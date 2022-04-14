#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MaxN 100

double average(double *data, int n) {
    double total = 0;
    double average;
    for (int i = 0; i < n; i++) {
        total += data[i];
    }
    average = total / n;

    return average;
}

int main(void) {
    FILE *fp1;
    FILE *fp2;
    fp1 = fopen("data3.csv", "r");
    fp2 = fopen("yagi_kota_exam3.csv", "w");
    double x[MaxN] = {0.0};
    double y[MaxN] = {0.0};
    int i = 0;
    int N;
    double avg_x, avg_y;

    printf("No\tx\t\ty\n");
    fprintf(fp2, "No,x,y\n");

    while (fscanf(fp1, "%lf,%lf", &x[i], &y[i]) != EOF) {
        printf("%d\t%f\t%f\n", i+1, x[i], y[i]);
        fprintf(fp2, "%d,%f,%f\n", i+1, x[i], y[i]);
        i++;
    }
    N = i;
    avg_x = average(x, N);
    avg_y = average(y, N);

    putchar('\n');
    printf("実データ数N\t%d\t%d\n", N, N);
    fprintf(fp2, "実データ数N,%d,%d\n", N,N);

    printf("平均\t%f\t%f\n", avg_x, avg_y);
    fprintf(fp2, "平均,%f,%f\n", avg_x, avg_y);

    fclose(fp1);
    fclose(fp2);

    return 0;
}