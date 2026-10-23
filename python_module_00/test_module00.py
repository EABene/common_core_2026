#!/usr/bin/env python3
"""
Tester für Python Module 00 – "Growing Code".

Aufruf (aus dem Repo-Root, in dem ex0/ ... ex7/ liegen):
    python3 test_module00.py              # alle Übungen
    python3 test_module00.py 2 6          # nur ex2 und ex6
    python3 test_module00.py -p ~/repo    # anderes Verzeichnis

Liegen die Dateien flach (ohne exN/-Ordner) im Verzeichnis, findet der
Tester sie auch dort.

Was geprüft wird:
  1. Struktur  – nur Funktionen im File, kein Code auf Top-Level,
                 kein if __name__ == "__main__", Funktionsname stimmt
  2. Erlaubt   – nur die im Subject erlaubten Built-ins werden aufgerufen
  3. Output    – exakter Vergleich inkl. Prompt-Texten von input()
  4. flake8 / mypy (falls installiert)
"""

import argparse
import ast
import builtins
import importlib.util
import io
import shutil
import subprocess
import sys
from contextlib import redirect_stdout
from pathlib import Path

GREEN = "\033[32m"
RED = "\033[31m"
YELLOW = "\033[33m"
BOLD = "\033[1m"
DIM = "\033[2m"
RESET = "\033[0m"

if not sys.stdout.isatty():
    GREEN = RED = YELLOW = BOLD = DIM = RESET = ""


# --------------------------------------------------------------------------
# Testfälle
# Jeder Fall: (Eingaben, Argumente, erwarteter Output als Liste von Zeilen)
# Bei input() erscheint im Output "Prompt + Eingabe" in einer Zeile –
# genau wie im Terminal.
# --------------------------------------------------------------------------

def _count(n):
    return ([f"Days until harvest: {n}"]
            + [f"Day {i}" for i in range(1, n + 1)]
            + ["Harvest time!"])


EXERCISES = {
    0: {
        "file": "ft_hello_garden.py",
        "funcs": ["ft_hello_garden"],
        "allowed": {"print"},
        "cases": {
            "ft_hello_garden": [
                ([], (), ["Hello, Garden Community!"]),
            ],
        },
    },
    1: {
        "file": "ft_garden_name.py",
        "funcs": ["ft_garden_name"],
        "allowed": {"input", "print"},
        "cases": {
            "ft_garden_name": [
                (["Community Garden"], (), [
                    "Enter garden name: Community Garden",
                    "Garden: Community Garden",
                    "Status: Growing well!",
                ]),
                (["Krems"], (), [
                    "Enter garden name: Krems",
                    "Garden: Krems",
                    "Status: Growing well!",
                ]),
                ([""], (), [
                    "Enter garden name: ",
                    "Garden: ",
                    "Status: Growing well!",
                ]),
            ],
        },
    },
    2: {
        "file": "ft_plot_area.py",
        "funcs": ["ft_plot_area"],
        "allowed": {"input", "int", "print"},
        "cases": {
            "ft_plot_area": [
                (["5", "3"], (), [
                    "Enter length: 5", "Enter width: 3", "Plot area: 15"]),
                (["0", "7"], (), [
                    "Enter length: 0", "Enter width: 7", "Plot area: 0"]),
                (["120", "45"], (), [
                    "Enter length: 120", "Enter width: 45",
                    "Plot area: 5400"]),
            ],
        },
    },
    3: {
        "file": "ft_harvest_total.py",
        "funcs": ["ft_harvest_total"],
        "allowed": {"input", "int", "print"},
        "cases": {
            "ft_harvest_total": [
                (["5", "8", "3"], (), [
                    "Day 1 harvest: 5", "Day 2 harvest: 8",
                    "Day 3 harvest: 3", "Total harvest: 16"]),
                (["0", "0", "0"], (), [
                    "Day 1 harvest: 0", "Day 2 harvest: 0",
                    "Day 3 harvest: 0", "Total harvest: 0"]),
                (["100", "250", "1"], (), [
                    "Day 1 harvest: 100", "Day 2 harvest: 250",
                    "Day 3 harvest: 1", "Total harvest: 351"]),
            ],
        },
    },
    4: {
        "file": "ft_plant_age.py",
        "funcs": ["ft_plant_age"],
        "allowed": {"input", "int", "print"},
        "cases": {
            "ft_plant_age": [
                (["75"], (), ["Enter plant age in days: 75",
                              "Plant is ready to harvest!"]),
                (["45"], (), ["Enter plant age in days: 45",
                              "Plant needs more time to grow."]),
                # Grenze: "strictly more than 60"
                (["60"], (), ["Enter plant age in days: 60",
                              "Plant needs more time to grow."]),
                (["61"], (), ["Enter plant age in days: 61",
                              "Plant is ready to harvest!"]),
                (["0"], (), ["Enter plant age in days: 0",
                             "Plant needs more time to grow."]),
            ],
        },
    },
    5: {
        "file": "ft_water_reminder.py",
        "funcs": ["ft_water_reminder"],
        "allowed": {"input", "int", "print"},
        "cases": {
            "ft_water_reminder": [
                (["4"], (), ["Days since last watering: 4",
                             "Water the plants!"]),
                (["1"], (), ["Days since last watering: 1",
                             "Plants are fine"]),
                # Grenze: "more than 2 days"
                (["2"], (), ["Days since last watering: 2",
                             "Plants are fine"]),
                (["3"], (), ["Days since last watering: 3",
                             "Water the plants!"]),
                (["0"], (), ["Days since last watering: 0",
                             "Plants are fine"]),
            ],
        },
    },
    6: {
        "file": ["ft_count_harvest_iterative.py",
                 "ft_count_harvest_recursive.py"],
        "funcs": ["ft_count_harvest_iterative",
                  "ft_count_harvest_recursive"],
        "allowed": {"input", "int", "print", "range"},
        "cases": {
            name: [
                (["5"], (), _count(5)),
                (["1"], (), _count(1)),
                (["12"], (), _count(12)),
                (["300"], (), _count(300)),
            ]
            for name in ("ft_count_harvest_iterative",
                         "ft_count_harvest_recursive")
        },
    },
    7: {
        "file": "ft_seed_inventory.py",
        "funcs": ["ft_seed_inventory"],
        "allowed": {"print"},  # + String-Methoden (Attribute-Calls)
        "no_input": True,
        "cases": {
            "ft_seed_inventory": [
                ([], ("tomato", 15, "packets"),
                 ["Tomato seeds: 15 packets available"]),
                ([], ("carrot", 8, "grams"),
                 ["Carrot seeds: 8 grams total"]),
                ([], ("lettuce", 12, "area"),
                 ["Lettuce seeds: covers 12 square meters"]),
                ([], ("basil", 3, "boxes"), ["Unknown unit type"]),
                ([], ("onion", 0, "packets"),
                 ["Onion seeds: 0 packets available"]),
                ([], ("pea", 7, "Packets"), ["Unknown unit type"]),
            ],
        },
    },
}

