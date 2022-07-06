.data
n:	.space 4
s:	.space 4

.text
.globl main	
main:
	add $a1, $zero, $zero
	add $s0, $zero, $zero
loop:
	slti	$t0, $s0, 100
	beq	$t0, $zero, exit
	andi	$t0, $s0, 1
	bne	$t0, $zero, next
	add	$s1, $s1, $s0
next:
	addi	$s0, $s0, 1
	j	loop
	
exit:
	# print_int(print s)
	move	$a0, $s1
	li	$v0, 1
	syscall
	# exit
	li	$v0, 10
	syscall
