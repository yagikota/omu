// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include<stdlib.h>
#define WEEK 7
#define MAX_WORDS 10

int zeller(int y, int m, int d) {
	int value;
	//1,2月の場合
	if (m < 3) {
		y--;
		m += 12;
	}

	value = (y + y/4 - y/100 + y/400 + (13*m + 8) / 5 + d) % 7;
	return value;
}

int main(int argc, char **argv) {
	int y = atoi(argv[1]);
	int m = atoi(argv[2]);
	int d = atoi(argv[3]);
	char week[WEEK][MAX_WORDS] = {"Sunday", "Monday", "Thuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	int h;
	h = zeller(y, m, d);

	printf("%d/%d/%d is %s\n", y, m, d, week[h]);

	return 0;
}