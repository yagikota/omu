	.data
str:	.space 100		# 100バイトの読み込みバッファ
	
	.text
	.global main
main:
	la	$a0, str	# 読み込みバッファの先頭アドレス
	li	$a1, 100	# 読み込みバッファのサイズ（バイト数）
	li	$v0, 8		# read_stringシステムコールの番号
	syscall
	
	la	$a0, str	# 読み込みバッファの先頭アドレス
	li	$v0, 4		# print_stringシステムコールの番号
	syscall
		
	li	$v0, 10		# exitシステムコールの番号
	syscall
