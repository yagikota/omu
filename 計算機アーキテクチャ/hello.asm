	.data
str:	.asciiz "Hello World"	# 末尾に'\0'が置かれる

	.text
	.global main
main:
	li	$v0, 4		# print_stringシステムコールの番号
	la	$a0, str
	syscall
	
	li	$v0, 10		# exitシステムコールの番号
	syscall
