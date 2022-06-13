// 1201201140
// 八木洸太
#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <math.h>

void make_rand_int_nums(int *nums, int min, int max, int n) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		nums[i] = min + rand() % (max - min + 1);
	}
}

void print_nums(int* nums, int n) {
	for (int i = 0; i < n; i++) {
		printf("nums[%d]: %d\n", i, nums[i]);
	}
}

// 平均値
float get_average(int *nums, int n) {
	int total = 0;
	for (int i = 0; i < n; i++) {
		total += nums[i];
	}

	return (float)total / n;
}

// 中央値
int get_center(int *nums, int n) {
	return nums[n / 2];
}

// ソートで使用
int asc(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

// 分散
float get_variance(int *nums, int n) {
	float avg = get_average(nums, n);
	float sum_of_squares = 0;
	for (int i = 0; i < n; i++) {
		sum_of_squares += pow(avg - nums[i], 2);
	}

	return sum_of_squares / n;
}

int main(void) {
	int n;
	printf("配列の要素数: ");
	scanf("%d", &n);

	int *nums;
	nums = (int *)malloc(sizeof(int) * n);
	make_rand_int_nums(nums, 0, 99, n);
	qsort(nums, n, sizeof(int), asc);

	print_nums(nums, n);
	printf("平均: %.1f\n", get_average(nums, n));
	printf("最大: %d\n", nums[n-1]);
	printf("最小: %d\n", nums[0]);
	printf("中央値: %d\n", get_center(nums, n));
	printf("分散: %f\n", get_variance(nums, n));

	return 0;
}