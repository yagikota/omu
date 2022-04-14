// 学籍番号：1201201140
//ポータルID：seb01140
// 指名：八木洸太
//プログラム名：yagi_kota_exam2-2.c

#include<stdio.h>
#include<math.h>

int main(void) {
    FILE *fp;
    double x, y;
    fp = fopen("yagi_kota_exam2-2.csv", "w");

    printf("x (5x)^0.3\n");
    for (x = 0.5; x <= 10.5; x++) {
        y = pow((5 * x), 0.3);
        printf("%.1lf %lf\n", x, y);
    }

    fprintf(fp, "x, (5x)^0.3\n");
    for (x = 0.5; x <= 10.5; x++) {
        y = pow((5 * x), 0.3);
        fprintf(fp, "%.1lf,%lf\n", x, y);
    }
    fclose(fp);

    return 0;
}