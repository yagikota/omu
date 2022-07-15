// 第11回 演習課題(1)
/*
氏名：八木洸太
学籍番号：1201201140
*/

// ヘッダファイルなどを記述
#include<string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>
using namespace std;

// クラスの定義
class Score {
  // write here...
  private:
    string name;
    int score_math;
    int score_english;
    int score_science;

  public:
    Score(string _name, int _math, int _eng, int _sci) {
      name = _name;
      score_math = _math;
      score_english = _eng;
      score_science = _sci;
    }

    string get_name() {
      return name;
    }

    double get_scores_avg() {
      return (score_math + score_english + score_science) / 3.0;
    }
};

int main() {

  // ファイルを開く
  // write here...
  ifstream fin("./kadai-1_score.txt");
  if (!fin) {
    cout << "Cannot open input file." << endl;
    exit(0);
  }

  // データの読み込みとクラスへの登録
  // write here...
  vector<Score> scores;
  string line;
  while (getline(fin, line)) {
    stringstream ss_line(line);
    std::vector<std::string> data;
    string tok;
    while (getline(ss_line, tok, ' ')) {
        data.push_back(tok);
    }

    string name = data[0];
    int score_math = stoi(data[1]);
    int score_english = stoi(data[2]);
    int score_science = stoi(data[3]);
    Score s(name, score_math, score_english, score_science);
    scores.push_back(s);
  }

    // 人毎に平均点の算出と表示
    // The average score of (人名): (点数） で出力する．
    /*
    想定する出力：
    The average score of Suzuki: 70
    The average score of Takeda: 80
    The average score of Yamada: 63.3333
    */
    // write here...
  for (int i = 0; i < scores.size(); i++) {
    Score s = scores[i];
    cout << "The average score of " << s.get_name() << " " <<  s.get_scores_avg() << endl;
  }
    return 0;
}
