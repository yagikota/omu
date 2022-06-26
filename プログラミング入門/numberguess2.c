// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main(void) {
  int i, correct_num, j;
  j = 0;

  srand((unsigned int)time(NULL));
  correct_num = rand() % 11;//0~10の乱数生成

  while(1) {
    printf("0以上10以下の整数を入力してください。 ： ");
    scanf("%d", &i);

    if(i < 0 || i > 10) {
      j++;
      printf("Type Error\n");
      continue;
    }else {
      if(i < correct_num) {
        j++;
        printf("不正解。正解値は%dより大きいです。\n", i);
        continue;
      }else {
        if(i > correct_num) {
          j++;
           printf("不正解。正解値は%dより小さいです。\n", i);
           continue;
        }else {
          j++;
          if (i == correct_num) {
            printf("正解。\n");
            printf("正解までにかかった回数は%d回。\n", j);
            break;
          }
        }
      }
    }
  }

  return 0;
}