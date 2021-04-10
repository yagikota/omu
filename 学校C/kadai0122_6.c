// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include<string.h>
#define MAX_LEN 16
#define WORDS 3

void swap_str(char *sx, char *sy) {
	char temp[MAX_LEN];
	strcpy(temp, sx);
	strcpy(sx, sy);
	strcpy(sy, temp);
}

void sort(char str[WORDS][MAX_LEN], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n -1; j > i; j--) {
			if (strlen(str[j-1]) < strlen(str[j])) {
				swap_str(str[j-1], str[j]);
			}
		}
	}
}

int main(void) {
	char subjects[WORDS][MAX_LEN] = {"Chemistry", "English", "Mathematics"};
	int i;

	sort(subjects,WORDS);

	for (i = 0; i < WORDS; i++) {
		printf("%s\n", subjects[i]);
	}

	return 0;
}