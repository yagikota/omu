/*
氏名：八木洸太
学籍番号：1201201140
*/

#include <stdio.h>
#include <stdlib.h>

#include "kadai15_1201201140.h"

void Poker::input_cards() { // 引くカードを入力
    for (int i = 0; i < 5; i++)
    {
        printf("%d番目のカードを入力して下さい (マーク, 数字)\n", (i + 1));
        scanf(" %c, %d", &mark[i], &number[i]);

        if (mark[i] != 'S' && mark[i] != 'H' && mark[i] != 'D' && mark[i] != 'C')
        {
            printf("入力したマークは無効です\n");
            exit(1);
        }

        if (number[i] < 1 || number[i] > 13)
        {
            printf("入力した数字は無効です\n");
            exit(1);
        }
    }

    return;
} // void input_cards()

void Poker::print_cards()
{ // 引いたカードを表示

    for (int i = 0; i < 5; i++)
    {
        printf("-%d-  ", (i + 1));
    }
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%c", mark[i]);
        printf("%2d  ", number[i]);
    }
    printf("\n");

    return;
} // void print_cards()

int Poker::flush() { // フラッシュ判定 return 1:フラッシュ return 0:フラッシュでない
    for (int i = 0; i < 4; i++) {
        if (mark[i] != mark[i+1]) {
            return 0;
        }
    }
    return 1;
}

int Poker::straight() { // ストレート判定 return 1:ストレート return 0:ストレートでない
    // 10-11-12-13-1の場合
    if ((number[0] == 1) && (number[1] == 10) && (number[2] == 11) && (number[3] == 12) && (number[4] == 13)) {
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        if (number[i] != number[i+1] - 1) {
            return 0;
        }
    }

    return 1;
}

int Poker::pair()
{ // 同一数字に関係するハンドを判定
    // return 1:ワンペア 2:ツーペア 3:スリーカード 4:フルハウス 5:フォーカード 0:該当なし

    // 5:フォーカード
    for (int i = 0; i < 2; i++)
    {
        // 数字がソートされているためnumber[0]またはnumber[4]のみの数字が異なる
        if (number[i] == number[i + 3])
        {
            return 5;
        }
    }

    // 4:フルハウス
    // フルハウスに該当する場合，4を返すよう(return 4)プログラムを作成
    if ((number[0] == number[1] && number[2] == number[4]) || (number[0] == number[2] && number[3] == number[4])) {
        return 4;
    }

    // 3:スリーカード
    for (int i = 0; i < 3; i++)
    {
        if (number[i] == number[i + 2])
        {
            return 3;
        }
    }

    // 2:ツーペア
    // ツーペアに該当する場合，2を返すよう(return 2)プログラムを作成
    int count_pair = 0;
    for (int i = 0; i < 4; i++) {
        if (mark[i] == mark[i+1] && number[i] == number[i+1]) {
            count_pair++;
        }
    }

    if (count_pair == 2) {
        return 2;
    }

    // 1:ワンペア
    // ワンペアに該当する場合，1を返すよう(return 1)プログラムを作成¥
    for (int i = 0; i < 4; i++) {
        if (mark[i] == mark[i+1] && number[i] == number[i+1]) {
            return 1;
        }
    }

    return 0;
} // int pair()


int Poker::exodia() {
    if ((number[0] != 5) || (number[1] != 5) || (number[2] != 5) || (number[3] != 5) || (number[4] != 13)) {
        return 0;
    }
    return 1;
}

int Poker::decision()
{ // ハンドを判定

    int decision1, decision2, tmp;

    // 数が小さい順に並べ替え
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (number[i] > number[j])
            {
                tmp = number[i];
                number[i] = number[j];
                number[j] = tmp;
            }
        }
    }

    decision1 = flush();
    decision2 = straight();

    if (decision1 == 1 && decision2 == 1)
    {
        if ((number[0] == 1) && (number[1] == 10))
        { // 左のif文に論理を追加せよ
            printf("ロイヤルストレートフラッシュ\n");
            return 10;
        }
        else
        {
            printf("ストレートフラッシュ\n");
            return 9;
        }
    }
    else if (decision1 == 1)
    {
        printf("フラッシュ\n");
        return 6;
    }
    else if (decision2 == 1)
    {
        printf("ストレート\n");
        return 5;
    }

    decision1 = pair();

    if (decision1 == 5)
    {
        if (exodia() == 1) {
            printf("エグゾディア\n");
            return -1;
        }
        printf("フォーカード\n");
        return 8;
    }
    else if (decision1 == 4)
    {
        printf("フルハウス\n");
        return 7;
    }
    else if (decision1 == 3)
    {
        printf("スリーカード\n");
        return 4;
    }
    else if (decision1 == 2)
    {
        printf("ツーペア\n");
        return 3;
    }
    else if (decision1 == 1)
    {
        printf("ワンペア\n");
        return 1;
    }
    else if (decision1 == 0)
    {
        printf("残念でした…\n");
    }

    return 0;
} // int decision()

int main()
{

    Poker poker;

    poker.input_cards();

    poker.print_cards();

    int dummy_decision = poker.decision();

    return 0;
}
