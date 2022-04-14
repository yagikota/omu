#include<stdio.h>
#include<math.h>

// 関数形式マクロ
#define f(x0) (7.0 * pow((x0), 4.0) - 5.0 * pow((x0), 3.0) + 3.0 * (x0))

// 自作関数
double f_x(double x0) {
    double fx0;
    fx0 = 7.0 * pow(x0, 4.0) - 5.0 * pow(x0, 3.0) + 3.0 * x0;
    return fx0;
}

int main(void) {
    double a = 1.99;
    double b = 0.01;
    printf("f(a+b) = %f, f_x(a+b) = %f\n", f(a + b), f_x(a + b));
    return 0;
}