	.data
num:	.space 4

	.text
	.global main
main:
	li	$v0, 5		# read_int�V�X�e���R�[���̔ԍ�
	syscall
	
	la	$t0, num	# la�͋^������
	sw	$v0, 0($t0)
	
	li	$v0, 10		# �����܂ŃX�e�b�v���s�ior �u���[�N�|�C���g��ݒ肵��Run�j����$v0�̓��e���`�F�b�N����
	syscall
