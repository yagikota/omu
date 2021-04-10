// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>

int main(void) {
	float sum = 0;
	int i;

	for (i = 1; i <= 10; i++)
		sum = i * (i + 1) * (i + 2) / 6;

	printf("sum = %f", sum);

	return 0;
}