EX7_SIGNATURE = (
    "def ft_seed_inventory(seed_type: str, quantity: int, unit: str)"
    " -> None:"
)


# --------------------------------------------------------------------------
# Hilfsfunktionen
# --------------------------------------------------------------------------

class Report:
    def __init__(self):
        self.ok = 0
        self.ko = 0
        self.warn = 0

    def good(self, msg):
        self.ok += 1
        print(f"  {GREEN}[OK]{RESET} {msg}")

    def bad(self, msg, detail=None):
        self.ko += 1
        print(f"  {RED}[KO]{RESET} {msg}")
        if detail:
            for line in detail:
                print(f"       {line}")

    def note(self, msg):
        self.warn += 1
        print(f"  {YELLOW}[!!]{RESET} {msg}")


def find_file(root, ex_num, filename):
    for candidate in (root / f"ex{ex_num}" / filename, root / filename):
        if candidate.is_file():
            return candidate
    return None


def check_structure(path, expected_funcs, rep):
    """Nur Funktionsdefinitionen auf Top-Level, Namen korrekt."""
    try:
        tree = ast.parse(path.read_text(), filename=str(path))
    except SyntaxError as e:
        rep.bad(f"Syntaxfehler: {e}")
        return None

    ok = True
    top_funcs = []
    for i, node in enumerate(tree.body):
        if isinstance(node, ast.FunctionDef):
            top_funcs.append(node.name)
        elif (i == 0 and isinstance(node, ast.Expr)
              and isinstance(node.value, ast.Constant)
              and isinstance(node.value.value, str)):
            continue  # Modul-Docstring ist ok
        elif isinstance(node, ast.If) and "__name__" in ast.dump(node.test):
            rep.bad(f"Zeile {node.lineno}: if __name__ == \"__main__\" "
                    "ist verboten")
            ok = False
        else:
            rep.bad(f"Zeile {node.lineno}: Code außerhalb einer Funktion "
                    f"({type(node).__name__})")
            ok = False

    for name in expected_funcs:
        if name not in top_funcs:
            rep.bad(f"Funktion '{name}' nicht gefunden "
                    f"(gefunden: {top_funcs or 'keine'})")
            ok = False
    extra = [f for f in top_funcs if f not in expected_funcs]
    if extra:
        rep.note(f"Zusätzliche Top-Level-Funktionen: {extra} "
                 "(Subject: 'only the requested function')")
    if ok:
        rep.good("Struktur: nur die verlangte(n) Funktion(en)")
    return tree


