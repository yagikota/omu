t w, int **x, int *y, int *z) {
// 	w = *y; // wにb(=2)が代入される
// 	y = *x; // bのアドレスを格納していたyがaのアドレスを格納するようになる
// 	*y = *z; // aの値がc(=4)になる
// 	*z = **x; // cの値が(a=4)になる
// 	// 結果としてa=4, b=2, c=4となる
// }

// int main(void) {
// 	int a = 3, b = 2, c = 4;

// 	int *ap = &a;
// 	func(a, &ap, &b, &c);
// 	printf("a=%d, b=%d, c=%d\n", a, b, c);
// 	return 0;
// }