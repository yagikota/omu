// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include<stdlib.h>

void calc_sum (double x, double y, double *sum) {
	*sum = x + y;
}

void calc_diff (double x, double y, double *diff) {
	*diff = x - y;
}

void calc_prod (double x, double y, double *prod) {
	*prod = x * y;
}

void calc_quot (double x, double y, double *quot) {
	*quot = x / y;
}

int main(int argc, char **argv) {
	double a = atof(argv[1]);
	double b = atof(argv[2]);
	double sum = 0;
	double diff = 0; 
	double prod = 0; 
	double quot = 0;

	calc_sum(a, b, &sum);
	calc_diff(a, b,&diff);
	calc_prod(a, b, &prod);
	calc_quot(a, b, &quot);

	printf("summation = %f\n", sum);
	printf("difference = %f\n", diff);
	printf("product = %f\n", prod);
	printf("quotient = %f\n", quot);

	return 0;
}