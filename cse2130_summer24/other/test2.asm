; Hello World in LC-3 Assembly

        .ORIG   x3000      ; Program start address

        LEA     R0, HELLO  ; Load the address of the string into R0
        PUTS                ; Print the string

        HALT                ; Halt the program

HELLO   .STRINGZ "Hello, World!" ; The string to be printed

        .END                ; End of the program
