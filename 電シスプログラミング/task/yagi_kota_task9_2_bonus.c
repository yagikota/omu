// 学籍番号：1201201140
//ポータルID：seb01140
// 指名：八木洸太
//プログラム名：yagi_kota_task9_2_bonus.c

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// 平均値を求める関数
double average(double *data, int n) {
    double total = 0;
    double average;
    for (int i = 0; i < n; i++) {
        total += data[i];
    }
    return total / n;
}

// 不偏分散を求める関数
double variance(double *data, int n) {
    double avg = average(data, n);
    double sum_of_squares = 0;
    for (int i = 0; i < n; i++) {
        sum_of_squares += pow(avg - data[i], 2);
    }
    return sum_of_squares / (n - 1);
}

// 標準偏差を求める関数
double std_deviation(double *data, int n) {
    return pow(variance(data, n), 0.5);
}

void create_uniform_rand_nums(double *x, int N, double min, double max) {
    for (int i = 0; i < N; i ++) {
        double u = (double)rand() / (double)(RAND_MAX);
        x[i] = min + (max -min) * u;
    }
}

void create_normal_rand_nums(double *x, int N, double myu, double sigma) {
    for (int i = 0; i < N; i += 2)
    {
        double r1 = (double)(rand() + 1.0) / (RAND_MAX + 1.0);
        double r2 = (double)(rand() + 1.0) / (RAND_MAX + 1.0);
        double u1 = sqrt(-2.0 * log(r1)) * cos(2.0 * M_PI * r2);
        double u2 = sqrt(-2.0 * log(r1)) * sin(2.0 * M_PI * r2);
        x[i] = myu + sigma * u1;
        x[i + 1] = myu + sigma * u2;
    }
    }



