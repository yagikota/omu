// 1201201140
// 八木洸太

#include<stdio.h>
#define MAX_NUM 1000

int main(void) {

	for (int i = 0; i <= MAX_NUM; i++) {
		if (i % 31 == 0) {
			printf("%d\n", i);
		}
	}
		return 0;
}