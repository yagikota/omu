// 学籍番号:１２０１２０１１４０
// 名前：八木洸太

#include <stdio.h>

int main(void) {
  int a, b;
  int sum;
  puts("二つの正の整数を入力してください。（ただし、A < B）");
  printf("A : ");
  scanf("%d",&a);
  printf("B : ");
  scanf("%d",&b);

  sum = (a + b)*(b - a + 1) / 2;
  printf("AからBまでの整数の合計は%d\n", sum);
}