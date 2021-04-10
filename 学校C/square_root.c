#include<stdio.h>
#include<math.h>

int main(void) {
  float a, b;
  printf("Input a number:");
  scanf("%f", &a);
  b = sqrt(a);
  printf("sqrt of %f = %f\n", a, b);
  return 0;
}

