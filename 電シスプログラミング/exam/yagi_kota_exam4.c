// 学籍番号：1201201140
//ポータルID：seb01140
// 指名：八木洸太
//プログラム名：yagi_kota_exam4.c

#include<stdio.h>
#include<math.h>

// 関数形式マクロ
#define f(x0) (7.0 * pow((x0), 4.0) - 5.0 * pow((x0), 3.0) + 3.0 * (x0))

// 自作関数
double f_x(double x0) {
    double fx0;
    fx0 = 7.0 * pow(x0, 4.0) - 5.0 * pow(x0, 3.0) + 3.0 * x0;
    return fx0;
    // return 7.0 * pow(x0, 4.0) - 5.0 * pow(x0, 3.0) + 3.0 * x0;
}

int main(void) {
    FILE *fp1;
    fp1 = fopen("yagi_kota_exam4.csv", "w");

    double x0;
    double h = 0.01;

    double fx0u;
    double fx0m;

    double dfdx0u;
    double d2fdx02u;

    double dfdx0m;
    double d2fdx02m;

    printf("f(x0) = 7.0 * x0^4 - 5.0 * x0^3 + 3.0 * x0\n\n");
    printf("choice: m:自作関数を利用, m:引数つき関数形式マクロを利用\n");
    putchar('\n');
    printf("choice\tx0\tfx0\th\tdfdx0\td2fdx02\n");

    fprintf(fp1, "f(x0) = 7.0 * x0^4 - 5.0 * x0^3 + 3.0 * x0\n\n");
    fprintf(fp1, "choice: m:自作関数を利用、 m:引数つき関数形式マクロを利用\n\n");
    fprintf(fp1, "choice,x0,fx0,h,dfdx0,d2fdx02\n");

    for (x0 = 1.99; x0 <= 2.01; x0 += h) {
        fx0u = f_x(x0);
        fx0m = f(x0);

        dfdx0u = (f_x(x0 + h) - f_x(x0 - h)) / (2.0 * h);
        dfdx0m = (f(x0 + h) - f(x0 - h)) / (2.0 * h);
        printf("%f, %f\n", f_x(x0 + h), f_x(x0 - h));
        printf("%f, %f\n", f(x0 + h), f(x0 - h));

        d2fdx02u = (f_x(x0 + h) - 2.0 * f_x(x0) + f_x(x0 - h)) / pow(h, 2.0);
        d2fdx02m = (f(x0 + h) - 2.0 * f(x0) + f(x0 - h)) / pow(h, 2.0);

        printf("u\t%f\t%f\t%f\t%f\t%f\n", x0, fx0u, h, dfdx0u, d2fdx02u);
        printf("m\t%f\t%f\t%f\t%f\t%f\n", x0, fx0m, h, dfdx0m, d2fdx02m);

        fprintf(fp1, "u,%f,%f,%f,%f,%f\n", x0, fx0u, h, dfdx0u, d2fdx02u);
        fprintf(fp1, "m,%f,%f,%f,%f,%f\n", x0, fx0m, h, dfdx0m, d2fdx02m);
    }

    fclose(fp1);
    return 0;
}
