// 1201201140
// 八木洸太

# include <stdio.h>
#include <string.h>

#ifdef DEBUG
#define debug debug_print_array
#else
#define debug 1 ? (void)0 : debug_print_array
#endif

void print_array(char *str[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%s, ", str[i]);
	}
	puts("");
}

void debug_print_array(char *str[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%s, ", str[i]);
	}
	puts("");
}

void bsort(char *str[], int n) {
	int i, j;
	char *tmp;
	for (int i = 0; i < n; i++) {
		for (j = n - 1; j > i; j--) {
			if (strcmp(str[j-1], str[j]) > 0) {
				tmp = str[j];
				str[j] = str[j - 1];
				str[j - 1] = tmp;
				if (DEBUG == 1) {
					debug_print_array(str, n);
				}
			}
		}
	}
}




int main(void) {
	char *str[256] = {"love", "lovely", "like", "link", "list"};
	int n = 5;

	puts("ソート前");
	print_array(str, n);
	puts("");
	bsort(str, n);

	puts("");
	puts("ソート後");
	print_array(str, n);
	return 0;
}