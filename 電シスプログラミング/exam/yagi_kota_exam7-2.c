// 学籍番号：1201201140
//ポータルID：seb01140
// 指名：八木洸太
//プログラム名：yagi_kota_exam7-2.c

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define N 2

struct Point {
    double x;
    double y;
};

double distance(double x1, double x2, double y1, double y2) {
    return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}


int main(void) {
    FILE *fp;
    fp = fopen("yagi_kota_exam7-2.csv", "w");

    struct Point city[N + 1] = {{0.0, 0.0}, {90.06, 14.19}, {18.80, 30.24}};

    int i = 1;
    int j = 2;
    double dij;
    if (j != i) {
        dij = distance(city[1].x, city[2].x, city[1].y, city[2].y);
    }

    printf("都市番号\tx座標\ty座標\n");
    fprintf(fp, "都市番号,x座標,y座標\n");

    for (int k = 1; k <= N; k++) {
        printf("%d\t%.2f\t%.2f\n", k, city[k].x, city[k].y);
        fprintf(fp, "%d,%.2f,%.2f\n", k, city[k].x, city[k].y);
    }

    printf("出発都市番号 i\t次の訪問都市 j\t2都市間距離 dij\n");
    printf("%d\t%d\t%.2f\n", i, j, dij);

    fprintf(fp, "出発都市番号 i,次の訪問都市 j,2都市間距離 dij\n");
    fprintf(fp, "%d,%d,%.2f\n", i, j, dij);

    fclose(fp);
    return 0;
}