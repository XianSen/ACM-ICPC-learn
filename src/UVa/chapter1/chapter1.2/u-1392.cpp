#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int MAXN = 151000;
int n, p;
int a[MAXN];
int b[MAXN];

int getC(){
    char c = getchar();
    while(c != 'A' && c != 'C' && c != 'G' && c != 'T')
	c = getchar();
    return c;
}

struct Point{
    int x;
    int y;
    bool operator<(const Point& o)const{
	int t1 = x - y;
	int t2 = o.x - o.y;
	if(t1 < t2) return true;
	if(t1 > t2) return false;
	return y >= o.y;
    }
}point[MAXN];

int main(){
    while(scanf("%d%d", &n, &p) != EOF){
	if(p == 0 && n == 0) break;

	for(int i = 0; i < n; i++)
	    a[i] = getC(); 
	for(int i = 0; i < n; i++)
	    b[i] = getC();

	int ans = 0;
	int sum = 0;

	for(int i = 0; i < n; i++){
	    if(a[i] != b[i]) sum++;
	    point[i].x = 100 * sum;
	    point[i].y = (i+1) * p;
	}
	point[n].x = 0;
	point[n].y = 0;
	n++;

	sort(point, point + n);

	int last = point[n - 1].y;

	for(int i = n - 2; i >= 0; i--){
	    if(point[i].y < last)
		last = point[i].y;
	    if(point[i].y - last > ans){
		ans = point[i].y - last;
	    }
	}

	if(ans == 0) printf("No solution.\n");
	else printf("%d\n", ans/p);
    }
    return 0;
}
