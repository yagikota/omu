// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include<math.h>

int main(void) {
	int a, b, x;

	puts("Please type in 2 integrs.");
	printf("a = "); scanf("%d", &a);
	printf("b = "); scanf("%d", &b);

	x = (int)pow((double)a, (double)b);

	printf("a^b = %d\n", x);

return 0;
}