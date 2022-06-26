// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>

int main(void) {
	int x = 6, y = 3;
	int temp;
	int *px ;
	int *py;

	printf("x = %d, y = %d\n", x, y);

	px = &x;
	py = &y;
	temp = *px;
	*px = *py;
	*py = temp;

	printf("x = %d, y = %d\n", x, y);
    
	return 0;
}