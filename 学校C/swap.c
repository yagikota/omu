// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include<stdlib.h>

void swap(double *x, double *y) {
	double temp = *x;
	*x = *y;
	*y = temp;
}

int main(int argc, char **argv) {
	double a = atof(argv[1]);
	double b = atof(argv[2]);

	puts("Input values:");
	printf("%d and %d\n", (int)a, (int)b);

	swap(&a, &b);

	puts("After swapping process, input values are exchanged:");
	printf("%d and %d\n", (int)a, (int)b);

	return 0;
}