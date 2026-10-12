# Glossary of C terms.


Address.
    Reference to a memory location. In C pointers are used to hold addresses.

ANSI
    American

API
    Application Programming Interface

Argument.
    A value passed to a function (see parameter).

Base Class
    See C++ glossary.

Block.
    A sequence of definitions, declarations and statements, enclosed within braces {}.

Character Array.
    A set of elements of type char. (Can be used to store a string).

Class
    See C++ glossary.

Compilation error.
    Error which occurs during the translation of source code into machine code.

Compiler.
    A program which converts source code into machine code.

Compound Statement.
    A sequence of simple statements.

Constant (common all garden)
    An item that represents a value that cannot be changed. For Example:

       
            123
            'x'

Constant (symbolic)
    A symbol defined in a #define preprocessor directive to represent a constant value.

Data type.
    Definition of the data. int, char, float.

Declaration.
    A construct which associates attributes to a variable name or function.
    No storage is reserved.

    For example:

            extrn int  a;
            extrn char c;

    variable declaration

    A structure decleration could look like:

            struct per_rec
            {
                int   age;
                char *surname;
                char *firstname;
            };

Definition.

    Variable definition is a declaration with storage allocation.

            int a;
            char c;
            struct per_rec person;

    A construct which specifies the name,parameters and return type of a function.
    For example a function definition would be:

            long sqr(int num)
            {
                return(num*num);
            }

Derived Class
    See C++ glossary.

Encapsulation.
    The C++ concept of grouping related variables and controlling the operations performed apon them. The encapsulated variables can be considered to be contained in their own environment.

Escape sequence.
    Control codes comprising combinations of a backslash followed by letters or digits which represent non printing characters.

Executable program.
    Program which will run in the environment of the operating system or within an appropriate run time environment.

Executable (stand-alone) program.
    Program which will run within the environment of the operating system without additional utilities or support.

Expression.
    A sequence of operators and operands which may yield a single value.

File.
    Data stored as an electronic file.

File descriptor.
    This is used in low level I/O (open/read/write/close functions) to identify a file. It is an integer number assigned to a file name by open and then used as a unique identifier by read/write and close.

Floating-point Number.
    Number having a decimal place or exponent.

Format specification.
    A string which controls how input or output shall be presented.

Identifier.
    The names used to refer to stored data values such as constants, variables or functions. 
Integer.
    A number without a fractional part.

Keyword.
    A word which has a predefined meaning to a 'C' compiler and therefore must not be used for any other purpose.

library file.
    The file which contains compiled versions of commonly used functions which can be linked to an object file to make an executable program.

Library function.
    A function whose code is contained in the external library file. 
Line.
    One line of input from the standard input device (keyboard) which is terminated with a newline character. The newline character is replaced by a null character.

Literal.
    Characters, letters or strings which are to be taken literally and used as constants rather than identifiers.

Method.
    C++ talk meaning a member function of a class.

Object
    See C++ glossary.

Object Code.
    Code which is directly understandable by the machine (machine code).

Operand.
    An expression acted on by an operator. For example:

            z = a + b;

    a and b are both operands of the + operator. 
Parameter.
    A value received by a function.

Pointer.
    Variable containing an address.

Polymorphism
    See C++ glossary.

POSIX
    Portable Operating System Interface.

Precedence (of operators)
    The order in which operators are dealt with during the evaluation of an expression.

Preprocessor.
    A processor which manipulates the initial directives of the source file which contains instructions about how the source file shall be processed and compiled.

Preprocessor directive.
    Source file instruction about how the file shall be processed and compiled.

Program.
    A text file comprising code which can be compiled.

Run time error.
    An error which occurs when a program is executed.

Reserved word. (keyword)
    A word which has a predefined meaning to a 'C' compiler and therefore must not be used for any other purpose.

Scope.

Source code.
    A text file comprising code which can be compiled.

Statement.
    A simple statement is an expression followed by a semicolon. (See compound statement and block).

String.
    A string in 'C' is an array of characters terminated by a Null character ('\0').

SubClass
    See C++ glossary.

SuperClass
    See C++ glossary.

Syntax error.
    A mistake in the source code which prevents the compiler from converting it into object code.

Threads.
    A process has five fundamental parts: code ("text"), data (VM), stack, file I/O, and signal tables. Theads are spawned from a process and can share these parts to comunicate with each other.

    The traditional method of spawning processes (fork) could only communicate with other forked processes via pipes and and "shared memory". The result is threads can communicate easily and have a low CPU overhead.

Variable.
    An identifier (and storage) for a data type and for which the data value is allowed to change as the program runs.
