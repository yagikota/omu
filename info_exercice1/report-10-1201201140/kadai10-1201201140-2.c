// 1201201140
// 八木洸太

#include <stdio.h>

enum DAY {SUN, MON, TUE, WED, THU, FRI, SAT};

void print_sun_time_table() {
	puts("休日");
}

void print_mon_time_table() {
	puts("2: 信号処理論");
	puts("3: ネトワーク工学");
}

void print_tue_time_table() {
	puts("1: オートマトンと形式言語");
	puts("2: 計算機アーキテクチャ");
	puts("3: 情報工学実験1");
	puts("4: 情報工学実験2");
}

void print_wed_time_table() {
	puts("2: プログラミング言語概論");
	puts("3: ソフトウェア工学");
	puts("4: 情報理論");
}

void print_thu_time_table() {
	puts("3: 情報工学演習3");
	puts("4: 情報工学演習1");
}

void print_fri_time_table() {
	puts("4: 環境倫理");
	puts("5: 工学倫理");
}

void print_sat_time_table() {
	puts("休日");
}

int main(void) {
	puts("select a day");
	puts("0: SUN, 1: MON, 2: TUE, 3: WED, 4: THU, 5: FRI, 6: SAT");
	int day;
	scanf("%d", &day);

	switch (day) {
		case SUN:
			print_sun_time_table();
			break;
		case MON:
			print_mon_time_table();
			break;
		case TUE:
			print_tue_time_table();
			break;
		case WED:
			print_wed_time_table();
			break;
		case THU:
			print_thu_time_table();
			break;
		case FRI:
			print_fri_time_table();
			break;
		case SAT:
			print_sat_time_table();
			break;
	}
	return 0;
}