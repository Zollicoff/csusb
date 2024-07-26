 ; Name: Zachary A. Hampton
 ; Student ID: 008339494
 ; Assignment: Lab 01 - Run 2
 ; Date: July 26, 2024

        .ORIG x3000         ; Starting address of the program

        LEA R2, xFF         ; Load effective address to R2 (x30FF)

        ; Load (Read) X and Y values
        LDR R1, R2, x0      ; Load X into R1 from memory location x3100
        LDR R3, R2, x1      ; Load Y into R3 from memory location x3101

        ; X + Y
        ADD R4, R1, R3      ; R4 <- R1 + R3
        STR R4, R2, x2      ; Store the result at x3102

        ; X AND Y
        AND R4, R1, R3      ; R4 = R1 AND R3
        STR R4, R2, x3      ; Store the result at x3103

        ; X OR Y
        NOT R5, R1          ; R5 = NOT(R1)
        NOT R6, R3          ; R6 = NOT(R3)
        AND R4, R5, R6      ; R4 = R5 AND R6
        NOT R4, R4          ; R4 = NOT(R4) (X OR Y)
        STR R4, R2, x4      ; Store the result at x3104

        ; NOT(X)
        NOT R4, R1          ; R4 = NOT(R1)
        STR R4, R2, x5      ; Store the result at x3105

        ; NOT(Y)
        NOT R4, R3          ; R4 = NOT(R3)
        STR R4, R2, x6      ; Store the result at x3106

        ; X + 3
        ADD R4, R1, #3      ; R4 = R1 + 3
        STR R4, R2, x7      ; Store the result at x3107

        ; Y - 3
        ADD R4, R3, #-3     ; R4 = R3 - 3
        STR R4, R2, x8      ; Store the result at x3108

        ; Determine if X is even or odd
        AND R4, R1, #1      ; R4 = R1 AND 1
        STR R4, R2, x9      ; Store the result at x3109

        HALT

        .END

        .ORIG x3100
        
X       .FILL #-11           ; X = 10
Y       .FILL #15           ; Y = 20
        .FILL #0            ; Space for X + Y result at x3102
        .FILL #0            ; Space for X AND Y result at x3103
        .FILL #0            ; Space for X OR Y result at x3104
        .FILL #0            ; Space for NOT(X) result at x3105
        .FILL #0            ; Space for NOT(Y) result at x3106
        .FILL #0            ; Space for X + 3 result at x3107
        .FILL #0            ; Space for Y - 3 result at x3108
        .FILL #0            ; Space for X even/odd result at x3109

        .END
