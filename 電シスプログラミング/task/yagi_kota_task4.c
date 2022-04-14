// 学籍番号：1201201140
//ポータルID：seb01140
// 指名：八木洸太
//プログラム名：yagi_kota_task4.c

#include<stdio.h>
#include<math.h>

double f(double x) {
    return 4.0 / (1.0 + pow(x, 2.0));
}

int main(void) {
    FILE *fp;
    fp = fopen("yagi_kota_task4.csv", "w");

    int n;
    int i;
    double a, b, T;
    double h;

    printf("台形則による数値計算\n");
    fprintf(fp, "台形則による数値計算\n");

    printf("被積分関数: f(x) = 4.0 / (1.0 + pow((x), 2.0))\n");
    fprintf(fp, "被積分関数,f(x) = 4.0 / (1.0 + x*x)\n");
    

    a = 0.0;
    b = 1.0;

    printf("積分区間[a, b]: a = %.2f, b = %.2f\n", a, b);
    fprintf(fp, "積分区間[a， b],a = %.2f,b = %.2f\n", a, b);

    n = 400;

    printf("数値積分の区間分割数: n = %d\n", n);
    fprintf(fp, "数値積分の区間分割数,n = %d\n", n);

    T = (f(a) + f(b)) / 2.0;
    h = (b - a) / n;
    for (i = 1; i < n; i++) {
        T += f(a + i * h);
    }

    printf("f(x)の積分の近似値: T = %.10f\n", T*h);
    fprintf(fp, "f(x)の積分の近似値,T = %.10f\n", T*h);

    fclose(fp);
    return 0;
}