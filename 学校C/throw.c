// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include<math.h>

int main(void) {
  float V, A, L, g, pi;
  float s, c;
  g = 9.8;
  pi = 3.141592;

  printf("初速V = ");
  scanf("%f",&V);
  printf("角度A = ");
  scanf("%f", &A);
  s = sin(A*pi/180);
  c = cos(A*pi/180);
  L = 2*V*V*s*c/g;
  printf("落下地点までの距離L = %f(m)", L);

  return 0;
}

