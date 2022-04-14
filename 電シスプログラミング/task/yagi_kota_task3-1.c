#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MaxN 100

// 最大値を求める関数
double max(double *data, int n) {
    double max = data[0];
    for (int i = 1; i < n; i++) {
        if (max < data[i]) {
            max = data[i];
        }
    }

    return max;
}

// 最小値を求める関数
double min(double *data, int n) {
    double min = data[0];
    for (int i = 1; i < n; i++) {
        if (min > data[i]) {
            min = data[i];
        }
    }

    return min;
}

// 範囲を求める関数
double range(double max, double min) {
    return (max - min);
}

// 平均値を求める関数
double average(double *data, int n) {
    double total = 0;
    double average;
    for (int i = 0; i < n; i++) {
        total += data[i];
    }
    return total / n;
}

// 不偏分散を求める関数
double variance(double *data, int n) {
    double avg = average(data, n);
    double sum_of_squares = 0;
    for (int i = 0; i < n; i++) {
        sum_of_squares += pow(avg - data[i], 2);
    }

    return sum_of_squares / (n - 1);
}

// 標準偏差を求める関数
double std_deviation(double *data, int n) {
    return pow(variance(data, n), 0.5);
}

int main(void) {
    FILE *fp1;
    FILE *fp2;
    fp1 = fopen("data3.csv", "r");
    fp2 = fopen("yagi_kota_task3-1.csv", "w");
    double x[MaxN] = {0.0};
    double y[MaxN] = {0.0};
    int i = 0;
    int N;
    double max_x, min_x, range_x, avg_x, variance_x, std_deviation_x;
    double max_y, min_y, range_y, avg_y, variance_y, std_deviation_y;

    printf("No\tx\t\ty\n");
    fprintf(fp2, "No,x,y\n");

    while (fscanf(fp1, "%lf,%lf", &x[i], &y[i]) != EOF) {
        printf("%d\t%f\t%f\n", i+1, x[i], y[i]);
        fprintf(fp2, "%d,%f,%f\n", i+1, x[i], y[i]);
        i++;
    }
    N = i;
    max_x = max(x, N);
    max_y = max(y, N);
    min_x = min(x, N);
    min_y = min(y, N);
    range_x = range(max_x, min_x);
    range_y = range(max_y, min_y);
    avg_x = average(x, N);
    avg_y = average(y, N);
    variance_x = variance(x, N);
    variance_y = variance(y, N);
    std_deviation_x = std_deviation(x, N);
    std_deviation_y = std_deviation(y, N);

    putchar('\n');
    printf("実データ数N\t%d\t%d\n", N, N);
    fprintf(fp2, "実データ数N,%d,%d\n", N,N);

    printf("最大値\t%f\t%f\n", max_x, max_y);
    fprintf(fp2, "最大値,%f,%f\n", max_x, max_y);

    printf("最小値\t%f\t%f\n", min_x, min_y);
    fprintf(fp2, "最小値,%f,%f\n", min_x, min_y);

    printf("範囲\t%f\t%f\n", range_x, range_y);
    fprintf(fp2, "範囲,%f,%f\n", range_x, range_y);

    printf("平均\t%f\t%f\n", avg_x, avg_y);
    fprintf(fp2, "平均,%f,%f\n", avg_x, avg_y);

    printf("不偏分散\t%f\t%f\n", variance_x, variance_y);
    fprintf(fp2, "不偏分散,%f,%f\n", variance_x, variance_y);

    printf("標準偏差\t%f\t%f\n", std_deviation_x, std_deviation_y);
    fprintf(fp2, "標準偏差,%f,%f\n", std_deviation_x, std_deviation_y);

    fclose(fp1);
    fclose(fp2);

    return 0;
}