// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>

int main(void) {
	float pi = 3.14;
	float d;//diameter
	float s;//area

	printf("Please type in a real number : ");
	scanf("%f",&d);

	s = pi * (d / 2) * (d / 2);

	printf("Circle Area : %f\n", s);

	return 0;
}