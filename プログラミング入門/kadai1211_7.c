// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include<math.h>
#define NUMBER 10

int main(void) {
	int i;
	int nums[NUMBER] = {92, 5, 77, 39, 42, 84, 23, 64, 50, 15};
	float sum = 0;
	float rss = 0;
	float avg;
	float var;
	
	for (i = 0; i < NUMBER; i++)
		sum += nums[i];
	avg = sum / NUMBER;

	for (i = 0; i < NUMBER; i++)
		rss += (nums[i] - avg) * (nums[i] - avg);
	var = rss / NUMBER;

	printf("AVERAGE : %.1f\nVARIANCE : %.2f\n", round(avg *100) / 100, var);

	return 0;
}