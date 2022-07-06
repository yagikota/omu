# include <stdio.h>

// void func1(int x, int *y, int **z) {
// 	x = *y;
// 	y = *z;
// 	**z = x;
// }

// // void func2(int *x, int *y, int **z) {
// // 	x = y;
// // 	y = *z;
// // 	**z = *x;
// // }

// // void func3(int w, int **x, int *y, int *z) {
// // 	w = *y;
// // 	y = *x;
// // 	*y = *z;
// // 	*z = **x;
// // }

// int main(void) {
// 	int a = 3, b = 2, c = 4;

// 	int *cp = &c;
// 	func1(a, &b, &cp); // a=3, b=2, c=2
// 	// func2(&a, &b, &cp); // a=3, b=2, c=2

// 	// int *ap = &a;
// 	// func3(a, &ap, &b, &c);
// 	printf("a=%d, b=%d, c=%d\n", a, b, c);
// 	return 0;
// }



// void func(int x, int *y, int **z) {
// 	x = *y; // xに2が代入される
// 	y = *z; // bのアドレスを格納していたyがcのアドレスを格納するようになる
// 	**z = x; // cの値がx(=2)になる
// 	// 結果として，cの値だけが2に変更される
// }

// int main(void) {
// 	int a = 3, b = 2, c = 4;

// 	int *cp = &c;
// 	func(a, &b, &cp);
// 	printf("a=%d, b=%d, c=%d\n", a, b, c);
// 	return 0;
// }

// void func(int *x, int *y, int **z) {
// 	x = y; // aのアドレスを格納していたxがbのアドレスを格納するようになる
// 	y = *z; // bのアドレスを格納していたyがcのアドレスを格納するようになる
// 	**z = *x; // cの値が*x(=b=2)になる
// 	// 結果として，cの値だけが2に変更される
// }

// int main(void) {
// 	int a = 3, b = 2, c = 4;

// 	int *cp = &c;
// 	func(&a, &b, &cp);
// 	printf("a=%d, b=%d, c=%d\n", a, b, c);
// 	return 0;
// }




void func(int w, int **x, int *y, int *z) {
	w = *y; // wにb(=2)が代入される
	y = *x; // bのアドレスを格納していたyがaのアドレスを格納するようになる
	*y = *z; // aの値がc(=4)になる
	*z = **x; // cの値が(a=4)になる
	// 結果としてa=4, b=2, c=4となる
}

int main(void) {
	int a = 3, b = 2, c = 4;

	int *ap = &a;
	func(a, &ap, &b, &c);
	printf("a=%d, b=%d, c=%d\n", a, b, c);
	return 0;
}