int main(void) {
    FILE *fp;
    // step1
    fp = fopen("yagi_kota_task9_2_bonus.csv", "a");
    int N;
    printf("乱数の生成数Nを整数値で入力してください。--->");
    scanf("%d", &N);
    //step2
    double *x;
    x = (double*)malloc(N * sizeof(double));
    if (x == NULL) {
        printf("メモリが確保できません\n");
        exit(1);
    }
    int i;
    for (i = 0; i <= N; i++) {
        x[i] = 0.0;
    }
    //step3
    srand((unsigned int) time(NULL));
    // srand(123);
    double a;
    double b;
    double u;
    double myu;
    double sigma;
    double r1, r2;
    double u1, u2;
    double x1, x2;

    int choice;
    printf("\n1: 範囲[a, b]の実数型一様乱数の生成\n");
    printf("\n2: 平均myuと標準偏差sigmaの正規乱数の生成\n");
    printf("\n生成する乱数の選択番号を1と2より1つ入力してください--->");
    scanf("%d", &choice);

//自作関数にする
    switch (choice) {
        case 1:
            printf("範囲の下限aを指定してください -->");
            scanf("%lf", &a);
            printf("範囲の上限bを指定してください -->");
            scanf("%lf", &b);

            create_uniform_rand_nums(x, N, a, b);

            break;
        case 2:
            printf("平均myuを指定してください -->");
            scanf("%lf", &myu);
            printf("標準偏差sigmaを指定してください -->");
            scanf("%lf", &sigma);
            if (myu - 3.0 * sigma <= 0) {
                printf("myu - 3.0 * sigma > 0となるようにしてください。\n");
                exit(1);
            }

            create_normal_rand_nums(x, N, myu, sigma);
            break;
        default:
            printf("選択番号に誤りがあります。再度、選択番号を入力し直してください。");
            exit(1);
            break;
        }

        
    double xmax = x[0];
    double xmin = x[0];
    double sum = x[0];
    double avg;
    double ss = pow(x[0], 2.0);
    double vx;
    double sx;
    //合計　最大値　最小値
    for (i = 1; i < N; i++)
    {
        sum += x[i];
        xmax = fmax(xmax, x[i]);
        xmin = fmin(xmin, x[i]);
    }
    //平均
    avg = average(x, N);
    //平方和
    for (i = 1; i < N; i++)
    {
        ss += pow(x[i], 2.0);
    }
    //不偏分散
    vx = variance(x, N);
    //標準偏差
    sx = std_deviation(x, N);

    switch (choice) {
    case 1:
        printf("実数型一様乱数データの統計処理結果\n\n");
        fprintf(fp, "実数型一様乱数データの統計処理結果\n\n");
        printf("データ範囲\ta\tb\n");
        fprintf(fp, "データ範囲,a,b\n");
        printf("\t%.1f\t%.1f\n\n", a, b);
        fprintf(fp, ",%.1f,%.1f\n\n", a, b);
        break;
    case 2:
        printf("正規乱数データの統計処理結果\n\n");
        fprintf(fp, "正規乱数データの統計処理結果\n\n");
        printf("正規分布\t平均\t標準偏差\n");
        fprintf(fp, "正規分布,平均,標準偏差\n");
        printf("真の値\t%f\t%f\n\n", myu, sigma);
        fprintf(fp, "真の値,%f,%f\n\n", myu, sigma);
        break;
    }
    printf("データ数\t%d\n", N);
    printf("データ平均\t%.1f\n", avg);
    printf("データ不偏分散\t%.2f\n", vx);
    printf("データ標準偏差\t%.2f\n", sx);
    printf("データの最大値\t%.1f\n", xmax);
    printf("データの最小値\t%.1f\n", xmin);
    fprintf(fp, "データ数,%d\n", N);
    fprintf(fp, "データ平均,%.1f\n", avg);
    fprintf(fp, "データ不偏分散,%.2f\n", vx);
    fprintf(fp, "データ標準偏差,%.2f\n", sx);
    fprintf(fp, "データの最大値,%.1f\n", xmax);
    fprintf(fp, "データの最小値,%.1f\n", xmin);

    //step 5
    int k;
    printf("級の数kを整数値で指定してください。--->");
    scanf("%d", &k);
    //step 6
    double h;
    h = ceil((xmax - xmin) / (double)k);
    printf("\n級の数\t%d\n", k);
    fprintf(fp, "\n級の数,%d\n", k);
    printf("級の区間幅\t%f\n", h);
    fprintf(fp, "級の区間幅,%f\n", h);
    //step 7
    double w_adj = 0.5;
    //step 8
    double min_x_interval = xmin - w_adj;
    //step 9
    double *x_interval;
    x_interval = (double *)malloc((k + 1) * sizeof(double));
    if (x_interval == NULL) {
        printf("メモリが確保できません\n");
        exit(1);
    }
    for (i = 0; i < k + 1; i++)
    {
        x_interval[i] = 0.0;
    }
    x_interval[0] = min_x_interval;
    for (i = 1; i < k + 1; i++) {
        x_interval[i] = x_interval[i - 1] + h;
    }
    //step 10
    double *x_median;
    x_median = (double *)malloc(k * sizeof(double));
    if (x_median == NULL) {
        printf("メモリが確保できません");
        exit(1);
    }
    for (i = 0; i < k ; i++)
    {
        x_median[i] = 0.0;
    }
    for (i = 0; i < k; i++) {
        x_median[i] = (x_interval[i + 1] + x_interval[i]) / 2.0;
    }
    // step 11
    int *Dosu;
    Dosu = (int *)malloc(k * sizeof(int));
    if (Dosu == NULL) {
        printf("メモリが確保できません。");
    }
    for (i = 0; i < k; i++) {
        Dosu[i] = 0;
    }
    int *Ruiseki_Dosu;
    Ruiseki_Dosu = (int *)malloc(k * sizeof(int));
    if (Ruiseki_Dosu == NULL) {
        printf("メモリが確保できません。");
    }
    for (i = 0; i < k; i++) {
        Ruiseki_Dosu[i] = 0;
    }
    double *Soutai_Dosu;
    Soutai_Dosu = (double *)malloc(k * sizeof(double));
    if (Soutai_Dosu == NULL) {
        printf("メモリが確保できません。");
    }
    for (i = 0; i < k; i++) {
        Soutai_Dosu[i] = 0.0;
    }
    double *Ruiseki_Soutai_Dosu;
    Ruiseki_Soutai_Dosu = (double *)malloc(k * sizeof(double));
    if (Ruiseki_Soutai_Dosu == NULL) {
        printf("メモリが確保できません。");
    }
    for (i = 0; i < k; i++) {
        Ruiseki_Soutai_Dosu[i] = 0.0;
    }

    printf("\nデータ区間\t中央値\t度数\t累積度数\t相対度数\t累積相対度数\n");
    fprintf(fp, "\nデータ区間,中央値,度数,累積度数,相対度数,累積相対度数\n");

    // 自作関数にする
    int j;
    for (i = 0; i < k; i++) {
        for (j = 0; j < N; j++)
        {
            if (x_interval[i] <= x[j] && x[j] < x_interval[i + 1]) {
                Dosu[i]++;
            }
        }
        Soutai_Dosu[i] = Dosu[i] / (double)N;
        if (i == 0) {
            Ruiseki_Dosu[i] = Dosu[i];
        }
        else
        {
            Ruiseki_Dosu[i] = Dosu[i] + Ruiseki_Dosu[i - 1];
        }
        if (i == 0) {
            Ruiseki_Soutai_Dosu[i] = Soutai_Dosu[i];
        }
        else
        {
            Ruiseki_Soutai_Dosu[i] = Soutai_Dosu[i] + Ruiseki_Soutai_Dosu[i - 1];
        }
        printf("%.1f - %.1f\t%.1f\t%d\t%d\t\t%.4f\t\t%.4f\n", x_interval[i], x_interval[i + 1], x_median[i], Dosu[i], Ruiseki_Dosu[i], Soutai_Dosu[i], Ruiseki_Soutai_Dosu[i]);
        fprintf(fp, "%.1f - %.1f,%.1f,%d,%d,%.4f,%.4f\n", x_interval[i], x_interval[i + 1], x_median[i], Dosu[i], Ruiseki_Dosu[i], Soutai_Dosu[i], Ruiseki_Soutai_Dosu[i]);
    }
    printf(",,累計,%d,累計,%f\n\n\n", Ruiseki_Dosu[k-1], Ruiseki_Soutai_Dosu[k-1]);
    fprintf(fp, ",,累計,%d,累計,%f\n\n\n", Ruiseki_Dosu[k-1], Ruiseki_Soutai_Dosu[k-1]);

    fclose(fp);
    free(x);
    free(x_interval);
    free(x_median);
    free(Dosu);
    free(Ruiseki_Dosu);
    free(Ruiseki_Soutai_Dosu);
    return 0;
}