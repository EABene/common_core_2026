
list im main ist die Liste. Es gibt nichts anderes, was "die Liste" ist, 
nur diesen einen Zeiger auf den ersten Knoten.
&list übergibt die Variable selbst, damit eine Funktion sie ändern kann.

t_list *lst als Parameter: Die Funktion bekommt eine Kopie des Zeigers.
Sie kann die Knoten verändern, aber nicht, wo die Liste im main beginnt.

t_list **lst als Parameter: Die Funktion kann über *lst = ... auch den 
Anfang der Liste im main umbiegen.

-> heißt immer: einem Zeiger auf einen Knoten folgen und ein Feld daraus 
nehmen. Links vom Pfeil muss also immer ein t_list * stehen, nie ein 
t_list **.
