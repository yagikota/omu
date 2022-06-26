#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

int main(void){ 
  int a, i;
  srand((unsigned int)time(NULL));
  for(i = 0; i < 10; i++){
    a = rand();
    printf("%d\n", a); 
    }
  return 0;
}