// 学籍番号：1201201140
//ポータルID：seb01140
// 指名：八木洸太
//プログラム名：yagi_kota_task5_bonus.c


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double f(double x) {
    return log(x) - cos(x);
}

double f_derivative(double x) {
    return 1.0 / fabs(x) + sin(x);
}

int main(void) {
    FILE *fp;
    fp = fopen("yagi_kota_task5_bonus.csv", "w");

    clock_t start, end;
    start = clock();

    double x0 = 0.001;
    double f_xn, f_xn_deriv;
    double x_n, x_nplus1;
    double w;
    double x; // 求める解
    double eps = pow(10.0, -5.0);
    int n = 1;

    printf("反復回数n\tx_n+1\tx_n\tf(x_n)\tf'(x_n)\tx_n+1 - x_n\n");
    fprintf(fp, "反復回数n,x_n+1,x_n,f(x_n),f'(x_n),x_n+1 - x_n\n");

    x_n = x0;
    do {
        f_xn = f(x_n);
        f_xn_deriv = f_derivative(x_n);
        x_nplus1 = x_n - f_xn / f_xn_deriv;
        w = fabs(x_nplus1 - x_n) / x_n;

        printf("%d\t%.8f\t%.8f\t%.8f\t%.8f\t%.8f\n", n, x_nplus1, x_n, f_xn, f_xn_deriv, x_nplus1 - x_n);
        fprintf(fp, "%d,%.8f,%.8f,%.8f,%.8f,%.8f\n", n, x_nplus1, x_n, f_xn, f_xn_deriv, x_nplus1 - x_n);

        n++;
        x_n = x_nplus1;

    } while (w > eps);

    x = x_nplus1;
    end = clock();

    printf("f(x) = log(x) - cos(x) = 0\n\n");
    fprintf(fp, "f(x) = log(x) - cos(x) = 0\n\n");


    printf("ニュートン分法による近似解: %.8f\n\n", x);
    fprintf(fp, "ニュートン分法による近似解: %.8f\n\n", x);

    printf("処理時間\t%.6f秒\n", (double)(end - start) / CLOCKS_PER_SEC);
    fprintf(fp, "処理時間,%.6f秒\n", (double)(end - start) / CLOCKS_PER_SEC);

    fclose(fp);

    return 0;
}
