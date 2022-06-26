#include<stdio.h>
#define pow(n) ((n) * (n))

float calc_bmi(int h, float w) {
	float b;
	b = w / pow(h / 100.0);
	return b;
}

int main(void) {
	int height = 180;
	float wight = 70.0;
	float bmi;

	bmi = calc_bmi(height, wight);

	printf("BMI is %.2f\n", bmi);
	return 0;
}