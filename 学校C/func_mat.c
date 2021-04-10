// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>

void calc_product(int mtrx1[][3], int mtrx2[][3], int prod[][3]) {
	int i, j, k;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			prod[i][j] = 0;
			for (k = 0; k < 3; k++) {
				prod[i][j] += mtrx1[i][k] * mtrx2[k][j];
			}
		}
	}
}

// void calc_product(int *mtrx1, int *mtrx2, int *prod, int numline, int numlen) {
// 	int i, j, k;
// 	for (i = 0; i < numline; i++) {
// 		for (j = 0; j < 3; j++) {
// 			prod[i * numlen + j] = 0;
// 			for (k = 0; k < 3; k++) {
// 				prod[i] += mtrx1[i] * mtrx2[k];
// 			}
// 		}
// 	}
// }

int main(void) {
	int i, j;

	int matrix1 [][3] = {
	{3, 0, 1},
	{1, 2, 0},
	{1, 1, -1},
	};

	int matrix2 [][3] = {
	{1, 3, 2},
	{4, 6, 5},
	{7, 9, 8},
	};

	int prod [][3] = {0};

	calc_product(matrix1, matrix2, prod);

	puts("product");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf("%4d", prod[i][j]);
		putchar('\n');
	}
	return 0;
}
