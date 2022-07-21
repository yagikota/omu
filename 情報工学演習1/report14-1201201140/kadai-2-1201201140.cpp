// 第12回 演習課題(2)の解
/*
氏名：八木洸太
学籍番号：1201201140
*/

#include <iostream>	// coutのため
#include <iomanip>	// setwのため
using namespace std;

#define SIZE 9

class kuku_array {
  // write here...
  private:
    int size;

  public:
    int **times_table;

    kuku_array(int _size) {
      size = _size;
      times_table = new int *[_size];
      for (int i = 0; i < _size; i++) {
        times_table[i] = new int[_size];
      } 
    }

    ~kuku_array() {
      if (size != 0) {
        for (int i = 0; i < size; i++) {
          delete[] times_table[i];
        }
        delete[] times_table;
        size = 0;
      }
      cout << "hoge";
    }

    kuku_array(kuku_array &obj) {
      size = obj.size;
      // メモリ確保
      times_table = new int *[size];
      for (int i = 0; i < size; i++) {
        times_table[i] = new int[size];
      } 
      // コピー
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          times_table[i][j] = obj.times_table[i][j];
        }
      }
    }

    void print_table() {
      cout.setf(ios::right, ios::adjustfield);
      cout << " |  1  2  3  4  5  6  7  8  9" << endl;
      cout << "----------------------------" << endl;

      for (int i = 0; i < size; i++) {
        cout << (i + 1) << "|";
        for (int j = 0; j < size; j++) {
          int value = times_table[i][j];
          cout << setw(3) << value;
        }
        cout << endl;
      }
    }
};

int main() {

  // 九九オブジェクトobj1の生成
  // write here...
  kuku_array obj1(SIZE);

  // 九九を計算して、obj1の配列に入れる
  // write here...
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			obj1.times_table[i][j] = (i + 1) * (j + 1);
		}
	}

  // 九九オブジェクトobj2にobj1の中身をコピーする
  // write here...
  kuku_array obj2 = obj1;

  // obj2に保持されている九九を表示する
  // write here...
  obj2.print_table();

  return 0;
}