def check_allowed(tree, allowed, rep):
    """Alle Aufrufe von Built-ins müssen erlaubt sein."""
    own_funcs = {n.name for n in ast.walk(tree)
                 if isinstance(n, ast.FunctionDef)}
    forbidden = set()
    for node in ast.walk(tree):
        if isinstance(node, (ast.Import, ast.ImportFrom)):
            forbidden.add(f"import (Zeile {node.lineno})")
        if isinstance(node, ast.Call) and isinstance(node.func, ast.Name):
            name = node.func.id
            if name not in allowed and name not in own_funcs:
                forbidden.add(f"{name}() (Zeile {node.lineno})")
    if forbidden:
        rep.bad("Nicht erlaubte Aufrufe: " + ", ".join(sorted(forbidden)),
                [f"Erlaubt: {', '.join(sorted(allowed))}"])
    else:
        rep.good("Nur erlaubte Funktionen verwendet")


def check_recursion(tree, rep):
    """ex6 rekursiv: es muss eine Funktion geben, die sich selbst aufruft,
    und keine Schleifen."""
    recursive = False
    for func in ast.walk(tree):
        if not isinstance(func, ast.FunctionDef):
            continue
        for node in ast.walk(func):
            if (isinstance(node, ast.Call)
                    and isinstance(node.func, ast.Name)
                    and node.func.id == func.name):
                recursive = True
    loops = [n.lineno for n in ast.walk(tree)
             if isinstance(n, (ast.For, ast.While))]
    if not recursive:
        rep.bad("Keine Funktion ruft sich selbst auf – nicht rekursiv")
    elif loops:
        rep.bad(f"Rekursive Version enthält Schleifen (Zeile {loops})")
    else:
        rep.good("Ist tatsächlich rekursiv (keine Schleifen)")


def check_iterative(tree, rep):
    loops = [n for n in ast.walk(tree)
             if isinstance(n, (ast.For, ast.While))]
    if loops:
        rep.good("Iterative Version nutzt eine Schleife")
    else:
        rep.bad("Iterative Version enthält keine Schleife")


def check_signature(tree, rep):
    func = next((n for n in tree.body if isinstance(n, ast.FunctionDef)
                 and n.name == "ft_seed_inventory"), None)
    if func is None:
        return
    want = [("seed_type", "str"), ("quantity", "int"), ("unit", "str")]
    got = [(a.arg, ast.unparse(a.annotation) if a.annotation else None)
           for a in func.args.args]
    ret = ast.unparse(func.returns) if func.returns else None
    if got == want and ret == "None":
        rep.good("Signatur mit Type Hints exakt wie verlangt")
    else:
        rep.bad("Signatur weicht ab",
                [f"erwartet: {EX7_SIGNATURE}",
                 f"gefunden: {got} -> {ret}"])


def load_module(path):
    spec = importlib.util.spec_from_file_location(
        f"_t_{path.stem}", path)
    module = importlib.util.module_from_spec(spec)
    buf = io.StringIO()
    with redirect_stdout(buf):
        spec.loader.exec_module(module)
    return module, buf.getvalue()


class InputExhausted(Exception):
    pass


def run_case(func, inputs, args):
    """Führt func aus, simuliert input() und gibt das Transkript zurück."""
    feed = list(inputs)
    out = io.StringIO()
    calls = {"n": 0}

    def fake_input(prompt=""):
        calls["n"] += 1
        if not feed:
            raise InputExhausted(
                f"input() wurde öfter aufgerufen als erwartet "
                f"({calls['n']}x, Prompt: {prompt!r})")
        value = feed.pop(0)
        out.write(str(prompt) + value + "\n")  # wie Terminal-Echo
        return value

    real_input = builtins.input
    builtins.input = fake_input
    error = None
    try:
        with redirect_stdout(out):
            func(*args)
    except Exception as e:  # noqa: BLE001 – wir wollen alles abfangen
        error = f"{type(e).__name__}: {e}"
    finally:
        builtins.input = real_input
    leftover = len(feed)
    return out.getvalue(), error, leftover


def show_diff(expected, got_text):
    got = got_text.split("\n")
    if got and got[-1] == "":
        got.pop()
    lines = []
    width = max(len(expected), len(got))
    for i in range(width):
        e = expected[i] if i < len(expected) else "<keine Zeile>"
        g = got[i] if i < len(got) else "<keine Zeile>"
        mark = " " if e == g else ">"
        lines.append(f"{mark} erwartet: {e!r}")
        if e != g:
            lines.append(f"{mark} bekommen: {g!r}")
    if not got_text.endswith("\n") and got_text:
        lines.append("> (Output endet ohne Zeilenumbruch)")
    return lines


