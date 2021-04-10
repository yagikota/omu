#include<stdio.h>

int main(void) {
  int i;
  printf("Case of break sentense\n");
  for(i=0; i < 10; i++) {
    if(i == 5) {
      break;
    }
    printf("i = %d\n", i);
  }

  printf("Case of continue sentense\n");
  for(i=0; i < 10; i++) {
    if(i == 5) {
      continue;
    }
    printf("i = %d\n", i);
  }

}