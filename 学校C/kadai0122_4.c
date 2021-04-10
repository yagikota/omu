// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define MAX 21


int main(void) {
	int count = 1;
	while (1) {
		srand((unsigned int)time(NULL));
		rand();
		int a = rand() % 13 + 1;
		int b = rand() % 13 + 1;
		int s = a + b;
		printf("1st: %d  2nd: %d  Sum: %d\n", a, b, s);

		if (s >= MAX) {
			if (count == 1) {
				printf("Total: 1 time trial!\n");
			} else {
				printf("Total: %d times trial!\n", count);
			}
			break;
		}
		count ++;
		sleep(1);
	}
	return 0;
}