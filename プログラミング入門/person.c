#include<stdio.h>
#include<string.h>

//データ型定義
struct Person {
	char name[40];
	int height;
	float wight;
};

int main(void) {
	//変数宣言
	struct Person dt, dt2;
	//ポインタ宣言
	struct Person *pp = &dt2;
	//初期化
	strcpy(dt.name, "Ichiro Tanaka");
	dt.height = 180;
	dt.wight = 70.0;

	strcpy(pp->name, "Jiro Suzuki");
	pp->height = 188;
	pp->wight = 80.0;

	printf("%s, %d, %f\n", dt.name, dt.height, dt.wight);
	printf("%s, %d, %f\n", pp->name, pp->height, pp->wight);

	return 0;

}

