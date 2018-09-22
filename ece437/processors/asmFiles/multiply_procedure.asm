#load stack pointer
addi $sp, $0, 0
#push all multipliers on the stack
addi $8, $0, 5
push $8

addi $9, $0, 4
push $9

addi $10, $0, 3
push $10

addi $11, $0, 2
push $11

#initialize reg 16 (accumulator) to one
addi $16, $16, 0
push $16

addi $12, $12, 0

j MULT_COUNTDOWN

MULT_COUNTDOWN:
#pop accumulator
pop $16
#break if nothing left to mult from the stack
beq $sp, $0, DONE
#pop multiplicand and multiplier
pop $9
pop $8
j MULT_LOOP

MULT_COUNTDOWN_2:
#pop accumulator
pop $16
#break if nothing left to mult from the stack
beq $sp, $0, DONE
#reinitialize regs 9 and 10 to 0
add $9, $0, $0
#load accumulator to reg
add $9, $16, $0
#clear accumulator
add $16, $0, $0
#pop new multiplier
pop $8
#break for register check
#beq $12, $13, MULT_CHECK
#addi $13, $13, 1

j MULT_LOOP

MULT_LOOP:
#break if the multiplier is 0
beq $8, $0, MULT_DONE
#add value to accumulator, subtract from mulitplier
add $16, $16, $9
addi $8, $8, -1
j MULT_LOOP

MULT_DONE:
push $16
j MULT_COUNTDOWN_2

#MULT_CHECK:
#alt
#j MULT_COUNTDOWN_2

DONE:
halt
push $16
