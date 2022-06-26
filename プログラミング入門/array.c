#include<stdio.h>

int main(void) {
    int i;
    int a[5] = {1, 2, 5, 10, -3};

    for (i = 0; i < 5; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    return 0;
}