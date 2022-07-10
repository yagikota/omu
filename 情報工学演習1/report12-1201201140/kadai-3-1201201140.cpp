// 演習課題(3)
/*
氏名：八木洸太
学籍番号：1201201140
*/

#include <iostream>
using namespace std;

//
// 出力は，以下の形式で完全数のみ表示する．
//
// （完全数と判定した数字） is a perfect number.
// 

// return 1 if n is a perfect number, otherwise 0.
int is_perfect_num(int n) {
	int total = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			total += i;
		}
	}

	if (n == total) {
		return 1;
	}

	return 0;
}

// write here...
int main() {
	for (int i = 1; i <= 100; i++) {
		if (is_perfect_num(i) == 1) {
			cout << i << " is a perfect number." << endl;
		}
	}

	return 0;
}
