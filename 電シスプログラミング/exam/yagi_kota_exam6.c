// 学籍番号：1201201140
//ポータルID：seb01140
// 指名：八木洸太
//プログラム名：yagi_kota_exam6.c

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define delta_x 0.001
#define f(x) (log(x) - cos(x))
FILE *fp;
double direct_recursion(double x1, int n);

int main(void) {
    clock_t start, end;
    start = clock();
    fp = fopen("yagi_kota_exam6.csv", "w");

    double a;
    double x1;
    int n;
    a = 0.001;
    x1 = a;
    n = 1;

    printf("反復回数n\tx1\tf(x1)\n");
    fprintf(fp, "反復回数n,x1,f(x1)\n");
    fclose(fp);

    x1 = direct_recursion(x1, n);
    end = clock();

    fp = fopen("yagi_kota_exam6.csv", "a");
    printf("f(x) = log(x) - cos(x) = 0\n\n");
    fprintf(fp, "f(x) = log(x) - cos(x) = 0\n\n");

    printf("直接探索法による近似解: %.8f\n\n", x1);
    fprintf(fp, "直接探索法による近似解: %.8f\n\n", x1);

    printf("処理時間\t%.6f秒\n", (double)(end - start) / CLOCKS_PER_SEC);
    fprintf(fp, "処理時間,%.6f秒\n", (double)(end - start) / CLOCKS_PER_SEC);

    fclose(fp);

    return 0;
}

double direct_recursion(double x1, int n) {
    fp = fopen("yagi_kota_exam6.csv", "a");
    double y1, y2, x2;
    y1 = f(x1);
    x2 = x1 + delta_x;
    y2 = f(x2);
    printf("%d\t%f\t%.8f\n", n, x1, y1);
    fprintf(fp, "%d,%f,%.8f\n", n, x1, y1);

    if (y1 * y2 > 0)
    {
        fclose(fp);
        return direct_recursion(x2, n + 1);
    }
    else
    {
        fclose(fp);
        return x1;
    }
}