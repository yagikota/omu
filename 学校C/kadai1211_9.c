// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>

int main(void) {
	int x = 7;
	int y = 3;
	int *px;
	int *py;
	int remainder;

	px = &x;
	py = &y;

	remainder = *px % *py;

	printf("remainder : %d\n", remainder);

	return 0;
}