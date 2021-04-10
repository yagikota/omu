#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int *pt;
	int n = 3, i;
	//メモリ確保
	pt = (int*)malloc(sizeof(int)*n);
	if (pt ==NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(-1);
	}

	pt[0] = 0;
	pt[1] = 1;
	pt[2] = 5;

	for (i = 0; i < n; i++) {
		printf("%d", pt[i]);
	}
	printf("\n");
	free(pt);
	return 0;
}