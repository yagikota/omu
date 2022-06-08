// 1201201140
// 八木洸太

#include <stdio.h>
#include <string.h>
#define MAX_DB_SIZE 100


typedef struct student {
	char id[10];
	char family_name[10];
	char first_name[10];
	char date_of_birth[8];
	char phone_number[11];
} Student;

int search_student(Student s_list[MAX_DB_SIZE], char *search_word) {
	for (int i = 0; i < MAX_DB_SIZE; i++) {
		char id = s_list[i].id;
		char family_name = s_list[i].family_name;
		char first_name = s_list[i].first_name;
		char date_of_birth = s_list[i].date_of_birth;
		char phone_num = s_list[i].phone_number;
		if (strcmp(search_word, id) == 0 || strcmp(search_word, family_name) == 0 || strcmp(search_word, first_name) == 0 || strcmp(search_word, date_of_birth) == 0 || strcmp(search_word, phone_num) == 0) {
			return i;
		}
	}
	return -1;
}

int search_student_id(Student s_list[MAX_DB_SIZE], char *search_id) {
	for (int i = 0; i < MAX_DB_SIZE; i++) {
		char id = s_list[i].id;
		if (strcmp(search_id, id) == 0) {
			return i;
		}
	}
	return -1;
}

void delete_student(Student s_list[MAX_DB_SIZE], int idx) {
	for (int i = idx; i < MAX_DB_SIZE; i++) {
		s_list[i] = s_list[i + 1];
	}
}

int main(void) {
	// 初期データの登録
	FILE *fp;

	if ((fp = fopen("meibo.txt", "r")) == NULL) {
		printf("Cannot open file you specified\n");
	} else {
		printf("specified file opened!\n");
	}

	Student s_list[MAX_DB_SIZE];
	int k = 0;
	while (fscanf(fp, "%s %s %s %s %s", s_list[k].id, s_list[k].family_name, s_list[k].first_name, s_list[k].date_of_birth, s_list[k].phone_number) != EOF) {
		printf("%s, %s, %s, %s, %s", s_list[k].id, s_list[k].family_name, s_list[k].first_name, s_list[k].date_of_birth, s_list[k].phone_number);
		puts("");
		k++;
	}
	printf("\n%s", s_list[0].date_of_birth);

	int menu = 0;
	int curr_db_size;
	Student new_s;
	char delete_id[10];
	char search_word[10];
	while (1)
	{
		printf("メニュー\n");
		printf("1: 新たに学生を登録\n");
		printf("2: 削除\n");
		printf("3: 検索\n");
		scanf("%d%*c", &menu);

		switch (menu)
		{
		case 1:
			// TODO: 関数化
			printf("学籍番号(ex: 123456789): ");
			scanf("%s%*c", &new_s.id);
			printf("名字(ex: Fudai): ");
			scanf("%s%*c", &new_s.family_name);
			printf("名前(ex: Taro): ");
			scanf("%s%*c", &new_s.first_name);
			printf("生年月日(ex: 20000101): ");
			scanf("%s%*c", &new_s.date_of_birth);
			printf("電話番号(ex: 09028283828): ");
			scanf("%s%*c", &new_s.phone_number);
			s_list[curr_db_size] = new_s;

		case 2:
			printf("削除する学生の学籍番号を入力してください: ");
			scanf("%s", &delete_id);
			int delete_idx = search_student_id(s_list, delete_id);
			if (delete_idx == -1) {
				printf("該当する学生なし");
			} else {
				// 削除処理
				delete_student(s_list, delete_idx);
			}

		case 3:
			printf("検索したい学生の学籍番号，名字，名前，生年月日，電話番号のいずれかを以下の書式で入力してください．");
			printf("学籍番号(ex: 123456789)\n");
			printf("名字(ex: Fudai)\n");
			printf("名前(ex: Taro)\n");
			printf("生年月日(ex: 20000101)\n");
			printf("電話番号(ex: 09028283828)\n");
			scanf("検索ワード: %s", search_word);

			printf("%s", search_word);
			int idx = search_student(s_list, search_word);
			if (idx == -1) {
				printf("検索結果なし\n");
			} else {
			printf("検索結果\n");
			printf("学籍番号: %s\n", s_list[idx].id);
			printf("名字: %s\n", s_list[idx].family_name);
			printf("名前:%s\n", s_list[idx].first_name);
			printf("生年月日: %s\n", s_list[idx].date_of_birth);
			printf("電話番号: %s\n", s_list[idx].phone_number);
			}
		default:
			printf("不正な入力");
		}
	}

	return 0;
}