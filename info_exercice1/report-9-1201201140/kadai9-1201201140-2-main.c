// 1201201140
// 八木洸太
#include <stdio.h>
#include <stdlib.h> 
#include "kadai9-1201201140-2.h"

int N = 3;

void print_vector(double *a) {
	printf("[");
	for (int i = 0; i < N; i++) {
		printf("%.1f,", a[i]);
	}
	printf("]\n");
}

void init_a(double *a) {
	a[0] = 1.0;
	a[1] = 2.0;
	a[2] = 2.0;
}

void init_b(double *b) {
	b[0] = 0.0;
	b[1] = 0.0;
	b[2] = 3.0;
}

int main(void) {

	double *a = (double *)malloc(sizeof(double) * N);
	init_a(a);
	double *unit_a = (double *)malloc(sizeof(double) * N);

	double *b = (double *)malloc(sizeof(double) * N);
	init_b(b);
	double *unit_b = (double *)malloc(sizeof(double) * N);


	unit_vector(a, unit_a);
	unit_vector(b, unit_b);

	printf("ベクトルa: ");
	print_vector(a);
	printf("ベクトルb: ");
	print_vector(b);

	printf("ベクトルaの長さ: %.2f\n", norm(a));
	printf("ベクトルbの長さ: %.2f\n", norm(b));
	printf("ベクトルaの単位ベクトル: ");
	print_vector(unit_a);
	printf("ベクトルbの単位ベクトル: ");
	print_vector(unit_b);

	printf("ベクトルaとbのコサイン類似度: %f\n", cos_sim(a, b));

	return 0;
}