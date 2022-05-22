// 1201201140
// 八木洸太

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <math.h>


void print_times_table() {
	puts("九九の表");
	puts("  1  2  3  4  5  6  7  8  9");
	puts("----------------------------");
	for (int i = 1; i < 10; i++) {
		printf("%d|", i);
		for (int j = 1; j < 10; j++) {
			int mult = i * j;
			if (mult >= 10) {
			printf("%d ", mult);
			} else {
			printf("%d  ", mult);
			}
		}
		puts("");
	}
}

int main(void) {
	puts("\n課題１");
	print_times_table();

	return 0;
}
