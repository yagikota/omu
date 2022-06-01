// 1201201140
// 八木洸太

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <string.h>

#define SIZE 10

int average(int *data) {
	int total = 0;
	for (int i = 0; i < SIZE; i++) {
		total += data[i];
	}
	return total / SIZE;
}

int generate_odd_rand_int(void) {
	srand((unsigned int)time(NULL));
	return 2 * (rand() % 5) + 1;
}

int main(void){
	int rand_int;
	rand_int = generate_odd_rand_int();
	printf("一桁のランダムな奇数: %d\n", rand_int);

	int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	puts("配列nums");
	for (int i = 0; i < SIZE; i++) {
		printf("%d, ", nums[i]);
	}
	printf("配列numsの要素の平均値: %d\n", average(nums));

	char *a = "asdf";
	char *b = "asdf";
	if (strcmp(a, b) == 0) {
		printf("%sと%s: 一致\n", a, b);
	} else {
		printf("%sと%s: 不一致\n", a, b);
	}

	return 0;
}