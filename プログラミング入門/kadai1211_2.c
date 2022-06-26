// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>

int main(void) {
	float tax = 1.1;
	int tax_included_price;
	int p;

	printf("Input a rice : ");
	scanf("%d", &p);
	tax_included_price = (int)(p * tax);

	printf("The price including tax is %d.\n", tax_included_price);

	return 0;
}