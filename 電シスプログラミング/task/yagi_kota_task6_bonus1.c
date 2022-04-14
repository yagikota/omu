// 学籍番号：1201201140
//ポータルID：seb01140
// 指名：八木洸太
//プログラム名：yagi_kota_task6_bonus1.c

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


#define f(x) (log(x) - cos(x))

FILE *fp;

void bisect(double *left, double *right, int *n) {
    double y_r, y_l, y_m;
    double w;
    double middle;
    double eps = pow(10.0, -5.0);
    y_r = f(*right);
    y_l = f(*left);
    w = fabs(*right - *left);
    middle = (*right + *left) / 2.0;
    y_m = f(middle);
    printf("%d\t%.7f\t%.8f\n", *n, middle, y_m);
    fprintf(fp, "%d,%.7f,%.8f\n", *n, middle, y_m);

    if (y_m * y_r < 0) {
        *left = middle;
    }
    if (y_m * y_l < 0) {
        *right = middle;
    }

    (*n)++;

    if (w >= eps)
        bisect(left, right, n);
}

int main(void) {
    fp = fopen("yagi_kota_task6_bonus1.csv", "w");

    clock_t start, end;
    start = clock();

    double right, left;// right: 区間の右端, left: 区間の左端, middle: rightとleftの中点のx座標
    double w;
    double y_r, y_l, y_m;
    double x;// 求める解
    double a = 0.001;
    double b = 3.0;
    int n = 1;

    right = b;
    left = a;

    printf("反復回数n\tx1\tf(x1)\n");
    fprintf(fp, "反復回数n,x1,f(x1)\n");

    bisect(&left, &right, &n);

    x = (right + left) / 2.0;
    end = clock();

    printf("f(x) = log(x) - cos(x) = 0\n\n");
    fprintf(fp, "f(x) = log(x) - cos(x) = 0\n\n");

    printf("2分法: a = 0.001000 b = 3.000000\n");
    fprintf(fp, "2分法: a = 0.001000 b = 3.000000\n");

    printf("2分法による近似解: %f\n\n", x);
    fprintf(fp, "2分法による近似解: %.8f\n\n", x);

    printf("処理時間\t%f秒\n", (double)(end - start) / CLOCKS_PER_SEC);
    fprintf(fp, "処理時間,%f秒\n", (double)(end - start) / CLOCKS_PER_SEC);

    fclose(fp);

    return 0;
}
