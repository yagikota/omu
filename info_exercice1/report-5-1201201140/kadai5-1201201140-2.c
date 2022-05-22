// 1201201140
// 八木洸太

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <math.h>

float get_average(float *data, int n) {
	float total = 0;
	float average;
	for (int i = 0; i < n; i++) {
		total += data[i];
	}
	average = total / n;

	return average;
}

float get_variance(float *data, int n) {
	float avg = get_average(data, n);
	float sum_of_squares = 0;
	for (int i = 0; i < n; i++) {
		sum_of_squares += pow(avg - data[i], 2);
	}

	return sum_of_squares / n;
}

void analyze_heights() {
	float heights[5] = {158.3, 189.5, 167.2, 177.4, 146.8};
	float avg = get_average(heights, 5);
	float variance = get_variance(heights, 5);
	printf("平均: %f\n", avg);
	printf("分散: %f\n", variance);
}

int asc(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

void sort() {
	int a[10] = {10, 32, 43, 8, 21, 92, 55, 42, 14, 9};
	qsort(a, sizeof(a) / sizeof(a[0]), sizeof(int), asc);
	for (int i = 0; i < 10; i++) {
		printf("%d, ", a[i]);
	}
}

int main(void) {
	puts("\n課題2");
	analyze_heights();

	return 0;
}
