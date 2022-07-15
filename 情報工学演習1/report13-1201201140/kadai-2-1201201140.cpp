// 第11回 演習課題(2)
/*
氏名：八木洸太
学籍番号：1201201140
*/

// ヘッダファイルなどを記述
#include <string>
#include <iostream>
#include <map>
using namespace std;

// クラスの定義
class Coordinate { // 座標を扱うクラス
  // write here...
  private:
    int x;
    int y;

  public:
    Coordinate(int _x, int _y) {
      x = _x;
      y = _y;
    }

    void move_up() {
      y++;
    }

    void move_down() {
      y--;
    }

    void move_right() {
      x++;
    }

    void move_left() {
      x--;
    }

    void show_position() {
      cout << "The current position is (" << x << ", " << y << ")" << endl;
    }
};

enum command {
  einvalid, // 0
  eup,
  edown,
  eleft,
  eright,
  eshow,
  equit,
};

int main() {
  // write here...
  map<string, int> command_map;
  command_map["up"] = eup;
  command_map["down"] = edown;
  command_map["left"] = eleft;
  command_map["right"] =  eright;
  command_map["show"] =  eshow;
  command_map["quit"] =  equit;

  Coordinate coordinate(0, 0);

  while (1) {
    cout << "Enter a command (up, down, left, right, show or quit): ";
    string command;
    cin >> command;

    switch (command_map[command]) {
      case eup:
        coordinate.move_up();
        break;
      case edown:
        coordinate.move_down();
        break;
      case eleft:
        coordinate.move_left();
        break;
      case eright:
        coordinate.move_right();
        break;
      case eshow:
        coordinate.show_position();
        break;
      case equit:
        goto quit_program;
      default:
        cout << "Invalid command" << endl;
      }
  }
  quit_program:
    cout << "Quit program" << endl;

    return 0;
  }
