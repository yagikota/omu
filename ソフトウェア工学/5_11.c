// 1201201140
// 八木洸太

#include<stdio.h>
#include<math.h>
#include <stdlib.h>


// 100!の末尾に並ぶ0
int count_nthfactorial_prefix_zero(int n) {
	int count = 0;
	int devider = 5;
	while (devider < n) {
		count += n / devider;
		devider *= 5;
	}
	return count;
}

// base^powの桁数
int count_digit_of_number(int base, int pow) {
	return pow *  log10(base);
}

int main(void) {
	int ans1 = count_nthfactorial_prefix_zero(100);
	printf("\n100!の末尾に並ぶ0:%d", ans1);

	int ans2 = count_digit_of_number(3, 1000);
	printf("\n3^1000の桁数: %d", ans2);
	return 0;
}
