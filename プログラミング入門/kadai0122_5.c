// 学籍番号:1201201140
// 名前：八木洸太

#include<stdio.h>
#include<math.h>
#define sqr(n) (n)*(n)

typedef struct {
	float x;
	float y;
} Point;

float distance_of(Point pa, Point pb) {
	return sqrt(sqr(pa.x-pb.x)+sqr(pa.y+pb.y));
}

int main(void) {
	float d;
	Point p, q;

	printf("Please input coordinate of p(x, y)\n");
	printf("x = "); scanf("%f", &p.x);
	printf("y = "); scanf("%f", &p.y);

	printf("Please input coordinate of q(x, y)\n");
	printf("x = "); scanf("%f", &q.x);
	printf("y = "); scanf("%f", &q.y);

	d = distance_of(p,q);

	printf("Distanse between p(x,y) and q(x,y) : %f\n", d);

	return 0;
}