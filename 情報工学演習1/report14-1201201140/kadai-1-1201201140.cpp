// 第12回 演習課題(1)
/*
氏名：八木洸太
学籍番号：1201201140
*/

#include <iostream>
#include <time.h>
using namespace std;

#define H 3600
#define M 60

// 時を表すクラス
class time_hms { 
// write here...
  private:
    int hour;
    int min;
    int sec;

  public:
    time_hms(int _hour, int _min, int _sec) {
      hour = _hour;
      min = _min;
      sec = _sec;
    }

    int get_curr_hour() {
      return hour;
    }

    int get_curr_min() {
      return min;
    }

    int get_curr_sec() {
      return sec;
    }

    void sum_time(time_hms &other_time) {
      int total_sec = 0;
      total_sec += (hour + other_time.hour) * H;
      total_sec += (min + other_time.min) * M;
      total_sec += (sec + other_time.sec);

      hour = total_sec / H;
      total_sec %= H;
      min = total_sec / M;
      total_sec %= M;
      sec = total_sec;
    }
};

void print_time(time_hms t) {
  int curr_h = t.get_curr_hour();
  int curr_m = t.get_curr_min();
  int curr_s = t.get_curr_sec();
  cout << curr_h << ":" << curr_m << ":" << curr_s << endl;
}

int main() {
  // write here...
  time_t raw_time;
  struct tm * time_info;

  time (&raw_time);
  time_info = localtime (&raw_time);

  int curr_h = time_info->tm_hour;
  int curr_m = time_info->tm_min;
  int curr_s = time_info->tm_sec;

  time_hms t1(curr_h, curr_m, curr_s);

  cout << "time1: ";
  print_time(t1);

  time_hms t2(3, 35, 40);
  cout << "time2: ";
  print_time(t2);


  t1.sum_time(t2);
  cout << "time1(time2 is added): ";
  print_time(t1);

  return 0;
}

