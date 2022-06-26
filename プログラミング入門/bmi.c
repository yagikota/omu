// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include<string.h>
#define NAME_LEN 40
#define NUMBER 5

typedef struct Person {
	char name[NAME_LEN];
	int height;
	float weight;
} Person;

int main(void) {
	int i, j;
	int result;
	char whose[NAME_LEN];
	float bmi;

	Person students[NUMBER] = {
		{"Ichika",  165, 53.0},
		{"Nino",    164, 52.0},
		{"Miku",    163, 51.0},
		{"Yotsuba", 162, 50.0},
		{"Itsuki",  161, 49.0},
	};


	puts("Member Profile");
	for (i = 0; i < NUMBER; i++) {
		printf("  %s, %d, %2.1f\n", students[i].name, students[i].height, students[i].weight);
	}

	printf("Whose BMI do you know?\n");
	scanf("%s", whose);

	for (j = 0; j < NUMBER; j++) {
		result = strcmp(students[j].name, whose);
		if (result == 0) {
			bmi = students[j].weight / ((float)students[j].height / 100) / ((float)students[j].height / 100);
			printf("%s's BMI is %f\n", students[j].name, bmi);
		}
	}
	
	return 0;
}