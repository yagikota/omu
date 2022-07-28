// 1201201140
// 八木洸太

#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

double gen_rand_num(double min, double max) {
    double offset = ((double)rand() / RAND_MAX) * (max - min);
    return min + offset;
}

int main(int argc, char *argv[]) {
    int M = atoi(argv[1]);
    int seed = atoi(argv[2]);

    // 乱数の種の生成
    srand(seed);

    // 球体内にできた点の数
    int inside = 0;

    for (int i = 0; i < M; i++) {
        double x = gen_rand_num(0, 1);
        double y = gen_rand_num(0, 1);
        double z = gen_rand_num(0, 1);
        double d = pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0);
        if (d < 1.0) {
            inside++;
        }
    }

    double pi = 6.0 * inside / (double)M;
    cout << pi << endl;
}

// 講義や課題に関するコメント
// 球体でなく円でモンテカルロ法をした方が簡単だと思った