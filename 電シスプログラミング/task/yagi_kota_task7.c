// 学籍番号：1201201140
//ポータルID：seb01140
// 指名：八木洸太
//プログラム名：yagi_kota_task7.c

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define MaxN 100

struct Point {
    double x;
    double y;
};

double distance(double x1, double x2, double y1, double y2) {
    return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}


int main(void) {
    FILE *fp1;
    FILE *fp2;
    fp1 = fopen("yagi_kota_task7-2.csv", "w");
    fp2 = fopen("task7_citydata.csv", "r");
    struct Point city[MaxN + 1] = {{0.0, 0.0}};
    int k = 1;
    while (fscanf(fp2, "%lf,%lf", &city[k].x, &city[k].y) != EOF) {
    k++;
    }
    int N = k - 1;
    printf("訪問する都市が%d都市あります。\n\n", N);
    fprintf(fp1, "訪問する都市が%d都市あります。\n\n", N);

    printf("訪問する%dの都市番号1〜都市番号%dの位置座標次の通りです。\n\n", N, N);
    fprintf(fp1, "訪問する%dの都市番号1〜都市番号%dの位置座標次の通りです。\n\n", N, N);

    printf("都市番号\tx座標\ty座標\n");
    fprintf(fp1, "都市番号,x座標,y座標\n");
    for (int a = 1; a <= N; a++) {
        printf("%d\t%f\t%f\n", a, city[a].x, city[a].y);
        fprintf(fp1, "%d,%f,%f\n", a, city[a].x, city[a].y);
    }

    int i;
    printf("最初に出発する都市iを1〜%dの中から選択してください:", N);
    scanf("%d", &i);

    printf("最初に出発する都市iを都市番号%dにした場合の結果を示します。\n", i);
    fprintf(fp1, "最初に出発する都市iを都市番号%dにした場合の結果を示します。\n", i);
    printf("出発都市番号 i\t訪問都市 j\t2都市間距離 dij\n");
    fprintf(fp1, "出発都市番号 i,訪問都市 j,2都市間距離 dij\n");

    double dis;
    for (int a = 1; a <= N; a++) {
        if (a != i) {
            dis = distance(city[i].x, city[a].x, city[i].y, city[a].y);
            printf("%d\t%d\t%.2f\n", i, a, dis);
            fprintf(fp1, "%d,%d,%.2f\n", i, a, dis);
        }
    }

    fclose(fp2);
    fclose(fp1);
    return 0;
}