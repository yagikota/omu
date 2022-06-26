// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include<stdlib.h>

void print_fib(int n) {
	int a = 0;
	int b = 1;
	int tmp;
	int i = 0;
	while (i <= n) {
		printf("F_%d = %d\n", i, a);
		tmp = a + b;
		a = b;
		b = tmp;
		i++;
	}
}

int main(int argc, char **argv) {
	int n = atoi(argv[1]);
	print_fib(n);

	return 0;
}