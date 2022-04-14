// 学籍番号：1201201140
//ポータルID：seb01140
// 指名：八木洸太
//プログラム名：yagi_kota_task8_bonus2.c

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define distance(x1, x2, y1, y2) sqrt(pow(x1 - (x2), 2.0) + pow(y1 - y2, 2.0))

typedef struct CityInfo {
    int citynumber;
    double x;
    double y;
} CityInfo;

void generate_data(double a, double b, int N);
void read_data(CityInfo cityinfodata[]);
void nearest_TSP(int N, int start, CityInfo cityinfodata[], int z[], int zz[], double *tdis);
void tow_opt_TSP(int N, CityInfo cityinfodata[], int *zz, int *zz_new, double *tdis_new);

FILE *fp1;
FILE *fp2;
FILE *fp3;

int main(void) {
    CityInfo *cityinfodata;
    int N;
    int n;
    double a, b;

    printf("訪問都市の位置座標x座標とy座標の範囲(下限a, 上限b)の設定について\n");

    printf("範囲の下限aを指定してください -->");
    scanf("%lf", &a);
    printf("範囲の上限bを指定してください -->");
    scanf("%lf", &b);
    printf("訪問都市数Nを指定してください -->");
    scanf("%d", &N);

    generate_data(a, b, N);

    cityinfodata = (CityInfo*)malloc((N+1)*sizeof(CityInfo));
    if (cityinfodata == NULL) {
        printf("メモリが確保できません\n");
        exit(1);
    }
    for (n = 0; n <= N; n++) {
        cityinfodata[n].citynumber = 0;
        cityinfodata[n].x = 0;
        cityinfodata[n].y = 0;
    }

    read_data(cityinfodata);

    fp3 = fopen("yagi_kota_task8_bonus2.csv", "w");
    printf("都市番号\tx座標\ty座標\n");
    fprintf(fp3, "都市番号,x座標,y座標\n");
    for (int n = 1; n <= N; n++)
    {
    printf("%d\t%.3f\t%.5f\n", cityinfodata[n].citynumber, cityinfodata[n].x, cityinfodata[n].y);
    fprintf(fp3, "%d,%.3f,%.5f\n", cityinfodata[n].citynumber, cityinfodata[n].x, cityinfodata[n].y);
    }

    int *z;
    z = (int *)malloc((N + 1) * sizeof(int));
    if (z == NULL) {
        printf("一次元配列zのメモリが確保できません\n");
        exit(1);
    }
    for (n = 0; n <= N; n++) {
        z[n] = 0;
    }

    int *zz;
    zz = (int *)malloc((N + 1) * sizeof(int));
    if (zz == NULL) {
        printf("一次元配列zzのメモリが確保できません\n");
        exit(1);
    }
    for (n = 0; n <= N; n++) {
        zz[n] = 0;
    }

    int start;
    printf("最初に出発する都市iを1〜%dの中から選択してください:", N);
    scanf("%d", &start);

    double tdis = 0.0;
    double searching_time;
    double start_time = clock();
    nearest_TSP(N, start, cityinfodata, z, zz, &tdis);

    double tdis_new = tdis;
    int *zz_new;
    zz_new = (int *)malloc((N + 1) * sizeof(int));
    if (zz_new == NULL) {
        printf("一次元配列zz_newのメモリが確保できません\n");
        exit(1);
    }
    for (int n = 0; n <= N; n++) {
        zz_new[n] = zz[n];
    }

    tow_opt_TSP(N, cityinfodata, zz, zz_new, &tdis_new);
    double end_time = clock();
    searching_time = (end_time - start_time) / CLOCKS_PER_SEC;

    printf("都市番号\t訪問順序\n");
    fprintf(fp3, "都市番号,訪問順序\n");
    for (int n = 1; n <= N; n++) {
        printf("%d\t\t%d\n", n, z[n]);
        fprintf(fp3, "%d,%d\n", n, z[n]);
    }

    printf("訪問順序\t都市番号\n");
    fprintf(fp3, "訪問順序,都市番号\n");
    for (int n = 1; n <= N; n++) {
        printf("%d\t\t%d\n", n, zz[n]);
        fprintf(fp3, "%d,%d\n", n, zz[n]);
    }

    printf("最近隣法での巡回経路\t2opt法での巡回経路\n");
    fprintf(fp3, "最近隣法での巡回経路,,2opt法での巡回経路\n");

    printf("訪問順序\t都市番号\t訪問順序\t都市番号\n");
    fprintf(fp3, "訪問順序,都市番号,訪問順序,都市番号\n");
    for (int n = 1; n <= N; n++) {
        printf("%d\t%d\t%d\t%d\n", n, zz[n], n, zz_new[n]);
        fprintf(fp3, "%d,%d,%d,%d\n", n, zz[n], n, zz_new[n]);
    }

    printf("start = %d\ttdis = %f\ttdis_new = %f\n", start, tdis, tdis_new);
    fprintf(fp3, "start = %d,tdis = %f,tdis_new = %f\n", start, tdis, tdis_new);

    double imp;
    imp = (tdis - tdis_new) / tdis * 100.0;
    printf("改善度 = %f（％）\n", imp);
    fprintf(fp3, "改善度 = %f（％）\n", imp);


    printf("2opt法適用 総移動距離（改善後）\t%f\n", tdis_new);
    fprintf(fp3, "2opt法適用 総移動距離（改善後）,%f\n", tdis_new);

    printf("探索処理時間\t%.15f秒\n", searching_time);
    fprintf(fp3, "探索処理時間,%.15f秒\n", searching_time);

    free(cityinfodata);
    free(z);
    free(zz);
    fclose(fp3);
    return 0;
}

