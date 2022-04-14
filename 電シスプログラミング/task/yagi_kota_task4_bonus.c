// 学籍番号：1201201140
//ポータルID：seb01140
// 指名：八木洸太
//プログラム名：yagi_kota_task4_bonus.c

#include<stdio.h>
#include<math.h>

double f(double x) {
    return 4.0 / (1.0 + pow(x, 2.0));
}

int main(void) {
    FILE *fp;
    fp = fopen("yagi_kota_task4_bonus.csv", "w");

    int n;
    int i;
    double a, b, S;
    double h;

    printf("シンプソン則による数値計算\n");
    fprintf(fp, "シンプソン則による数値計算\n");

    printf("被積分関数: f(x) = 4.0 / (1.0 + pow((x), 2.0))\n");
    fprintf(fp, "被積分関数,f(x) = 4.0 / (1.0 + x*x)\n");

    a = 0.0;
    b = 1.0;

    printf("積分区間[a, b]: a = %.2f, b = %.2f\n", a, b);
    fprintf(fp, "積分区間[a， b],a = %.2f,b = %.2f\n", a, b);

    n = 400;

    printf("数値積分の区間分割数: n = %d\n", n);
    fprintf(fp, "数値積分の区間分割数,n = %d\n", n);

    S = f(a) + f(b);
    h = (b - a) / (2.0 * n);
    for (i = 1; i < n; i++) {
        S += 4.0 * f(a + (2.0 * i - 1.0) * h) + 2.0 * f(a + 2.0 * i * h);
    }
    S += 4.0 * f(a + (2.0 * n - 1) * h);

    printf("f(x)の積分の近似値: T = %.15f\n", S * h / 3.0);
    fprintf(fp, "f(x)の積分の近似値,T = %.15f\n", S * h / 3.0);

    fclose(fp);
    return 0;
}