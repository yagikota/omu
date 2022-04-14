// 学籍番号：1201201140
//ポータルID：seb01140
// 指名：八木洸太
//プログラム名：yagi_kota_task10.c

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


int main(void)
{
    FILE *fp;
    fp = fopen("yagi_kota_task10.csv", "w");

    double lambda;//客の平均到着率
    printf("客の平均到着率 = ");
    scanf("%lf", &lambda);
    double micro;//窓口の平均サービス率
    printf("ATM1台あたりの平均サービス率 = ");
    scanf("%lf", &micro);
    int s;//ATM設置台数s
    printf("ATM設置台数s = ");
    scanf("%d", &s);
    double T;//シミュレーション時間
    printf("シミュレーション時間 = ");
    scanf("%lf", &T);
    double delta_t;//シミュレーション時間の刻み
    printf("シミュレーション時間の刻み = ");
    scanf("%lf", &delta_t);

    printf("客の平均到着率lambda = %f\n", lambda);
    fprintf(fp, "客の平均到着率lambda = %f\n", lambda);
    printf("ATM1台あたりの平均サービス率micro = %f\n", micro);
    fprintf(fp, "ATM1台あたりの平均サービス率micro = %f\n", micro);
    printf("ATM設置台数s = %d\n", s);
    fprintf(fp, "ATM設置台数s = %d\n", s);

    int q = 0;//客の到着の有無を判定, 無到着(q = 0)で初期化
    int sum_q = 0;//客の到着人数
    double u, ca, ca_time;
    srand((unsigned int)time(NULL));
    u = ((double)rand() + 1.0) / ((double)RAND_MAX + 1.0);
    ca = (-1.0 / lambda) * log(u);//平均発生率が1/lambdaの場合の事象の発生時間間隔（指数乱数）
    ca_time = ca;//最初の客の到着時間

    //ATM初期化
    int *atm_available;
    atm_available = (int *)malloc((s + 1) * sizeof(int));
    int window;
    for (window = 0; window <= s; window++)
    {
        atm_available[window] = 0;//空き
    }

    int sq = 0;// 客のサービス窓口割り当て有無を判定, 無(sq = 0)

    double st_window;//客が割り当てられた各ATMのサービス時間格納
    double *stime;//客が割り当てられた各ATMのサービス終了時間
    stime = (double *)malloc((s + 1) * sizeof(double));
    for (window = 0; window <= s; window++)
    {
        stime[window] = 0.0;
    }

    int fsq;//サービスが終了した客の人数をカウント

    double t; //現在のシミュレーション時間
    // シミュレーション
    for (t = 0.0; t <= T; t += delta_t)
    {
        //客の到着を確認
        if (ca_time <= t)
        {
            q = 1;
            sum_q += 1;
            u = ((double)rand() + 1.0) / ((double)RAND_MAX + 1.0);
            ca = (-1.0 / lambda) * log(u);
            ca_time = ca + t;
        }

        // 全ATMの空き状況を確認
        for (window = 1; window <=s; window++)
        {
            // 客がいる
            if (q == 1)
            {
                //ATMが空いている
                if (atm_available[window] == 0)
                {
                    atm_available[window] = 1;
                    q = 0;
                    sq = 1;
                    u = ((double)rand() + 1) / ((double)RAND_MAX + 1);
                    st_window = (-1.0 / micro) * log(u);
                    stime[window] = st_window + t;
                }
            }
        }

        //全ATMについて調べる
        for (window = 1; window <= s; window++)
        {
            //客が窓口に割り当てられている
            if (sq == 1)
            {
                //窓口がサービスを終了している
                if (stime[window] <= t + delta_t)
                {
                    atm_available[window] = 0;
                    stime[window] = 0.0;
                    sq = 0;
                    fsq += 1;
                }
            }
        }
    }

    double act_ro;//到着客に対するサービス率
    act_ro = (double)fsq / (double)sum_q;

    printf("シミュレーション時間T = %fまでの客の到着総数sum_q = %d\n", T, sum_q);
    fprintf(fp, "シミュレーション時間T = %fまでの客の到着総数sum_q = %d\n", T, sum_q);
    printf("シミュレーション時間T = %fまでのATM設置台数%d台でサービスを終了した客の総数fsq = %d\n", T, s, fsq);
    fprintf(fp, "シミュレーション時間T = %fまでのATM設置台数%d台でサービスを終了した客の総数fsq = %d\n", T, s, fsq);
    printf("到着客に対するサービス率act_ro = %f\n", act_ro);
    fprintf(fp, "到着客に対するサービス率act_ro = %f\n", act_ro);

    fclose(fp);
    free(atm_available);
    free(stime);
    return 0;
}