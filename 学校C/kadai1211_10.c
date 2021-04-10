// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include<string.h>
#define NUMBER 11
typedef struct player {
	char name[40];
	int number;
	char position[2];
} Player;

int main(void) {
	char info[10];
	int i;
	Player japan[NUMBER] = {
		{"Gonda",     12, "GK"},
		{"Miura ",     2, "DF"},
		{"Muroya",     3, "DF"},
		{"Yamanaka",   5, "DF"},
		{"Makino",    20, "DF"},
		{"Haraguchi ", 8, "MF"},
		{"Ito",       14, "MF"},
		{"Morita ",   17, "MF"},
		{"Misao",     18, "FW"},
		{"Sugimoto ", 11, "FW"},
		{"Kitagawa",  13, "FW"},
	};

	printf("What kind of player's information do you know? : ");
	scanf("%s", info);

	if (strcmp(info, "number") == 0) {
		puts("--NAME--     --NUMBER--");
		for (i = 0; i < NUMBER; i++)
			printf("%-10s %4d\n", japan[i].name, japan[i].number);
	} else if (strcmp(info, "position") == 0) {
		puts("--NAME--     --POSITION--");
		for (i = 0; i < NUMBER; i++)
			printf("%-10s %4s\n", japan[i].name, japan[i].position);
	} else
		printf("Error\n");

	return 0;
}