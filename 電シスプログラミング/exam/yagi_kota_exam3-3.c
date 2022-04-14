#include<stdio.h>
#include<stdint.h>
#include<math.h>

#define MaxN 100

int main(void) {
    FILE *fp1;
    fp1 = fopen("data2.csv", "r");
    int i = 0;
    double x[MaxN] = {0.0};

    while (fscanf(fp1, "%lf", &x[i]) != EOF) {
        printf("%lf\n", x[i]);
        i++;
    }
    fclose(fp1);

    return 0;
}