// 1201201140
// 八木洸太

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <math.h>

int asc(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

void sort() {
	int a[10] = {10, 32, 43, 8, 21, 92, 55, 42, 14, 9};
	qsort(a, sizeof(a) / sizeof(a[0]), sizeof(int), asc);
	for (int i = 0; i < 10; i++) {
		printf("%d, ", a[i]);
	}
}

int main(void) {
	puts("\n課題3");
	sort();

	return 0;
}
