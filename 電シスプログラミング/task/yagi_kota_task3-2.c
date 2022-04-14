#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MaxN 100


// 平均値を求める関数
double average(double *data, int n) {
    double total = 0;
    double average;
    for (int i = 0; i < n; i++) {
        total += data[i];
    }

    return total / n;
}

//平均値を上回った全体割合を求める関数
double rate_over_average(double *data, int n) {
    int j = 0;
    double average_data = average(data, n);

    for (int i = 0; i < n; i++) {
        if (data[i] > average_data) {
            j++;
        }
    }

    return j * 100.0 / n;
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

//痩せすぎ判定
double rate_of_underweight(double *data, int n, double max) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] < max) {
            count++;
        }
    }

    return count * 100.0 / n;
}

//美容体型判定
double rate_of_beauty(double *data, int n, double min, double max) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (min <= data[i] && data[i] < max) {
            count++;
        }
    }

    return count * 100.0 / n;
}

//適正体型判定
double rate_of_normal(double *data, int n, double min, double max) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (min <= data[i] && data[i] < max) {
            count++;
        }
    }

    return count * 100.0 / n;
}

//太り気味判定
double rate_of_overweight(double *data, int n, double min, double max) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (min <= data[i] && data[i] < max) {
            count++;
        }
    }

    return count * 100.0 / n;
}

//太りすぎ判定
double rate_of_obese(double *data, int n, double min) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (min <= data[i]) {
            count++;
        }
    }

    return count * 100.0 / n;
}


int main(void) {
    FILE *fp1;
    FILE *fp2;
    fp1 = fopen("healthdata.csv", "r");
    fp2 = fopen("yagi_kota_task3-2.csv", "w");
    double height[MaxN] = {0.0};
    double weight[MaxN] = {0.0};
    double bmi[MaxN] = {0.0};
    int i = 0;
    int N;
    double avg_height, std_deviation_height, rate_over_average_height;
    double avg_weight, std_deviation_weight, rate_over_average_weight;
    double avg_mbi, std_deviation_bmi, rate_over_average_bmi;
    double underweight, beauty, normal, overweight, obese;
    double num1 = 18.5;
    double num2 = 20.0;
    double num3 = 25.0;
    double num4 = 30.0;

    printf("検査No\t\t身長\t体重\tBMI\n");
    fprintf(fp2, "検査No,身長,体重,BMI\n");

    while (fscanf(fp1, "%lf,%lf", &height[i], &weight[i]) != EOF) {
        bmi[i] = weight[i] / pow(height[i] / 100, 2);
        printf("%d\t%f\t%f\t%f\n", i + 1, height[i], weight[i], bmi[i]);
        fprintf(fp2, "%d,%f,%f,%f\n", i+1, height[i], weight[i], bmi[i]);
        i++;
    }

    N = i;
    avg_height = average(height, N);
    std_deviation_height = std_deviation(height, N);
    rate_over_average_height = rate_over_average(height, N);

    avg_weight = average(weight, N);
    std_deviation_weight = std_deviation(weight, N);
    rate_over_average_weight = rate_over_average(weight, N);

    avg_mbi = average(bmi, N);
    std_deviation_bmi = std_deviation(bmi, N);
    rate_over_average_bmi = rate_over_average(bmi, N);

    underweight = rate_of_underweight(bmi, N, num1);
    beauty = rate_of_beauty(bmi, N, num1, num2);
    normal = rate_of_normal(bmi, N, num2, num3);
    overweight = rate_of_overweight(bmi, N, num3, num4);
    obese = rate_of_obese(bmi, N, num4);

    printf("データ読込件数\t%d\t%d\t%d\n", N, N, N);
    fprintf(fp2, "データ読込件数,%d,%d,%d\n", N, N, N);

    printf("平均値\t%.2f\t%.2f\t%.2f\n", avg_height, avg_weight, avg_mbi);
    fprintf(fp2, "平均値,%.2f,%.2f,%.2f\n", avg_height, avg_weight, avg_mbi);

    printf("標準偏差\t%.2f\t%.2f\t%.2f\n", std_deviation_height, std_deviation_weight, std_deviation_bmi);
    fprintf(fp2, "標準偏差,%.2f,%.2f,%.2f\n", std_deviation_height, std_deviation_weight, std_deviation_bmi);

    printf("平均値を上回った全体割合(％)\t%.2f\t%.2f\t%.2f\n", rate_over_average_height, rate_over_average_weight, rate_over_average_bmi);
    fprintf(fp2, "平均値を上回った全体割合(％),%.2f,%.2f,%.2f\n", rate_over_average_height, rate_over_average_weight, rate_over_average_bmi);

    printf("痩せすぎの全体割合(％)\t\t\t%.2f\n", underweight);
    fprintf(fp2, "痩せすぎの全体割合(％), , ,%.2f\n", underweight);

    printf("美容体格全体割合(％)\t\t\t%.2f\n", beauty);
    fprintf(fp2, "美容体格全体割合(％), , ,%.2f\n", beauty);

    printf("適正体格全体割合(％)\t\t\t%.2f\n", normal);
    fprintf(fp2, "適正体格全体割合(％), , ,%.2f\n", normal);

    printf("太り気味全体割合(％)\t\t\t%.2f\n", overweight);
    fprintf(fp2, "太り気味全体割合(％), , ,%.2f\n", underweight);

    printf("太りすぎ全体割合(％)\t\t\t%.2f\n", obese);
    fprintf(fp2, "太りすぎ全体割合(％), , ,%.2f\n", obese);

    printf("割合の合計(％)\t\t\t100.00\n");
    fprintf(fp2, "割合の合計(％), , ,100.00\n");

    fclose(fp1);
    fclose(fp2);
    return 0;
}