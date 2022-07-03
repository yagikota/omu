.data
str: .space 16

.text
main:
	# read_string
	li $v0, 8
	li $a1, 16
	la $a0, str
	syscall

# convert case
loop:
	# load byte
	lb	$t1, str($t0)
	# break loop if string is blank
 	beq	$t1, 0, exit

	# check a letter using ASCII Code
	# ~ @
	blt	$t1, 'A', not_change_case
	# A ~ Z
	blt 	$t1, '[', to_lower_case
 	# [ ~ `
 	blt	$t1, 'a', not_change_case
 	# a ~ z
	blt 	$t1, '{', to_upper_case
	# { ~
	bgt	$t1, 'z', not_change_case

not_change_case: 
	addi $t0, $t0, 1
	j loop
to_upper_case:
	sub 	$t1, $t1, 32
	sb 	$t1, str($t0)
	addi	$t0, $t0, 1
	j loop	
to_lower_case:
	add 	$t1, $t1, 32
	sb	$t1, str($t0)
	addi	$t0, $t0, 1
	j loop
exit:
	# print_string
	li	$v0, 4
	la	$a0, str
	syscall

	# exit
	li	$v0, 10
	syscall
