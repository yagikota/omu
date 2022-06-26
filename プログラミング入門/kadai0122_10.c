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
	int n, m;
	int ans;
	puts("Please type in 2 integers.");
	printf("n = "); scanf("%d", &n);
	printf("m = "); scanf("%d", &m);

	ans = nth_factorial(n) / nth_factorial(m) / nth_factorial(n - m);

	printf("n!/m!(n-m)! = %d\n", ans);

	return 0;
}