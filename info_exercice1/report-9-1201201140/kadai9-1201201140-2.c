// 1201201140
// 八木洸太

#include <stdio.h>
#include <math.h>
#include "kadai9-1201201140-2.h"

extern int N;

double dot(double *a, double *b) {
	double inner_prod= 0.0;
	for (int i = 0; i < N; i++) {
		inner_prod += a[i] * b[i];
	}
	return inner_prod;
}

double norm(double *a) {
	return sqrt(dot(a, a));
}

void unit_vector(double *a, double *b) {
	double n = norm(a);
	for (int i = 0; i < N; i++) {
		b[i] = a[i] / n;
	}
}

double cos_sim(double *a, double *b) {
	double inner_prod = dot(a, b);
	double norm_a = norm(a);
	double norm_b = norm(b);
	return inner_prod / (norm_a * norm_b);
}