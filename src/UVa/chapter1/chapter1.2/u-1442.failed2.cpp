#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

const int MAXN = 1100000;
const int INF = 20000;
using namespace std;

int l[MAXN];
int h[MAXN];
int sum[MAXN];

struct Cave{
    int l;
    int h;
    int who;
};

int main(){
    int z;
    scanf("%d", &z);
    while(z--){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	    scanf("%d", l + i);
	for(int i = 1; i <= n; i++){
	    scanf("%d", h + i);
	    h[i] = h[i] - 1;
	}

	sum[0] = 0;
	for(int i = 1; i <= n; i++)
	    sum[i] = sum[i-1] + l[i];

	h[n+1] = l[n+1] = INF;
	n = n + 1;

	int ans = 0;
	deque<Cave> que;
	que.push_back((Cave){INF, INF, 0});

	for(int i = 1; i <= n; i++){
	    int newl = l[i];
	    int newh = h[i];
	    int who = i;
	    while(que.back().l < l[i]){
		Cave oldCave = que.back();
		que.pop_back();
		who = oldCave.who;
		newh = min(oldCave.h, newh);
		newl = max(oldCave.l, newl);
		if(oldCave.h >= oldCave.l){	
		   int len = i - oldCave.who; 
		   int nowh = min(min(oldCave.h, l[i]), que.back().l);
		   int sumArea = sum[i - 1] - sum[oldCave.who-1];
		   int area = len * (nowh+1)  - sumArea;
		   ans = max(ans, area);
		}
		que.back().h = min(que.back().h, oldCave.h);
	    }
	    if(que.back().l == l[i]){
		que.back().h = min(h[i], que.back().h);
	    }else{
		que.push_back((Cave){newl,newh,who});
	    }
	}

	printf("%d\n", ans);
    }
    return 0;
}
