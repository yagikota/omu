// 1201201140
// 八木洸太

#include<stdio.h>

#define PAYMENT 1000

typedef struct change {
	int coin_500;
	int coin_100;
	int coin_50;
	int coin_10;
} Change;

void count_change(Change *change, int curr_change) {
	while (curr_change > 0) {
		if (curr_change >= 500) {
			curr_change -= 500;
			change->coin_500 += 1;
		} else if (curr_change >= 100) {
			curr_change -= 100;
			change->coin_100 += 1;
		} else if (curr_change >= 50) {
			curr_change -= 50;
			change->coin_50 += 1;
		} else if (curr_change >= 10) {
			curr_change -= 10;
			change->coin_10 += 1;
		}
	}
}

int main(void) {
	puts("1000円の入金を確認しました．");
	puts("購入する券の金額を入力してください");
	int amount;
	scanf("%d", &amount);

	Change change = {0, 0, 0, 0};
	count_change(&change, PAYMENT - amount);
	puts("お釣り");
	printf("500円: %d枚, 100円: %d枚, 50円: %d枚, 10円: %d枚\n", change.coin_500, change.coin_100, change.coin_50, change.coin_10);

	return 0;
}
