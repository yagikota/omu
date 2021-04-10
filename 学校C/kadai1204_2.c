// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#define NAME_LEN 40
#define NUMBER 3

typedef struct Person {
	char name[NAME_LEN];
	int height;
	float weight;
	float bmi;
} Person;

void swap_Student(Person *x, Person *y) {
	Person temp = *x;
	*x = *y;
	*y = temp;
}

void sort_by_height(Person a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--)
			if (a[j - 1].height < a[j].height)
				swap_Student(&a[j - 1], &a[j]);
	}
}

void sort_by_weight(Person a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--)
			if (a[j - 1].weight > a[j].weight)
				swap_Student(&a[j - 1], &a[j]);
	}
}

void sort_by_bmi(Person a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--)
			if (a[j - 1].bmi < a[j].bmi)
				swap_Student(&a[j - 1], &a[j]);
	}
}


int main(void) {
	Person prsn[NUMBER] = {
		{"Emilia",  164, 55.0,},
		{"Ram",    153, 53.0},
		{"Rem",    154, 54.0},
	};

	int k, l;

	for (k = 0; k < NUMBER; k++)
		prsn[k].bmi = prsn[k].weight / ((float)prsn[k].height / 100) / ((float)prsn[k].height / 100);

	printf("\n");
	puts("--Member Profile--");
	puts("  Name       Height(cm)   Weight(kg)   BMI");
	for (l = 0; l < NUMBER; l++) {
		printf("  %-7s %6d %13.1f %17.6f\n", prsn[l].name, prsn[l].height, prsn[l].weight, prsn[l].bmi);
	}
	printf("\n");


	sort_by_height(prsn, NUMBER);

	puts("--sort by height--");
	puts("  Name       Height(cm)");
	for (l = 0; l < NUMBER; l++) {
		printf("  %-7s %6d\n", prsn[l].name, prsn[l].height);
	}
	printf("\n");


	sort_by_weight(prsn, NUMBER);

	puts("--sort by weight--");
	puts("  Name       Weight(kg)");
	for (l = 0; l < NUMBER; l++) {
		printf("  %-7s %7.1f\n", prsn[l].name, prsn[l].weight);
	}
	printf("\n");


	sort_by_bmi(prsn, NUMBER);

	puts("--sort by bmi--");
	puts("  Name       BMI");
	for (l = 0; l < NUMBER; l++) {
		printf("  %-7s %12.6f\n", prsn[l].name, prsn[l].bmi);
	}
	printf("\n");

	return 0;
}