// 1201201140
// 八木洸太
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

int get_rand_int(int min, int max) {
	return min + rand() % (max - min + 1);
}

int counter(void) {
	static int counter = 0;
	counter++;
	return counter;
}

int main(int argc, char *argv[]) {
	int max_count = atoi(argv[1]);
	int target = atoi(argv[2]);

	srand((unsigned int)time(NULL));
	int cnt;
	int flag = 0;
	for (int i = 0; i < max_count; i++) {
		int rand_int = get_rand_int(0, 9);
		if (target == rand_int) {
			flag = 1;
			cnt = counter();
		}
	}

	printf("%dの発生回数\n", target);
	if (flag == 0) {
		printf("0\n");
	} else {
		printf("%d\n", cnt);
	}
		return 0;
}