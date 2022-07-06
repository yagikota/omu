// 1201201140
// 八木洸太

#include <stdio.h>

#define N 5

typedef struct laboratory {
	int id; // 研究室番号
	int wanted_student_ids[N]; // 研究室側の配属者順位(降順)
	int curr_student_ids[N]; // 仮配属されている学生の学籍番号
	int curr_student_num; // 仮配属されている学生の人数
	int is_full; // 配属者がいるかどうかのテータス(0: いない, 1: いる)
} Lab;

typedef struct student {
	int id; // 学籍番号
	int wanted_lab_ids[N]; // 希望の研究室番号(希望順)
	int have_decided_lab; // 内定しているかdどうかのステータス(0: 内定していない, 1: 内定している)
} Student;

// 仮配属の処理
void append(Lab *lab, Student s) {
	lab->curr_student_ids[lab->curr_student_num] = s.id;
	lab->curr_student_num++;
}

// 仮配属の人数が2人以上の場合, 研究室が用意してある配属者順位に基づき, 仮配属の人数を1人にする
void delete(Lab *lab, int idx) {
	for (int i = idx; i < lab->curr_student_num-1; i++) {
		lab->curr_student_ids[i] = lab->curr_student_ids[i + 1];
	}
	lab->curr_student_num--;

}

int rank_index(int *a, int target, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] == target) {
			return i;
		}
	}
	return -1;
}

int main(void) {
	// ---テストデータ1---
	Student students[N] = {
		{1, {1, 2, 3, 4, 5}, 0},
		{2, {1, 2, 4, 5, 3}, 0},
		{3, {3, 4, 1, 5, 2}, 0},
		{4, {2, 4, 1, 3, 5}, 0},
		{5, {1, 3, 2, 4, 5}, 0},
	};

	Lab labs[N] = {
		{1, {1, 2, 3, 4, 5}, {}, 0, 0},
		{2, {2, 3, 4, 5, 1}, {}, 0, 0},
		{3, {5, 4, 3, 2, 1}, {}, 0, 0},
		{4, {5, 1, 2, 3, 4}, {}, 0, 0},
		{5, {1, 4, 5, 2, 3}, {}, 0, 0},
	};

	// ---テストデータ2---
	// Student students[N] = {
	// 	{1, {1, 2, 3, 4, 5}, 0},
	// 	{2, {1, 2, 3, 4, 5}, 0},
	// 	{3, {2, 1, 3, 4, 5}, 0},
	// 	{4, {2, 3, 1, 4, 5}, 0},
	// 	{5, {3, 1, 2, 4, 5}, 0},
	// };

	// Lab labs[N] = {
	// 	{1, {1, 2, 3, 4, 5}, {}, 0, 0},
	// 	{2, {1, 2, 3, 4, 5}, {}, 0, 0},
	// 	{3, {1, 2, 3, 4, 5}, {}, 0, 0},
	// 	{4, {1, 2, 3, 4, 5}, {}, 0, 0},
	// 	{5, {1, 2, 3, 4, 5}, {}, 0, 0},
	// };


	for (int i = 0; i < N; i++) {
		// 一旦学生を希望の研究室に仮配属
		for (int j = 0; j < N; j++) {
			Student s = students[j];
			if (s.have_decided_lab == 0) {
				int want_lab_id = s.wanted_lab_ids[i];
				append(&labs[want_lab_id - 1], s);
			}
		}

		// 研究室1~5に対して順番に処理を行う
		for (int j = 0; j < N; j++) {
			if (labs[j].is_full == 0 || labs[j].curr_student_num > 1) {
				labs[j].is_full = 0;
				// 研究室に仮配属されている学生を, 順位の低い順に調べていき, 最後の1人になるまで学生を削除していく
				for (int k = N-1; k > 0; k--) {
					int rank = labs[j].wanted_student_ids[k];
					int idx = rank_index(labs[j].curr_student_ids, rank, N);
					if (labs[j].curr_student_num > 1 && idx != -1) {
						students[labs[j].curr_student_ids[idx]-1].have_decided_lab = 0;
						delete(&labs[j], idx);
					}
				}
			}
		}

		// 研究室と学生のステータスを更新
		for (int j = 0; j < N; j++) {
			if (labs[j].is_full == 0) {
				if (labs[j].curr_student_num == 1) {
					labs[j].is_full = 1;
					int id = labs[j].curr_student_ids[0];
					students[id - 1].have_decided_lab = 1;
				}
			}
		}
	}

	// 最終的に余った学生を残っている研究室に入れる
	for (int i = 0; i < N; i++) {
		if (students[i].have_decided_lab == 0) {
			for (int j = 0; j < N; j++) {
				if (labs[j].curr_student_num == 0) {
					labs[j].curr_student_ids[0] = students[i].id;
				}
			}
		}
	}

		puts("研究室番号: 学籍番号");
	for (int i = 0; i < N; i++) {
		printf("%d: %d\n", i+1, labs[i].curr_student_ids[0]);
	}

	return 0;
}
