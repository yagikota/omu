// 1201201140
// 八木洸太

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define NUMS 100

int generate_rand_int(int min, int max) {
	return min + rand() % (max - min + 1);
}

// void print_nums(int *nums) {
// 	for (int i = 0; i < NUMS; i++) {
// 		printf("%d\n", *(nums + i));
// 	}
// }

void print_counter(int *counter) {
	puts("出現頻度");
	for (int i = 0; i < NUMS; i++)
	{
		printf("%d: %d回\n", i, *(counter + i));
	}
}

int main(void) {
	// srand((unsigned int)time(NULL));
	srand(100);

	int *nums;
	nums = (int*)malloc(sizeof(int) * NUMS);
	for (int i = 0; i < NUMS; i++) {
		*(nums + i) = generate_rand_int(0, 99);
	}

	// print_nums(nums);

	int *counter;
	counter = (int *)malloc(sizeof(int) * NUMS);
	for (int i = 0; i < NUMS; i++) {
		*(counter + i) = 0;
	}

	for (int i = 0; i < NUMS; i++) {
		int idx = *(nums + i);
		*(counter + idx) += 1;
	}

	print_counter(counter);

	free(nums);
	free(counter);
	return 0;
}
