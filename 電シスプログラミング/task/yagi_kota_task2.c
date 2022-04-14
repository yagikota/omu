// 学籍番号：1201201140
//ポータルID：seb01140
// 指名：八木洸太
//プログラム名：yagi_kota_task2.c

#include<stdio.h>
#include<math.h>

int main(void) {
    FILE *fp;
    double x, y1, y2, y3;
    fp = fopen("yagi_kota_task2.csv", "w");

    fprintf(fp, "x,(1.5)^x,xlogx,logx\n");
    for (x = 1; x <= 10; x+=1) {
        y1 = pow(1.5, x);
        y2 = x * log(x);
        y3 = log(x);
        fprintf(fp, "%.1lf,%.1lf,%.1lf,%.1lf\n", x, y1, y2, y3);
    }
    fclose(fp);

    return 0;
}
