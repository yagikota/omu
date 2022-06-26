// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>

int main(void) {
	int n;
	
	printf("Input a number : ");
	scanf("%d", &n);

	if (n % 2 == 0)
		printf("%d is even number.\n", n);
	else
		printf("%d is odd nubmer.\n", n);

return 0;
}