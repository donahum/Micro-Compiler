#load stack pointer
addi $sp, $0, 0
#current day
addi $13, $0, 20
#current month
addi $14, $0, 8
#current year
addi $15, $0, 2018

j GET_MONTH_DAYS

GET_MONTH_DAYS:

#subtract one from current month
addi $14, $14, -1
push $14
addi $11, $11, 30
push $11
#initialize reg 16 (accumulator) to zero
addi $16, $16, 0
push $16

j MULT_COUNTDOWN

MULT_COUNTDOWN:
#pop accumulator
pop $16
#break if nothing left to mult from the stack
beq $sp, $0, DONE
#pop multiplicand and multiplier
pop $8
pop $9
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
#halt
#j MULT_COUNTDOWN_2

DONE:
#get acc val
add $12, $16, $0
#clear acc
add $16, $0, $0
#clear 10
add $10, $0, $0
add $10, $15, $0
#get year-2000
addi $10, $10, -2000
addi $11, $0, 365
push $11
push $10
push $16

j MULT_COUNTDOWN_v2

MULT_COUNTDOWN_v2:
#pop accumulator
pop $16
#break if nothing left to mult from the stack
beq $sp, $0, DONE_v2
#pop multiplicand and multiplier
pop $8
pop $9
j MULT_LOOP_v2

MULT_COUNTDOWN_2_v2:
#pop accumulator
pop $16
#break if nothing left to mult from the stack
beq $sp, $0, DONE_v2
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

j MULT_LOOP_v2

MULT_LOOP_v2:
#break if the multiplier is 0
beq $8, $0, MULT_DONE_v2
#add value to accumulator, subtract from mulitplier
add $16, $16, $9
addi $8, $8, -1
j MULT_LOOP_v2

MULT_DONE_v2:
push $16
j MULT_COUNTDOWN_2_v2

DONE_v2:
#get acc val
add $17, $16, $0
#clear acc
add $16, $0, $0
#add in days from years
add $16, $17, $0
#add in days from months
add $16, $12, $16
#add in from current day
add $16, $16, $13
halt
