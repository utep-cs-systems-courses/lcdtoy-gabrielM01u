	.arch msp430g2553
    .file "msp430.h"
	.file "stateMachine.h"
    .file "states.h"
    .file "hardware.h"
    .p2align 1,0

    
redraw: .byte 0

;;state machine
    .text
jt: .word default
    .word case_1
    .word case_2
    .word case_3
    .word case_4

    .text
    .global state_machine
state_machine:

    cmp #4, r12
    jc default
    add r12, r12
    mov jt(r12), r0

case_1:
    call #state_1
    mov #0, &switch_state_changed
    jmp exit

case_2:
    call #state_2
    call #enable_green
    mov #0, &switch_state_changed
    jmp exit

case_3:
    call #state_3
    mov #0, &switch_state_changed
    jmp exit

case_4:
    call #state_4
    mov #0, &switch_state_changed
    jmp exit

default:
    jmp exit

exit:
    ret

    