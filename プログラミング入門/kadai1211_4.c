// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#define AGE1 4
#define AGE2 12

int main(void) {
	int age;

	printf("Input your age : ");
	scanf("%d", &age);

	if (age < AGE1)
		printf("Addmition : free\n");
	else if (AGE1 <= age & age <= AGE2)
		printf("Addmition : 250 yen\n");
	else if (AGE2 <age)
		printf("Addmition : 400 yen\n");

	return 0;
}