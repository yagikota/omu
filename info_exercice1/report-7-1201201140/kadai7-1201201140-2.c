// 1201201140
// 八木洸太

#include <stdio.h>

// 間違った定義
# define sq1(a) a*a
// 適切な定義
# define sq2(a) (a)*(a)

int main(void) {
	int result1 = sq1(1+1);
	int result2 = sq2(1+1);
	// 期待値は4
	printf("result1: %d, result2: %d\n", result1, result2);
}