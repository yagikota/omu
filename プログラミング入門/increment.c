#include<stdio.h>

int main(void) {
  int i, j;
  i = 3;
  j = 12;
  printf("1: i = %d, j = %d\n", i, j);//3, 12
  i++;
   printf("2: i = %d, j = %d\n", i, j);//4, 12
  ++i;
  printf("3: i = %d, j = %d\n", i, j);//5, 12
  j = j + i++;
  // j = j + iを実行してからi ++を実行
  printf("4: i = %d, j = %d\n", i, j);//6, 17
  j = j + ++i;
  // ++iを実行してからj = j+ iを実行
  printf("5: i = %d, j = %d\n", i, j);//7, 24

  return 0;
}