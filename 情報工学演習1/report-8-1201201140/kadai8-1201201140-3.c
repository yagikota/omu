// 1201201140
// 八木洸太

#include <stdio.h>

void replace(int *x, int *y);


int main( void ){
	int a = 10;
	int b = 6;

	printf( "a=%d, b=%d\n",a, b );

	replace(&a, &b);

	printf( "a=%d, b=%d\n",a, b );

	return 0;
}

void replace(int *x, int *y){
	int z;

	z = *x;
	*x = *y;
	*y = z;
}

// 変更前のコードではreplace関数には，a, bのコピーが渡され，replace関数内で処理が適用されるのは，コピーしたa, bであ流ので，元々のa, bは変更されない．