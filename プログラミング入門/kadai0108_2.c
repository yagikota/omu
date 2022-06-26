// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main(void) {
	int stones;//石の数
	int your_take;//ユーザが取る石の数
	int cmp_take;//コンピュータが取る石の数

	//勝敗の決定で用いる
	//ユーザ、コンピュータが石を取ったらcheckを1インクリメントする。
	//checkが偶数ならユーザの勝ち、奇数ならコンピュータの勝ち
	int check = 0;

	printf("Please type in the number of stone over 1.\n");
	scanf("%d", &stones);
	printf("Stone number : %d\n", stones);

	while(stones > 0) {
		//user's turn
		printf("Your turn. Please type in the number from 1 to 3.\n");
		scanf("%d", &your_take);
		stones -= your_take;
		check += 1;
		printf("Stone number : %d\n", stones);

		//computer's turn
		if (stones > 0) {
			if (stones > 2) {
			srand((unsigned int)time(NULL));
			cmp_take = rand() % 3 + 1;
			stones -= cmp_take;
			} else if (stones == 2){
				srand((unsigned int)time(NULL));
				cmp_take = rand() % 2 + 1;
				stones -= cmp_take;
			} else {
				cmp_take = 1;
				stones -= cmp_take;
			}
			check += 1;
			printf("Computer take %d stone.\n", cmp_take);
			printf("Stone number : %d\n", stones);
		}
	}

	puts("Number of Stone is 0.");
	//勝敗の決定
	if (check % 2 == 0) {
		puts("You Win!");
		puts("Congraturations!");
	} else {
		puts("You lose!");
		puts("Game over!");
	}

	return 0;
}