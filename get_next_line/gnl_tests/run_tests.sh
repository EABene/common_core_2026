#!/bin/bash
# Automatischer Test fuer get_next_line (wird NICHT abgegeben)
#
# Aufruf aus dem Projektordner (dort, wo get_next_line.c liegt):
#   bash gnl_tests/run_tests.sh
#
# Was getestet wird:
#   1. Kompiliert mit -Wall -Wextra -Werror, mit UND ohne -D BUFFER_SIZE
#   2. Fuer jede BUFFER_SIZE und jede Testdatei:
#      Alle Zeilen hintereinander ausgegeben muessen exakt der Originaldatei
#      entsprechen (Datei und stdin)
#   3. Ungueltige fds liefern NULL
#   4. Speicherfehler via -fsanitize=address
#      Leaks: auf Linux automatisch (ASan), auf macOS nur mit valgrind am Campus

cd "$(dirname "$0")/.." || exit 1

SRC="get_next_line.c get_next_line_utils.c gnl_tests/main.c"
FLAGS="-Wall -Wextra -Werror -g -I ."
FILES=gnl_tests/files/*.txt
SIZES="1 2 3 5 41 42 43 100 9999 10000000"
BIN=gnl_tests/gnl_test
OUT=gnl_tests/.out

GREEN="\033[32m"; RED="\033[31m"; RESET="\033[0m"
pass=0; fail=0

ok()   { printf "${GREEN}OK${RESET}   %s\n" "$1"; pass=$((pass+1)); }
ko()   { printf "${RED}KO${RESET}   %s\n" "$1"; fail=$((fail+1)); }

# Fuehrt einen Befehl mit Zeitlimit aus (macOS hat kein "timeout").
# Exit-Code 124 = Zeitlimit ueberschritten (Endlosschleife?)
LIMIT=${LIMIT:-10}
limited() {
	"$@" <&0 &
	local pid=$!
	( sleep $LIMIT; kill -9 $pid 2>/dev/null ) &
	local watcher=$!
	wait $pid 2>/dev/null
	local status=$?
	if kill -0 $watcher 2>/dev/null; then
		kill $watcher 2>/dev/null; wait $watcher 2>/dev/null
		return $status
	fi
	return 124
}

# ASan nur, wenn der Compiler es kann
SAN="-fsanitize=address"
echo 'int main(void){return 0;}' > /tmp/gnl_san_probe.c
cc $SAN /tmp/gnl_san_probe.c -o /tmp/gnl_san_probe 2>/dev/null || SAN=""
rm -f /tmp/gnl_san_probe /tmp/gnl_san_probe.c

echo "=== Kompilieren ohne -D BUFFER_SIZE"
if cc $FLAGS $SRC -o $BIN 2>$OUT.err; then ok "kompiliert ohne BUFFER_SIZE"
else ko "kompiliert NICHT ohne BUFFER_SIZE"; cat $OUT.err; fi

for bs in $SIZES; do
	echo
	echo "=== BUFFER_SIZE=$bs"
	if ! cc $FLAGS $SAN -D BUFFER_SIZE=$bs $SRC -o $BIN 2>$OUT.err; then
		ko "Kompilierfehler"; cat $OUT.err; continue
	fi
	for f in $FILES; do
		name=$(basename "$f")
		limited ./$BIN --raw "$f" > $OUT 2>$OUT.err
		status=$?
		if [ $status -eq 124 ]; then
			ko "$name (Zeitlimit ${LIMIT}s, Endlosschleife?)"
		elif [ $status -ne 0 ] || [ -s $OUT.err ]; then
			ko "$name (Absturz oder Sanitizer-Meldung)"; head -20 $OUT.err
		elif cmp -s "$f" $OUT; then ok "$name"
		else ko "$name (Ausgabe weicht ab)"; fi
	done
	limited ./$BIN --raw < gnl_tests/files/06_multi_no_newline_end.txt > $OUT 2>$OUT.err
	if cmp -s gnl_tests/files/06_multi_no_newline_end.txt $OUT && [ ! -s $OUT.err ]; then
		ok "stdin (Umleitung)"
	else ko "stdin (Umleitung)"; fi
	cat gnl_tests/files/11_many_lines.txt | limited ./$BIN --raw > $OUT 2>$OUT.err
	if cmp -s gnl_tests/files/11_many_lines.txt $OUT && [ ! -s $OUT.err ]; then
		ok "stdin (Pipe)"
	else ko "stdin (Pipe)"; fi
	if limited ./$BIN --badfd > $OUT 2>$OUT.err; then ok "ungueltige fds -> NULL"
	else ko "ungueltige fds"; cat $OUT; fi
done

# Leak-Check mit valgrind, falls vorhanden (z. B. am Campus)
if command -v valgrind > /dev/null; then
	echo
	echo "=== valgrind (BUFFER_SIZE=1 und 42)"
	for bs in 1 42; do
		cc $FLAGS -D BUFFER_SIZE=$bs $SRC -o $BIN
		for f in $FILES; do
			name=$(basename "$f")
			if limited valgrind -q --leak-check=full --error-exitcode=42 \
				./$BIN --raw "$f" > /dev/null 2>$OUT.err; then
				ok "valgrind BS=$bs $name"
			else ko "valgrind BS=$bs $name"; head -20 $OUT.err; fi
		done
	done
else
	echo
	echo "(valgrind nicht gefunden: Leak-Check bitte am Campus wiederholen)"
fi

rm -f $OUT $OUT.err $BIN
rm -rf $BIN.dSYM
echo
printf "Ergebnis: ${GREEN}%d OK${RESET}, ${RED}%d KO${RESET}\n" $pass $fail
[ $fail -eq 0 ]
