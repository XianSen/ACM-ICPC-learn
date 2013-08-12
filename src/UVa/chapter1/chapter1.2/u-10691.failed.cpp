#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 300;

struct Point{
    int x;
    int y;

    int cross(int x1, int y1, int x2, int y2)const{
	return x1 * y2 - x2 * y1;
    }

    int where(int x, int y)const{
	if(x == 0 && y == 0) return 0;
	if(x > 0 && y == 0) return 1;
	if(x > 0 && y > 0) return 2;
	if(x == 0 && y > 0) return 3;
	if(x < 0 && y > 0) return 4;
	if(x < 0 && y == 0) return 5;
	if(x < 0 && y < 0) return 6;
	if(x == 0 && y < 0) return 7;
	if(x > 0 && y < 0) return 8;
    }

    bool operator<(const Point& e) const{
	int w1 = where(x, y);
	int w2 = where(e.x, e.y);
	if(w1 < w2) return true;
	if(w1 > w2) return false;
	int c = cross(x, y, e.x, e.y);
	if(c > 0) return true;
	return false;
    }
}point[MAXN];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
	int n, d;	
	scanf("%d%d", &n, &d);
	for(int i = 0; i < n; i++)
	    scanf("%d%d", &point[i].x, &point[i].y);
    }
    return 0;
}
