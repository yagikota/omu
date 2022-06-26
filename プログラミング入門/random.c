#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int a, i;

	for(i=0; i < 10; i++) {
		a = rand();
		printf("%d\n", a);
	}

	return 0;
}