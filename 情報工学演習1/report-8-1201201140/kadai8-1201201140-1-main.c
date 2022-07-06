// 1201201140
// 八木洸太
#include <stdio.h>
#include "kadai8-1201201140-1.h"



int main(void) {
	double x = 1.0;
	double y = 2.0;

	printf("%.1fと%.1fの四則演算の結果\n", x, y);

	printf("%.1f+%.1f=%.1f\n", x, y, plus(x, y));
	printf("%.1f-%.1f=%.1f\n", x, y, minus(x, y));
	printf("%.1f*%.1f=%.1f\n", x, y, multiply(x, y));
	printf("%.1f/%.1f=%.1f\n", x, y, divide(x, y));

	return 0;
}