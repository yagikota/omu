	.text
	.global main
main:
	li	$v0, 5		# read_int�V�X�e���R�[���̔ԍ�
	syscall
	
	move	$a0, $v0	# move�͋^������
	li	$v0, 1		# print_int�V�X�e���R�[���̔ԍ�
	syscall
		
	li	$v0, 10		# exit�V�X�e���R�[���̔ԍ�
	syscall
