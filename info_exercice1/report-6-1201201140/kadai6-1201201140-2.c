#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <string.h>

#define SIZE 10

int comb(int a, int b) {
	if (a <= 0 || b < 0) {
		return -1;
	}

	if (b == 0) {
		return 1;
	}

	if (a < 2*b) {
		b = a - b;
	}
	int ans = 1;
	for (int i = 0; i < b; i++) {
		ans *= (a - i);
	}
	for (int i = 1; i < b+1; i++) {
		ans /= i;
	}
	return ans;
}

int convert_alph_case(int chr) {
	if(chr >= 65 && chr <= 90) {
		chr += 32;
	} else if (chr >= 97 && chr <= 122) {
		chr -= 32;
	}
	return chr;
}

int main(int argc, char *argv[]){
	// 課題4
	int ans = comb(1, 1);
	if (ans < 0) {
		printf("invalid arguments\n");
	} else {
		printf("aCb: %d\n", ans);
	}

	// 課題５
	char *target_alph= argv[1];
	char *in_file_name = argv[2];
	char *out_file_name = argv[3];

	FILE *fp_in;
	if ((fp_in = fopen(in_file_name, "r")) == NULL) {
		printf("Cannot open emperors_new_clothes.txt\n");
		exit(1);
	} else {
		printf("emperors_new_clothes.txt opened!\n");
	}

	int chr;
	FILE *fp_out;
	if ((fp_out = fopen(out_file_name, "a")) == NULL) {
		printf("Cannot open result.txt\n");
		exit(1);
	} else {
		printf("result.txt opened!\n");
	}

	while ((chr = fgetc(fp_in)) != EOF) {
		if (chr == (int)*target_alph) {
			chr = convert_alph_case(chr);
		}
		putc(chr, fp_out);
	}

	fclose(fp_in);
	fclose(fp_out);

	return 0;
}