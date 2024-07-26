 ; Name: Zachary A. Hampton
 ; Student ID: 008339494
 ; Assignment: Lab 02 - Run 3
 ; Date: July 26, 2024

            .ORIG x3000             ; Program start

            ; Load X and Y
            LDI R1, ADDR_X          ; Load X into R1
            LDI R2, ADDR_Y          ; Load Y into R2

            ; Compute X - Y
            NOT R3, R2              ; R3 = NOT(Y)
            ADD R3, R3, #1          ; R3 = -Y (2's complement)
            ADD R4, R1, R3          ; R4 = X - Y
            STI R4, ADDR_DIFF       ; Store (X - Y) at x3122

            ; Compute |X|
            ADD R5, R1, #0          ; R5 ← R1, can now use condition codes
            BRzp POS_X              ; If zero or positive, do not negate
            NOT R5, R5
            ADD R5, R5, #1          ; R5 = -R1
POS_X       STI R5, ADDR_ABS_X      ; Store |X| at x3123

            ; Compute |Y|
            ADD R5, R2, #0          ; R5 ← R2, can now use condition codes
            BRzp POS_Y              ; If zero or positive, do not negate
            NOT R5, R5
            ADD R5, R5, #1          ; R5 = -R2
POS_Y       STI R5, ADDR_ABS_Y      ; Store |Y| at x3124

            ; Compare |X| and |Y|
            LDI R1, ADDR_ABS_X      ; Load |X| into R1
            LDI R2, ADDR_ABS_Y      ; Load |Y| into R2
            NOT R3, R2              ; R3 = NOT(|Y|)
            ADD R3, R3, #1          ; R3 = -|Y|
            ADD R4, R1, R3          ; R4 = |X| - |Y|
            BRzp X_GREATER          ; If |X| > |Y|, branch
            BRz Y_EQUAL             ; If |X| == |Y|, branch
            LD R0, VALUE_2          ; R0 = 2 (|Y| is larger)
            BR COMP_DONE
X_GREATER   LD R0, VALUE_1          ; R0 = 1 (|X| is larger)
            BR COMP_DONE
Y_EQUAL     LD R0, VALUE_0          ; R0 = 0 (equal)
COMP_DONE   STI R0, ADDR_RESULT     ; Store result at x3125

            HALT

ADDR_X      .FILL x3120         ; Address of X
ADDR_Y      .FILL x3121         ; Address of Y
ADDR_DIFF   .FILL x3122         ; Address of (X - Y)
ADDR_ABS_X  .FILL x3123         ; Address of |X|
ADDR_ABS_Y  .FILL x3124         ; Address of |Y|
ADDR_RESULT .FILL x3125         ; Address of result

VALUE_1     .FILL #1            ; Value 1
VALUE_2     .FILL #2            ; Value 2
VALUE_0     .FILL #0            ; Value 0

            .END

            .ORIG x3120         ; Data section
            .FILL #11           ; X
            .FILL #-15          ; Y
            .FILL #0            ; Space for (X - Y)
            .FILL #0            ; Space for |X|
            .FILL #0            ; Space for |Y|
            .FILL #0            ; Space for comparison result

            .END