def run_tool(cmd, paths, label, rep):
    exe = shutil.which(cmd[0]) if cmd[0] != sys.executable else cmd[0]
    if exe is None:
        rep.note(f"{label} nicht installiert – übersprungen "
                 f"(pip3 install {label})")
        return
    try:
        res = subprocess.run(cmd + [str(p) for p in paths],
                             capture_output=True, text=True, timeout=120)
    except (OSError, subprocess.TimeoutExpired) as e:
        rep.note(f"{label} konnte nicht laufen: {e}")
        return
    output = (res.stdout + res.stderr).strip()
    if "No module named" in output:
        rep.note(f"{label} nicht installiert – übersprungen "
                 f"(pip3 install {label})")
    elif res.returncode == 0:
        rep.good(f"{label} sauber")
    else:
        rep.bad(f"{label} meldet Fehler", output.splitlines()[:20])


# --------------------------------------------------------------------------
# Hauptablauf
# --------------------------------------------------------------------------

def test_exercise(num, root, rep, found):
    ex = EXERCISES[num]
    files = ex["file"] if isinstance(ex["file"], list) else [ex["file"]]
    funcs = ex["funcs"]
    print(f"\n{BOLD}=== ex{num} ==={RESET}")

    for filename, funcname in zip(files, funcs):
        path = find_file(root, num, filename)
        if len(files) > 1:
            print(f" {DIM}-- {filename}{RESET}")
        if path is None:
            rep.bad(f"{filename} nicht gefunden "
                    f"(gesucht in ex{num}/ und im Root)")
            continue
        found.append(path)

        tree = check_structure(path, [funcname], rep)
        if tree is None:
            continue
        check_allowed(tree, ex["allowed"], rep)
        if funcname.endswith("_recursive"):
            check_recursion(tree, rep)
        if funcname.endswith("_iterative"):
            check_iterative(tree, rep)
        if num == 7:
            check_signature(tree, rep)

        try:
            module, import_out = load_module(path)
        except Exception as e:  # noqa: BLE001
            rep.bad(f"Import schlägt fehl: {type(e).__name__}: {e}")
            continue
        if import_out:
            rep.bad("Beim Import wird schon etwas ausgegeben "
                    "(Funktion wird im File aufgerufen?)",
                    [repr(import_out[:200])])
        func = getattr(module, funcname, None)
        if func is None:
            continue

        for inputs, args, expected in ex["cases"][funcname]:
            label = (f"{funcname}({', '.join(map(repr, args))})"
                     + (f" mit Eingabe {inputs}" if inputs else ""))
            got, error, leftover = run_case(func, inputs, args)
            exp_text = "\n".join(expected) + "\n"
            if error:
                rep.bad(label, [error] + show_diff(expected, got))
            elif got != exp_text:
                rep.bad(label, show_diff(expected, got))
            elif leftover:
                rep.bad(label, [f"input() wurde {leftover}x zu wenig "
                                "aufgerufen"])
            else:
                rep.good(label)


def main():
    parser = argparse.ArgumentParser(description="Tester für Python Module 00")
    parser.add_argument("exercises", nargs="*", type=int,
                        help="Nummern der Übungen (Default: alle)")
    parser.add_argument("-p", "--path", default=".",
                        help="Repo-Verzeichnis (Default: aktuelles)")
    parser.add_argument("--no-lint", action="store_true",
                        help="flake8/mypy überspringen")
    args = parser.parse_args()

    if sys.version_info < (3, 10):
        print(f"{YELLOW}Achtung: Python {sys.version.split()[0]} – das "
              f"Subject verlangt 3.10+{RESET}")

    root = Path(args.path).expanduser().resolve()
    selected = args.exercises or sorted(EXERCISES)
    rep = Report()
    found = []

    for num in selected:
        if num not in EXERCISES:
            print(f"{RED}Übung {num} gibt es nicht (0–7){RESET}")
            continue
        test_exercise(num, root, rep, found)

    if found and not args.no_lint:
        print(f"\n{BOLD}=== Linter ==={RESET}")
        run_tool([sys.executable, "-m", "flake8"], found, "flake8", rep)
        ex7 = [p for p in found if p.name == "ft_seed_inventory.py"]
        if ex7:
            run_tool([sys.executable, "-m", "mypy", "--strict"], ex7,
                     "mypy", rep)

    print(f"\n{BOLD}Ergebnis:{RESET} {GREEN}{rep.ok} OK{RESET}, "
          f"{RED}{rep.ko} KO{RESET}, {YELLOW}{rep.warn} Hinweise{RESET}")
    sys.exit(1 if rep.ko else 0)


if __name__ == "__main__":
    main()
