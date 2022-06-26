// 学籍番号:1201201140
// 名前：八木洸太
#include<stdio.h>

int main(void) {
	char str[32];
	char *pt;
	char c;
	pt = str;

	printf("Please type in a word : ");
	scanf("%s", str);

	while (*pt != '\0') {
		c = *pt;
		if ('A'<= c && c <= 'Z') {
			c += 32;
			printf("%c", c);
		}
		else if ('a'<= c && c <= 'z') {
			c -= 32;
			printf("%c", c);
		}
		pt++;
	}
	puts("");
	return 0;
}