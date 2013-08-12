#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Q(x) ((x) * (x))

struct Point{
    double x;
    double y;
};

double distance(double x1, double y1, double x2, double y2){
    return sqrt(Q(x1 - x2) + Q(y1 - y2));
}

int main(){
    int n;
    Point a, b;
    scanf("%d", &n);
    while(scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y) == 4){
	double ans = distance(a.x, a.y, b.x, b.y);
	double first = distance(-a.x, a.y, b.x, -b.y);
	double second = distance(a.x, -a.y, -b.x, b.y);
	if(first < second) ans += first;
	else ans += second;
	printf("%0.3lf\n", ans);
    }
    return 0;
}
