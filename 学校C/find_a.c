// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>

int find_a (const char s[]) {
	int i = 0;
	int count = 0;

	while (s[i]) {
		if (s[i] == 'a')
			count++;
		i++;
	}
	return count;
}

int main(void) {
	char str[100];
	printf("Please type in a word : ");
	scanf("%s", str);
	printf("Number of 'a' is %d\n", find_a(str));
	
	return 0;
}