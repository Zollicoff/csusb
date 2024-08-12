.ORIG x3000       ; Start address of the user program

LEA R7, LOOP      ; Load the address of LOOP into R7

LOOP:
    LDI R0, ENABLE ; Load the value from the address stored in ENABLE into R0
    LD R1, NEG_OFF ; Load the value at NEG_OFF into R1
    ADD R0, R0, R1 ; Add the values in R0 and R1
    BRnp BLINK     ; Branch to BLINK if the result is negative or positive
    AND R0, R0, #0 ; Clear R0
    STI R0, LIGHT  ; Store the value in R0 into the address stored in LIGHT
    RET            ; Return from subroutine

BLINK:
    ST R7, SAVE_R7 ; Save the value of R7
    LDI R0, LIGHT  ; Load the value from the address stored in LIGHT into R0
    ADD R0, R0, #1 ; Add 1 to R0
    AND R0, R0, #1 ; AND R0 with 1 to toggle between 0 and 1
    STI R0, LIGHT  ; Store the value in R0 into the address stored in LIGHT
    JSR DELAY      ; Jump to subroutine DELAY
    LD R7, SAVE_R7 ; Load the saved value of R7
    RET            ; Return from subroutine

LIGHT .FILL xFE08  ; Address of the LIGHT device register
ENABLE .FILL x4000 ; Address of the ENABLE register
NEG_OFF .FILL x-30 ; Value for checking if the switch is on
SAVE_R7 .BLKW #1   ; Reserve one word for saving R7

.END

; Interrupt Vector
.ORIG x0180
.FILL x1500       ; Address of the keyboard interrupt routine
.END

; Keyboard Interrupt Routine
.ORIG x1500       ; Start address of the keyboard interrupt routine

    ADD R6, R6, #-1 ; Decrement R6
    STR R0, R6, #0  ; Save R0 on the stack
    ADD R6, R6, #-1 ; Decrement R6
    STR R7, R6, #0  ; Save R7 on the stack

    TRAP x20        ; Get the keyboard input
    STI R0, ENABLE2 ; Store the keyboard input in ENABLE2
    RTI             ; Return from interrupt

ENABLE2 .FILL x4000 ; Address of the ENABLE2 register
.END

; DELAY Subroutine
.ORIG x5000        ; Start address of the DELAY subroutine

DELAY:
    LD R1, DELAY_COUNT
DELAY_LOOP:
    ADD R1, R1, #-1
    BRp DELAY_LOOP
    RET

DELAY_COUNT .FILL x7FFF ; Large value for delay loop

.END