void generate_data(double a, double b, int N) {
    int city_number;
    double x_point, y_point;
    double ux, uy;
    srand((unsigned int)time(NULL));
    fp1 = fopen("citydata_info.csv", "w");
    for (int n = 1; n <= N; n++) {
        city_number = n;
        ux = (double)rand() / (double)RAND_MAX;
        x_point = a + (b - a) * ux;
        uy = (double)rand() / (double)RAND_MAX;
        y_point = a + (b - a) * uy;
        fprintf(fp1, "%d,%f,%f\n", city_number, x_point, y_point);
    }
    fclose(fp1);
}

void read_data(CityInfo cityinfodata[]) {
    int n;
    fp2 = fopen("citydata_info.csv", "r");
    n = 1;
    while (fscanf(fp2, "%d,%lf,%lf", &cityinfodata[n].citynumber, &cityinfodata[n].x, &cityinfodata[n].y) != EOF) {
    n++;
    }
    fclose(fp2);
}

void nearest_TSP(int N, int start, CityInfo cityinfodata[], int z[], int zz[], double *tdis) {
    int i;
    i = start;
    int k = 1;
    z[i] = k;
    zz[k] = i;
    int next;
    printf("k\t\ti\t\tnext\t\tmin\t\ttdis\n");
    fprintf(fp3, "k,i,next,min,tdis\n");
    for (k = 2; k <= N; k++)
    {
        double min = 10000000;
        for (int j = 1; j <= N; j++) {
            if (z[j] == 0) {
                double dij = distance(cityinfodata[i].x, cityinfodata[j].x, cityinfodata[i].y, cityinfodata[j].y);
                printf("%f", dij);
                if (dij <= min)
                {
                    next = j;
                    min = dij;
                }
            }
        }
        z[next] = k;
        zz[k] = next;
        *tdis += min;
        printf("%d\t\t%d\t\t%d\t\t%.3f\t\t%.3f\n",k, i, next, min, *tdis);
        fprintf(fp3, "%d,%d,%d,%.3f,%.3f\n",k, i, next, min, *tdis);
        i = next;
    }
    double finaldis = distance(cityinfodata[start].x, cityinfodata[i].x, cityinfodata[start].y, cityinfodata[i].y);
    *tdis += finaldis;
    printf("\t%d\t%d\t%.3f\t%.3f\n", i, start, finaldis, *tdis);
    fprintf(fp3, ",%d,%d,%.3f,%.3f\n", i, start, finaldis, *tdis);
}

void tow_opt_TSP(int N, CityInfo cityinfodata[], int *zz, int *zz_new, double *tdis_new) {
    int *zz_old;
    double dis_old, dis_new;

    zz_old = (int *)malloc((N + 1) * sizeof(int));
    if (zz_old == NULL) {
        printf("一次元配列zz_oldのメモリが確保できません\n");
        exit(1);
    }
    for (int n = 0; n <= N; n++) {
        zz_old[n] = zz[n];
    }

    int check;
    do
    {
        check = 0;
        for (int i = 1; i <= N - 3; i++)
        {
            for (int j = i + 2; j <= N - 1; j++) {
                dis_old = distance(cityinfodata[zz_old[i]].x, cityinfodata[zz_old[i + 1]].x, cityinfodata[zz_old[i]].y, cityinfodata[zz_old[i + 1]].y) + distance(cityinfodata[zz_old[j]].x, cityinfodata[zz_old[j + 1]].x, cityinfodata[zz_old[j]].y, cityinfodata[zz_old[j + 1]].y);
                dis_new = distance(cityinfodata[zz_old[i]].x, cityinfodata[zz_old[j]].x, cityinfodata[zz_old[i]].y, cityinfodata[zz_old[j]].y) + distance(cityinfodata[zz_old[i + 1]].x, cityinfodata[zz_old[j + 1]].x, cityinfodata[zz_old[i + 1]].y, cityinfodata[zz_old[j + 1]].y);
                if (dis_old > dis_new) {
                    printf("(dis_old, dis_new)=(%f, %f)\n", dis_old, dis_new);
                    for (int m = 0; m <= j - i - 1; m++)
                    {
                        zz_new[i + 1 + m] = zz_old[j - m];
                    }
                    *tdis_new += dis_new - dis_old;
                    for (int k = 0; k <= N; k++) {
                        zz_old[k] = zz_new[k];
                    }
                    check = 1;
                    // printf("change\n");
                }
            }
        }
    } while (check != 0);
}
