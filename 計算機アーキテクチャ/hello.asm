	.data
str:	.asciiz "Hello World"	# ������'\0'���u�����

	.text
	.global main
main:
	li	$v0, 4		# print_string�V�X�e���R�[���̔ԍ�
	la	$a0, str
	syscall
	
	li	$v0, 10		# exit�V�X�e���R�[���̔ԍ�
	syscall
