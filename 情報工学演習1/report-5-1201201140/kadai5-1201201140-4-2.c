#define MAX_STACK 64//スタックに入れられる最大の要素数

#include <stdio.h>
#include <stdlib.h>

//pop 関数．
// s[]: スタックを表現する配列
//   l: スタックの長さを表す変数のポインタ
int pop( int s[], int* l );

//print_stack 関数
//スタックに積んだ数値を出力する関数
// s[]: スタックを表現する配列
//   l: スタックの長さ
void print_stack( int s[], int l );

int main( void ){
	int stack[ MAX_STACK ];//スタックを表現する配列
	int len = 0;//スタックの長さ．最初はスタックに何も積まれていないので0
	int val;//pop されてきた整数を格納する変数
	int new_len[ 2 ];//pop の時に使う新旧のスタックの長さを代入する配列．
	int i;

	//テスト用にスタックに予め4つほど整数を積んでおく
	stack[0] = 1;
	stack[1] = 2;
	stack[2] = 3;
	stack[3] = 4;
	//スタックの長さは4
	len = 4;

	//スタック表示
	print_stack( stack, len );

	//4回スタックからpop する
	for( i=0; i<4; i++ ){
		val = pop( stack, &len );
		printf( "%d\n", val );
		//スタック表示
		print_stack( stack, len );
	}
	
	return 0;
}

int pop( int s[], int* l ){

	int val = 0;//popした値
	//lの値に代入をしたい場合は，(*l) = a; として下さい．
	//////////ここからpop 関数の中身を書いて下さい．////////////////////////////////
	val = s[--*l];

	//////////////////////////ここまで///////////////////////////////////////////
	return val;
}

void print_stack( int s[], int l ){
	int i;
	if( l < 0 ){
		printf( "The length of the stack should be positive.\n" );
		exit( -1 );
	}
	else{
		printf( "[" );
		for( i=0; i<l; i++ ){
		printf( "%d", s[i] );
		if( i != ( l-1 ) ){
		printf( " " );
		}
		}
		printf( "]\n" );
	}
}