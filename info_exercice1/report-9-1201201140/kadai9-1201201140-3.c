// 1201201140
// 八木洸太

#include <stdio.h>

#define N 5

typedef struct laboratory {
	int id; // 研究室番号
	int wanted_student_ids[N]; // 研究室側の配属者順位(降順)
	int curr_student_ids[N];
	int curr_student_num;
	int is_full;
} Lab;

typedef struct student {
	int id; // 学籍番号
	int wanted_lab_ids[N]; // 希望の研究室番号(希望順)
	int have_decided_lab;
} Student;

void append(Lab *lab, Student s) {
	lab->curr_student_ids[lab->curr_student_num] = s.id;
	lab->curr_student_num++;
}

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

	Student students[N] = {
		{1, {1, 2, 3, 4, 5}, 0},
		{2, {1, 2, 3, 4, 5}, 0},
		{3, {2, 1, 3, 4, 5}, 0},
		{4, {2, 3, 1, 4, 5}, 0},
		{5, {3, 1, 2, 4, 5}, 0},
	};

	Lab labs[N] = {
		{1, {1, 2, 3, 4, 5}, {}, 0, 0},
		{2, {1, 2, 3, 4, 5}, {}, 0, 0},
		{3, {1, 2, 3, 4, 5}, {}, 0, 0},
		{4, {1, 2, 3, 4, 5}, {}, 0, 0},
		{5, {1, 2, 3, 4, 5}, {}, 0, 0},
	};


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Student s = students[j];
			if (s.have_decided_lab == 0) {
				int want_lab_id = s.wanted_lab_ids[i];
				append(&labs[want_lab_id - 1], s);
			}
		}

		for (int j = 0; j < N; j++) {
			if (labs[j].is_full == 0 || labs[j].curr_student_num > 1) {
				labs[j].is_full = 0;
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

	puts("研究室番号: 学籍番号");
	for (int i = 0; i < N; i++) {
		printf("%d: %d\n", i+1, labs[i].curr_student_ids[0]);
	}

	return 0;
}
