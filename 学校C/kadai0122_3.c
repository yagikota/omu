// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include<math.h>
#define MAX_NUM 100

void find_prime_nums(int max_num) {
	int i, j, flag;
	printf("2\n");//2 is prime number

	//prime number is odd number
	for (i = 3; i <= max_num; i += 2) {
		flag = 0;
		//check the divisors of N that are less than sqrt(N)
		for (j = 3; j <= sqrt(i); j += 2) {
			if (i % j == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			printf("%d\n", i);
	}
}

int main(void) {
	printf("--Prime numbers(from 1 to 100)--\n");
	find_prime_nums(MAX_NUM);
	return 0;
}