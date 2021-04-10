// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include<string.h>

int main(void) {
	char str[100];
	int len;

	printf("Input a word : ");
	scanf("%s", str);

	len = strlen(str);

	printf("the number of words : %d\n", len);

	return 0;
}