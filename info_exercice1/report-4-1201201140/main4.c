#define MAX_STACK 64//スタックに入れられる最大の要素数

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>

//push 関数．
// s[]: スタックを表現する配列
//   l: スタックの長さ
// val: スタックに格納される整数
//戻り値はスタックにval を積んだあとのスタックの長さ
int push( int s[], int l, int v );

//pop 関数．
// s[]: スタックを表現する配列
//l[2]: l[0] がスタックの長さを表し，l[1] がpop した後のスタックの長さ 
int pop( int s[], int l[2] );

//print_stack 関数
//スタックに積んだ数値を出力する関数
// s[]: スタックを表現する配列
//   l: スタックの長さ
void print_stack( int s[], int l );

bool is_digit(char c) {
	return (strcmp(&c, "1") || strcmp(&c, "2") || strcmp(&c, "3") || strcmp(&c, "4") || strcmp(&c, "5") || strcmp(&c, "6") || strcmp(&c, "7") || strcmp(&c, "8") || strcmp(&c, "9"));
}

int main( void ){

	int stack[ MAX_STACK ];//スタックを表現する配列
	int len = 0;//スタックの長さ．最初はスタックに何も積まれていないので0
	char eq[] = "7 8 + 4 9 - *";//逆ポーランド式記法の数式
	printf( "%s\n", eq);

	// eq を前から読んでいって，整数の場合はpush, 演算子の場合は2回pop して計算結果をpush//
	for (int i = 0; i < sizeof(eq) / sizeof(eq[0]); i++) {
		char c = eq[i];
		if (strcmp(c," ")) {
			continue;
		} else if (strcmp(&c,"+")) {
			int val = 0;
			val = pop(stack, &len);
			val += pop(stack, &len);
			len = push(stack, len, val);
		} else if (strcmp(&c,"-")) {
			int val = 0;
			val = pop(stack, &len);
			val -= pop(stack, &len);
			len = push(stack, len, val);
		} else if (strcmp(&c,"*")) {
			int val = 0;
			val = pop(stack, &len);
			val *= pop(stack, &len);
			len = push(stack, len, val);
		} else if (strcmp(&c,"/")) {
			int val = 0;
			val = pop(stack, &len);
			val /= pop(stack, &len);
			len = push(stack, len, val);
		} else if (is_digit(c)) {
			len = push(stack, len, (int)c);
		}
	}

		/////////////////////////////////ここまで//////////////////////////////////////

	printf("equation:%s\n", eq);
	printf( "answer: %d\n", stack[0] );
	
	return 0;
}

////////////////////4-1 で完成させた関数をコピーして下さい///////////////////////
int push( int s[], int l, int val ){
	int n_val_update = 0;
	s[l] = val;
	n_val_update = l + 1;
	return n_val_update;
}

////////////////////4-2 で完成させた関数をコピーして下さい///////////////////////
int pop( int s[], int *l ){
	int val = 0;
	val = s[--*l];
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