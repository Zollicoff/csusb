.ORIG x3000

; Main program
MAIN    LEA R0, PROMPT1     ; Load prompt for binary input
        PUTS                ; Print prompt
        JSR READ_BIN        ; Read binary number
        JSR BIN_TO_DEC      ; Convert to decimal
        LEA R0, RESULT1     ; Load result string
        PUTS                ; Print result string
        LD R0, DEC_RESULT   ; Load decimal result
        JSR PRINT_DEC       ; Print decimal number
        
        LEA R0, PROMPT2     ; Load prompt for decimal input
        PUTS                ; Print prompt
        JSR READ_DEC        ; Read decimal number
        JSR DEC_TO_BIN      ; Convert to binary
        LEA R0, RESULT2     ; Load result string
        PUTS                ; Print result string
        JSR PRINT_BIN       ; Print binary number
        HALT                ; End program

; Binary to Decimal conversion
BIN_TO_DEC
        AND R1, R1, #0      ; Clear R1 (result)
        AND R2, R2, #0      ; Clear R2 (counter)
        ADD R2, R2, #16     ; Set counter to 16 (assuming 16-bit number)
LOOP_BTD
        ADD R1, R1, R1      ; Left shift R1
        ADD R0, R0, #0      ; Check MSB of R0
        BRzp SKIP_ADD       ; If 0, skip addition
        ADD R1, R1, #1      ; If 1, add 1 to result
SKIP_ADD
        ADD R0, R0, R0      ; Left shift R0
        ADD R2, R2, #-1     ; Decrement counter
        BRp LOOP_BTD        ; Loop if counter > 0
        ST R1, DEC_RESULT   ; Store result
        RET

; Decimal to Binary conversion
DEC_TO_BIN
        LD R0, DEC_INPUT    ; Load decimal input
        AND R1, R1, #0      ; Clear R1 (result)
        AND R2, R2, #0      ; Clear R2 (counter)
        ADD R2, R2, #16     ; Set counter to 16
LOOP_DTB
        ADD R1, R1, R1      ; Left shift R1
        ADD R0, R0, #0      ; Check if R0 is negative
        BRzp SKIP_SET       ; If positive or zero, skip setting bit
        ADD R1, R1, #1      ; If negative, set least significant bit
SKIP_SET
        ADD R0, R0, R0      ; Left shift R0
        ADD R2, R2, #-1     ; Decrement counter
        BRp LOOP_DTB        ; Loop if counter > 0
        ST R1, BIN_RESULT   ; Store result
        RET

; Subroutines for input/output omitted for brevity
; (READ_BIN, READ_DEC, PRINT_BIN, PRINT_DEC)

; Data
PROMPT1 .STRINGZ "Enter binary number: "
PROMPT2 .STRINGZ "Enter decimal number: "
RESULT1 .STRINGZ "Decimal equivalent: "
RESULT2 .STRINGZ "Binary equivalent: "
DEC_RESULT .BLKW 1
DEC_INPUT .BLKW 1
BIN_RESULT .BLKW 1

.END
