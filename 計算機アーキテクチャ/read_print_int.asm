	.text
	.global main
main:
	li	$v0, 5		# read_intシステムコールの番号
	syscall
	
	move	$a0, $v0	# moveは疑似命令
	li	$v0, 1		# print_intシステムコールの番号
	syscall
		
	li	$v0, 10		# exitシステムコールの番号
	syscall
