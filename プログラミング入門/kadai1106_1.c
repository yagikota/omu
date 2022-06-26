// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>

int main(void) {
	int x1, x2, y;
	float w1, w2, theta, tmp;

	printf("Please type in 0 or 1 for x1\n");
	scanf("%d", &x1);
	printf("Please type in 0 or 1 for x2\n");
	scanf("%d", &x2);

//AND gate
	w1 = 0.5;
	w2 = 0.5;
	theta = 0.7;
	tmp = w1 * x1 + w2 * x2;

	if (tmp <= theta)
		y = 0;
	else
		y = 1;
	printf("In case of x1 = %d, x2 = %d, the output of AND gate is y = %d\n", x1, x2, y);

//OR gate
	w1 = 0.5;
	w2 = 0.5;
	theta = 0;
	tmp = w1 * x1 + w2 * x2;

	if (tmp <= theta)
		y = 0;
	else
		y = 1;
	printf("In case of x1 = %d, x2 = %d, the output of OR gate is y = %d\n", x1, x2, y);

	return 0;
}
