#load stack pointer
addi $sp, $0, 0xFFFC
#push multiplicand, multiplier on stack
addi $1, $0, 5
push $1

addi $2, $0, 4
push $2

#initialize reg 3 to zero
addi $3, $3, 0
push $3

j MULT

MULT:
#pop all values
pop $3
pop $2
pop $1
#break if the second is 0
beq $2, $0, DONE
#subtract from counter
addi $2, $2, -1
#add multiplicand to accumulator
add $3, $3, $1
push $1
push $2
push $3
j MULT

DONE:
halt
