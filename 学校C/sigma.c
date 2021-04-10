// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>

int main(void) {
  // while文
  int i, j;
  i = 1;

  while(i < 101) {
    j = i*i;
    printf("%d^2 = %d\n", i, j);
    i++;
  }

  // // for文
  // int i;

  // for(i=1; i < 101; i++) {
  //   printf("%d^2 = %d\n", i, i*i);
  // }

  return 0;
}