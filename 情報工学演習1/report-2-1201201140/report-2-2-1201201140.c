// 1201201140
// 八木洸太

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define MAX_CAL 100

// create random int within [min, max]
int get_random(int min, int max) {
	return min + rand() % (max - min + 1);
}

int main(void) {
	int a, i;
	srand((unsigned int)time(NULL));
	for(i = 0; i < MAX_CAL; i++){
	a = get_random(1, 100);
	printf("%d: %d\n",i+1, a); 
	}
	return 0;
}
