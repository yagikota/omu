// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#define TIME 2020
#define CAGE_NUM 2020

int main(void) {
	int i, j, k;
	int count = 0;
	//cage
	//opened : 1
	//closed : 0
	int cage[CAGE_NUM] = {};

	for(i = 2; i <= TIME; i++) {
		for (j = 1; j <= i; j++) {
			if (i % j == 0) {
				if (cage[j - 1] == 0)
					cage[j - 1] = 1;
				else
					cage[j - 1] = 0;
				
			}
		}
	}

	for (k = 0; k < CAGE_NUM; k++) {
		if (cage[k] == 0)
			count += 1;
	}

	printf("%d minutes later, %d dogs in the cages.\n",TIME, count);

	return 0;
}