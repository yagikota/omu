#include<stdio.h>

void wa(int x, int y, int *z) {
	*z = x + y;
}

int main (void) {
	int a = 3;
	int b = 4;
	int sum = 0;
	wa(a, b, &sum);

	printf("sum = %d\n", sum);

	return 0;
}