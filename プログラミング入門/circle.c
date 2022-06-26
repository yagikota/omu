// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>

int main(void) {
    float x1, y1;
    float x2, y2;
    float k, pi, circle;

    pi = 3.141592;

    printf("x1 = ");
    scanf("%f", &x1);

    printf("y1 = ");
    scanf("%f", &y1);

    printf("x2 = ");
    scanf("%f", &x2);

    printf("y2 = ");
    scanf("%f", &y2);

    k = (x1 - x2) *(x1 - x2) + (y1 - y2) * (y1 - y2);

    circle = k * pi / 4;

    printf("円の面積 : %f\n", circle);

    return 0;
}