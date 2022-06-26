// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>

int main(void) {
    int dp, bp, money_in_hand, dp_tax, bp_tax, change;

    dp = 128;
    bp = 116;
    money_in_hand = 1000;

    dp_tax = dp * 1.1;
    bp_tax = bp * 1.1;
    change = money_in_hand - (dp_tax * 2 + bp_tax);

    printf("お釣り : %d 円\n", change);
    return 0;
}

// 1.1 
// -> float tax = 1.1
