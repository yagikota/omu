#include<stdio.h>
#include<math.h>
#include <stdlib.h>

#define MAX_CAL 100
// #define N 6 // Tシャツ
#define N 16
// #define N 3
#define E 0.000001


double max(double a, double b) { return a > b ? a : b; }


double find_max_dist(double x_new[], double x_old[], int size) {
	double max_dist;
	int i;
	for (i = 0; i <= size - 1; i++) {
		max_dist = max(max_dist, fabs(x_new[i] - x_old[i]));
	}
	return max_dist;
}

void array_copy(double from[], double dist[], int size) {
	int i;
	for (i = 0; i <= size - 1; i++) {
		dist[i] = from[i];
	}
}

// 内積を求める
double get_inner_product(double x[], double y[], int size) {
	double res;
	int i;
	for (i = 0; i <= size - 1; i++) {
		res += x[i] * y[i];
	}
	return res;
}



// TODO: Nに依存しないようにする
int main(void) {
	int i, j;
	// N*N行列初期化
	// test
	// double a[N][N] = {
	// 	{6,-1,-2},
	// 	{4,1,-2},
	// 	{5,-1,-1},
	// };

	// Tシャツの一対比較行列
	// double a[N][N] = {
	// 	{1.0, 1.0, 5.0, 3.0, 9.9, 7.0},
	// 	{1.0, 1.0, 1.0, 1.0 / 5.0, 1.0 / 3.0, 1.0 / 3.0},
	// 	{1.0 / 5.0, 1.0, 1.0, 1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0},
	// 	{1.0 / 3.0, 5.0, 3.0, 1.0, 1.0, 3.0},
	// 	{1.0 / 9.0, 3.0, 3.0, 1.0, 1.0, 3.0},
	// 	{1.0 / 7.0, 3.0, 3.0, 1.0 / 3.0, 1.0 / 3.0, 1.0},
	// };

	// 視覚特性のの一対比較行列
	double a[N][N] = {
	{11, 0, 0, 1.0/3.0, 0, 0, 1.0/3.0, 0, 0, 1.0/3.0, 0, 0, 3, 0, 0, 1},
	{0, 11, 0, 1.0/3.0, 0, 0, 1.0/3.0, 0, 0, 1.0/3.0, 0, 0, 1, 0, 0, 1},
	{0, 0, 11, 1.0/3.0, 0, 0, 1.0/3.0, 0, 0, 1.0/3.0, 0, 0, 1, 0, 0, 1},
	{3, 3, 3, 9, 0, 0, 1, 0, 0, 1, 0, 0, 3, 0, 0, 1},
	{0, 0, 0, 0, 12, 0, 1, 0, 0, 1, 0, 0, 3, 0, 0, 1},
	{0, 0, 0, 0, 0, 12, 1, 0, 0, 1, 0, 0, 3, 0, 0, 1},
	{3, 3, 3, 1, 1, 1, 7, 0, 0, 1, 0, 0, 3, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 13, 0, 1, 0, 0, 3, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 13, 3, 0, 0, 3, 0, 0, 3},
	{3, 3, 3, 1, 1, 1, 1, 1, 1.0/3.0, 5, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 0, 1, 0, 0, 1.0/3.0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 1, 0, 0, 1},
	{1.0/3.0, 1, 1, 1.0/3.0, 1.0/3.0, 1.0/3.0, 1.0/3.0, 1.0/3.0, 1.0/3.0, 1, 1, 1, 3, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1.0/3.0, 1, 3, 1, 1, 1, 1, 1},
	};
	// x_old初期化
	double x_old[N] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};

	// test
	// double x_old[N] = {1.0, 2.0, 3.0}; 
	double x_new[N];
	double u[N];
	// lambdaとx「N]を求める
	double lambda;
	double x[N];
	int cal = 0;
	// while loop start
	while (cal <= MAX_CAL) {
		printf("cal:%d\n", cal);
		// normの初期化
		double Norm = 0.0;
		for (i = 0; i <= N - 1; i++) {
			Norm += x_old[i] * x_old[i];
		}
		Norm=sqrt(Norm);
		printf("\n\n---Normの表示---\n");
		printf("%f", Norm);

		// ベクトルx_oldを基準化しuとする
		for (i = 0; i <= N - 1; i++) {
			u[i] = x_old[i] / Norm;
		}
		printf("\n\n---基準化したベクトルuの表示---\n");
		for(i=0; i<=N-1; i++) {
			printf("%3.1lf,",u[i]);
		}

		// x_new = Au
		for (i = 0; i <= N - 1; i++) {
			x_new[i] = 0.0;
			for (j = 0; j <= N - 1; j++) {
				x_new[i] += a[i][j] * u[j];
			}
		}
		printf("\n\n---行列Aと基準化したベクトルxの積の表示---\n");
		for(i=0; i<=N-1; i++) {
			printf("%3.1lf,",x_new[i]);
		}

		double max_dist;
		max_dist = find_max_dist(x_new, x_old, N);
		printf("\nmax_dist=%.8f\n", max_dist);
		if (max_dist < E) {
			// 収束条件満たす
			// 固有値
			lambda = get_inner_product(x_new, u, N);
			// 固有ベクトル
			array_copy(u, x, N);
			break;
		} else {
			array_copy(x_new, x_old, N);
			cal++;
		}

		if (cal >= MAX_CAL) { 
			// x_oldをx_newで初期化
			cal = 0;
		}
	}
	// while loop end

	printf("\n\n---固有値と固有ベクトルの表示--\n");
	printf("固有値: %f\n", lambda);
	printf("\n固有ベクトル\n");
	for(i=0; i<=N-1; i++) {
		printf("%3.3lf,",x[i]);
	} 

	return 0;
}

