	.data
str:	.space 100		# 100�o�C�g�̓ǂݍ��݃o�b�t�@
	
	.text
	.global main
main:
	la	$a0, str	# �ǂݍ��݃o�b�t�@�̐擪�A�h���X
	li	$a1, 100	# �ǂݍ��݃o�b�t�@�̃T�C�Y�i�o�C�g���j
	li	$v0, 8		# read_string�V�X�e���R�[���̔ԍ�
	syscall
	
	la	$a0, str	# �ǂݍ��݃o�b�t�@�̐擪�A�h���X
	li	$v0, 4		# print_string�V�X�e���R�[���̔ԍ�
	syscall
		
	li	$v0, 10		# exit�V�X�e���R�[���̔ԍ�
	syscall
