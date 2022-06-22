# include <stdio.h>


// テストでる
// apとbpが入れ替わっている
void func(int **x, int **y) {
	int *tmp = *x; // tmpにapを入れる
	*x = *y; // apにbpを入れる
	*y = tmp; // bpにtmp(ap)を入れる
	// 結果として，apとbpが入れ変わる
}

int main(void) {
	int a = 3, b = 2;
	int *ap = &a;
	int *bp = &b;
	printf("*ap=%d, *bp=%d\n", *ap, *bp);
	func(&ap, &bp);
	printf("*ap=%d, *bp=%d\n", *ap, *bp);
	printf("a=%d, b=%d\n", a, b); // a, b自体は変化しない
	return 0;
}