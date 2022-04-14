// 学籍番号：1201201140
//ポータルID：seb01140
// 指名：八木洸太
//プログラム名：yagi_kota_exam5.c

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double f(double x) {
    return log(x) - cos(x);
}

int main(void) {
    FILE *fp;
    fp = fopen("yagi_kota_exam5.csv", "w");
    clock_t start, end;
    start = clock();

    double a, delta_x;
    double x1, x2, y1, y2;
    int n;
    a = 0.001;
    delta_x = 0.001;
    x1 = a;
    n = 1;

    printf("反復回数n\tx1\tf(x1)\n");
    fprintf(fp, "反復回数n,x1,f(x1)\n");

    do {
        y1 = f(x1);
        x2 = x1 + delta_x;
        y2 = f(x2);
        printf("%d\t%f\t%f\n", n, x1, y1);
        fprintf(fp, "%d,%f,%f\n", n, x1, y1);

        x1 = x2;
        n++;

    } while (y1 * y2 > 0);

    x1 -= delta_x;
    end = clock();

    printf("f(x) = log(x) - cos(x) = 0\n\n");
    fprintf(fp, "f(x) = log(x) - cos(x) = 0\n\n");

    printf("直接探索法による近似解: %f\n\n", x1);
    fprintf(fp, "直接探索法による近似解: %f\n\n", x1);

    printf("処理時間\t%f秒\n", (double)(end - start) / CLOCKS_PER_SEC);
    fprintf(fp, "処理時間,%f秒\n", (double)(end - start) / CLOCKS_PER_SEC);

    fclose(fp);

    return 0;
}