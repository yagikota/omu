// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>

void nth_rtial(int n) {
	int i, c;
	double a, x, y, d, pi, p, e;
	srand((unsigned)time(NULL));
	a = rand();// 初期値の影響の強さを避ける
	pi = 3.141592;
	c = 0;

	for (i = 0; i < n; i++) {
		x = (double)rand() / RAND_MAX;
		y = (double)rand() / RAND_MAX;
		d = x * x + y * y;
		if(d <= 1)
			c += 1;
	}
	// 確率
	p = (double)c / i;
	// 誤差
	e = fabs(pi - p * 4);
	printf("%dth trial:\n", n);
	printf("The probability that plotted point are in the sector is %lf\n", p);
	printf("The quadruple of the probability is %lf\n", p * 4);
	printf("The difference between the quadruple and pi is %lf\n",e);
	putchar('\n');
}

int main(void) {
	nth_rtial(1000);
	nth_rtial(10000);
	nth_rtial(100000);
	
	return 0;
}