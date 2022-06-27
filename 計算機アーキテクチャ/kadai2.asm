.data
n:	.space 4
n_pls1:	.space 4
s:	.space 4

.text
.globl main	
main:
	# read a integer and store the integer on n
	li	$v0, 5
	syscall
	sw	$v0, n
	
	# calcurate n+1 and store it on n_pls1
	lw	$t0, n
	lw	$t1, n_pls1
	addi 	$t1, $t0, 1
	sw	$t1, n_pls1
	

	# multiply n and n + 1
	mult	$t0, $t1
	
	# devide n(n+1) by 2 and store the result on s
	mfhi	$t2
	mflo	$t1
	lw	$t3	s
	div	$t3, $t1, 2
	sw	$t3, s

	# load s and print_int(s)
	lw	$a0, s
	li	$v0, 1
	syscall
	
	
	# exit
	li	$v0, 10
	syscall
