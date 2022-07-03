.data
n:	.space 4
s:	.space 4

.text
.globl main	
main:
	# read a integer and store the integer on n
	li	$v0, 5
	syscall
	sw	$v0, n
	
	
	lw	$t0, n
	lw	$t1, s
	addi	$t0, $t0, 1
loop:
	slt	$t2, $s0, $t0 # 
	beq	$t2, $zero, exit
	add	$t1, $t1, $s0
	addi	$s0, $s0, 1
	j	loop
	
exit:
	# print_int(print s)
	move	$a0, $t1
	li	$v0, 1
	syscall
	# exit
	li	$v0, 10
	syscall
