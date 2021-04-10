#include <stdio.h> 
#include <math.h>

int main(void){
float a, s, c, t;
printf("Input an angle:");
scanf("%f", &a);
s = sin(a);
c = cos(a);
t = tan(a);
printf("sin(a): %f, cos(a): %f, tan(a): %f", s, c, t); 
return 0;
}