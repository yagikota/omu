// 学籍番号:１２０１２０１１４０
// 名前：八木洸太

#include<stdio.h>

int main(void) {
  int n1, n2;
  printf("Type an integer not smaller than 1 : ");
  scanf("%d",&n1);
  printf("Type an integer not smaller than 1 : ");
  scanf("%d",&n2);

  printf("和 : %d\n", n1 + n2);
  printf("差 : %d\n",n1 - n2);
  printf("積 : %d\n",n1 * n2);
  printf("商 : %d\n",n1 / n2);
  printf("剰余 : %d\n",n1 % n2);

  return 0;
}