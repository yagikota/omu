// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>

int nth_factorial(int n) {
	if (n == 1)
		return 1;
	else
		return n * nth_factorial(n - 1);
}

int main(void) {
	int i;
	for(i = 1; i <= 10; i++) {
		printf("%d! = %d\n", i, nth_factorial(i));
	}

	return 0;
}