// 1201201140
// 八木洸太

#include<stdio.h>
#include <stdlib.h> 

double p(int n) {
	double y = 1.0;
	for (int i = 1; i < n; i++) {
		y *= (365 - i) / 365.0;
	}
	return 1 - y;
}

int main(int argc, char *argv[]) {
	int n = atoi(argv[1]);
	printf("クラス内に同じ誕生日の人が2人以上いる確率: %.1f％\n", p(n)*100);

	double y = 1.0;
	int i = 0;
	while (y > 0.5) {
		y *= (365 - i) / 365.0;
		i++;
	}
	printf("Nが%d人以上だとその確率が50％以上になる\n", i);
	return 0;
}
