// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>

int main(void) {
	int i, j, k;

	int matrix1 [3][3] = {
	{3, 0, 1},
	{1, 2, 0},
	{1, 1, -1},
	};
	int matrix2 [3][3] = {
	{1, 3, 2},
	{4, 6, 5},
	{7, 9, 8},
	};
	int sum [3][3] = {};
	int product [3][3] = {};

// sum
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			sum[i][j] = matrix1[i][j] + matrix2[i][j];
	}

//product
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			product[i][j] = matrix1[i][0] * matrix2[0][j] + matrix1[i][1] * matrix2[1][j] + matrix1[i][2] * matrix2[2][j];
	}
//product別解
	// for (i = 0; i < 3; i++) {
	// 	for (j = 0; j < 3; j++) {
	// 		product[i][j] = 0;
	// 		for (k = 0; k < 3; k++) {
	// 			product[i][j] += matrix1[i][k] * matrix2[k][j];
	// 		}
	// 	}
	// }

	puts("sum");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf("%4d", sum[i][j]);
		putchar('\n');
}

	puts("product");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf("%4d", product[i][j]);
		putchar('\n');
}
	return 0;
}