// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include <stdlib.h> 
#include <time.h>

int main(void) {
	int i;
	int num;
	int sum = 0;
	float avg;

	srand((unsigned)time(NULL));
	puts("--random numbers--");

	for (i = 0; i < 5; i++) {
		num = rand() % 100 + 1;
		sum += num;
		printf("%d\n", num);
	}

	avg = (float)sum / 5;

	printf("AVERAGE : %.1f\n", avg);

	return 0;
}