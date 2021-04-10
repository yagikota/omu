// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include <stdlib.h> 
#include <time.h>

int main(void) {
	double a, x, y, d;
	srand((unsigned)time(NULL));
	a = rand();// 初期値の影響の強さを避ける
	x = (double)rand() / RAND_MAX;
	y = (double)rand() / RAND_MAX;
	d = x * x + y * y;

	if (d <= 1) {
		printf("The point (%lf, %lf) is in the sector\n", x, y);
	}

	else
		printf("The point (%lf, %lf) is outside of the sector\n", x, y);
	return 0;
}

