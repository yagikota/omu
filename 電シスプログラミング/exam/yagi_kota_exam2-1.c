// 学籍番号：1201201140
//ポータルID：seb01140
// 指名：八木洸太
//プログラム名：yagi_kota_exam2-1.c


#include<stdio.h>
#include<math.h>


int main(void) {
    FILE *fp;
    fp = fopen("yagi_kota_exam2-1.csv", "w");

    double x1, y1;
    x1 = 1.73;
    y1 = log(2 * x1);

    printf("x1  log(2 * x1)\n");
    printf("%.2lf %.8lf", x1, y1);

    fprintf(fp, "x1,log(2 * x1)\n");
    fprintf(fp, "%.2lf,%.8lf", x1, y1);
    fclose(fp);

    return 0;
}
