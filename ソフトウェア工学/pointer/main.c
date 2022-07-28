# include <stdio.h>


// テストでる
// apとbpが入れ替わっている
void func(int **x, int **y) {
	int *tmp = *x; // ポインタtmpの参照先をポインタのポインタであるxの参照先の値(aのアドレス)とする。
	*x = *y; //  ポインタのポインタであるxの参照先の値をポインタのポインタであるyの参照先の値(bのアドレス)とする。
	*y = tmp; // ポインタのポインタであるyの参照先の値をポインタtmp(参照先はaのアドレス)にする
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


// void func(int x, int y, int *xp, int*yp) {
// 	x = *yp;
// 	int tmp = x + y;
// 	xp = yp;
// 	*xp = tmp;
// }

// int main(void){
// 	int a=1, b=2;
// 	func(a, b, &a, &b);
// 	printf("a=%d, b=%d\n", a, b);
// 	return 0;
// }


// void func(int **x, int **y) {
// 	int *tmp = *x; // ポインタtmpの参照先を、ポインタのポインタxの参照先の値(aのアドレス)にする。
// 	*x = *y; // ポインタのポインタxの参照先の値をポインタのポインタyの参照先の値(bのアドレス)にする。
// 	*y = tmp; // ポインタのポインタyの参照先の値をポインタtmpの参照先(aのアドレス)にする・
// 結果、ポインタのポインタであるxとyの参照先の値(アドレス)が入れ替わるだけで、a, b自体は変化しない。
// }

// int main(void) {
// 	int a = 3, b = 2;
// 	int *ap = &a;
// 	int *bp = &b;
// 	printf("*ap=%d, *bp=%d\n", *ap, *bp);
// 	func(&ap, &bp);
// 	printf("*ap=%d, *bp=%d\n", *ap, *bp);
// 	printf("a=%d, b=%d\n", a, b); //
// 	return 0;
// }
