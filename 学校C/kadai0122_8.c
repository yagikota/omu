// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include<string.h>

int main(int argc, char **argv) {
	char *s1, *s2;
	int flag;
	s1 = argv[1];
	s2 = argv[2];
	flag = strcmp(s1,s2);
	if (flag == 0) {
		printf("%s and %s are same words.\n", s1, s2);
	} else {
		printf("%s and %s are different words.\n", s1, s2);
	}

	return 0;
}