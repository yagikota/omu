// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#define SIZE 3

void trans_mat(int mat[][SIZE]) {
	int i;
	puts("tM = ");
	for (i = 0; i < SIZE; i++) {
		printf("%d %d %d\n", mat[0][i], mat[1][i], mat[2][i]);
		}
	}

int main(void) {
	int i, j;
	int mat[][SIZE] = {
		{1,3,2},
		{5,6,4},
		{8,7,9},
	};

	puts("M = ");
	for (i = 0; i< SIZE; i++) {
		printf("%d %d %d\n", mat[i][0], mat[i][1], mat[i][2]);
	}

	trans_mat(mat);

	return 0;
}