.data
x:	.space 4
y:	.space 4
z:	.space 4

.text
.globl main	
main:
	# read the first integer(x) and store the integer on x
	li	$v0, 5
	syscall
	sw	$v0, x
	
	# read the second integer(y) and store the integer on y
	li	$v0, 5
	syscall
	sw	$v0, y
	
	# calculate x + y and and store the result on z
	lw	$t0, x
	lw	$t1, y
	add	$t2, $t0, $t1
	sw	$t2, z
	
	# load z and print_int(print z)
	lw	$a0, z
	li	$v0, 1
	syscall
	
	# exit
	li	$v0, 10
	syscall
