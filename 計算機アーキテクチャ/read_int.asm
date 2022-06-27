	.data
num:	.space 4

	.text
	.global main
main:
	li	$v0, 5		# read_intシステムコールの番号
	syscall
	
	la	$t0, num	# laは疑似命令
	sw	$v0, 0($t0)
	
	li	$v0, 10		# ここまでステップ実行（or ブレークポイントを設定してRun）して$v0の内容をチェックする
	syscall
