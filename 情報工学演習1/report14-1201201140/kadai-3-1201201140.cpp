// 第12回 演習課題(3)
/*
氏名：八木洸太
学籍番号：1201201140
*/

#include <iostream>
#include <stdlib.h> // rand関数のため
#include <time.h>
#include <math.h>

using namespace std;

class random_number {
  // write here...
  public:
    double value;

    random_number(double min ,double max) {
      double offset = ((double)rand() / RAND_MAX) * (max - min);
      value = min + offset;
    }
};

// 2x2の正方形と直径2の円を考える。円の中心は原点とする。
int main() {
  // write here...
  cout << "n(the number of random integer): ";
  int n = 0;
  cin >> n;

  if (n < 0) {
    cout << "n must be positive integer" << endl;
    exit(1);
  }

  srand((unsigned int)time(NULL));
  int inside = 0;
  for (int i = 0; i < n; i++) {
    random_number x(-1.0, 1.0);
    random_number y(-1.0, 1.0);
    double d = pow(x.value, 2.0) + pow(y.value, 2.0);
    if (d < 1.0) {
      inside++;
    }
  }

  double pi = 4.0 * inside / (double)n;

  cout << "pi = " << pi << endl;

  return 0;
}
