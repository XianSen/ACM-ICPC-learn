//written by nothi 
//UVa1382-Distant Galaxy

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

int n;
struct Point{
    int x;
    int y;
    bool operator<(const Point &p)const{
	return x < p.x;
    }
}point[MAXN];
int y[MAXN];
int on[MAXN], on2[MAXN], left[MAXN]; 

int solve(){
    sort(point, point + n);
    sort(y, y + n);
    int m = unique(y, y+n) - y;

    int ans = 0;
    if(m <= 2) return n;

    for(int a = 0; a < m; a++)
	for(int b = a + 1; b < m; b++){
	    int ymin = y[a], ymax = y[b];
	    int k = 0;
	    for(int i = 0; i < n; i++){
		if(i == 0 || point[i].x != point[i-1].x){
		    k++;
		    on[k] = on2[k] = 0;
		    left[k] = k == 0 ? 0:left[k-1] + on2[k - 1] - on[k - 1];
		}
		if(point[i].y > ymin && point[i].y < ymax) on[k]++;
		if(point[i].y >= ymin && point[i].y <= ymax) on2[k]++;
	    }

	    if(k <= 2) return n;

	    int M = 0;
	    for(int i = 1; i <= k; i++){
		ans = max(ans, left[i] + M + on2[i]);
		M = max(M, on[i] - left[i]);
	    }
	}
    return ans;
}

int main(){
    int kcas = 0; 
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;
	for(int i = 0; i < n; i++){
	    scanf("%d%d", &point[i].x, &point[i].y);
	    y[i] = point[i].y;
	}
	int ans = solve();
	printf("Case %d: %d\n",++kcas, solve());
    }
    return  0;
}
