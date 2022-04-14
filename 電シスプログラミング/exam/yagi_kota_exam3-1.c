#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MaxN 100

int main(void) {
    FILE *fp1;
    fp1 = fopen("data1.csv", "r");
    double x[MaxN] = {0.0};
    int i = 0;
    int N;

    while (fscanf(fp1, "%lf,", &x[i]) != EOF) {
        printf("一次元配列xの配列要素%dへの読み取り格納データ:%lf\n", i, x[i]);
        i++;

    }
    fclose(fp1);

    return 0;
}