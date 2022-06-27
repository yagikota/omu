	.data			# �f�[�^��data�Z�O�����g�ɔz�u����
	# ������data�Z�O�����g�̎n�܂�
x:	.word	123		# int x = 123; �Ɠ���
y:	.word	456		# int y = 456; �Ɠ���
z:	.space	4		# int z; �Ɠ����i'4'�͊m�ۂ���o�C�g���j
	# ������data�Z�O�����g�̏I���
	
	.text			# ���߂�text�Z�O�����g�ɔz�u����
	# ������text�Z�O�����g�̎n�܂�
	.global main		# ���x��main�𑼂̃t�@�C������Q�Ɖ\�ɂ���
main:
	lw	$t1, x
	lw	$t2, y
	add	$t3, $t1, $t2
	sw	$t3, z
	
	# �v���O�����̍Ō��exit�V�X�e���R�[���Ăяo���ŏI���
	li	$v0, 10		# exit�V�X�e���R�[���̔ԍ����^������li��$v0�ɑ������
	syscall
	# ������text�Z�O�����g�̏I���
