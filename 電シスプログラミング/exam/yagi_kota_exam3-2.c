#include<stdio.h>
#include<stdint.h>
#include<math.h>

#define MaxN 100

int main(void) {
    FILE *fp1;
    FILE *fp2;
    fp1 = fopen("data1.csv", "r");
    fp2 = fopen("result.csv", "w");
    int i = 0;
    int N;
    double x[MaxN] = {0.0};

    while (fscanf(fp1, "%lf,", &x[i]) != EOF) {
        printf("%lf\n", x[i]);
        fprintf(fp2, "%lf\n", x[i]);
        i++;
    }
    fclose(fp1);

    N = i;
    printf("データ実読込数:%d\n", N);
    fprintf(fp2, "データ実読込数:%d\n", N);
    fclose(fp2);

    return 0;
}