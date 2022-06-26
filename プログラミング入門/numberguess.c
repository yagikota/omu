// 学籍番号:1201201140
// 名前：八木洸太


#include<stdio.h>

int main(void) {
  int i, correct_num;
  correct_num = 8;

  while(1) {
    printf("0以上10以下の整数を入力してください。\n ： ");
    scanf("%d", &i);

    if(i < 0 || i > 10) {
      printf("Type Error\n");
      continue;
    }else {
      if(i < correct_num) {
        printf("不正解。正解値は%dより大きいです。\n", i);
        continue;
      }else {
        if(i > correct_num) {
           printf("不正解。正解値は%dより小さいです。\n", i);
           continue;
        }else {
          if (i == correct_num) {
            printf("正解。\n");
            break;
          }
        }
      }
    }
  }

  return 0;
}