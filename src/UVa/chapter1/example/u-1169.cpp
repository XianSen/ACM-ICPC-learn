#include <deque>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;
const int MAXN = 110000;
int n, c;

struct Point{
    int x;
    int y;
    int w;
}p[MAXN];

//w[x], 是w和的集合
int w[MAXN];
//dis[i],是点i到原点的距离
int dis[MAXN];
//sum[x],sum[1] = dis[1]  
//	 sum[2] = sum[1] + dist[1][2]
int sum[MAXN];
int dp[MAXN];

int distan(int p1, int p2){
    return abs(p[p1].x - p[p2].x) + abs(p[p1].y - p[p2].y);
}

int main(){
    int kcase;
    scanf("%d", &kcase);
    while(kcase--){
	scanf("%d%d", &c, &n);

	p[0].x = 0;
	p[0].y = 0;
	p[0].w = 0;

	for(int i = 1; i <= n; i++)
	    scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].w);

	w[0] = 0;
	for(int i = 1; i <= n; i++)
	    w[i] = w[i-1] + p[i].w;

	dis[0] =0;
	for(int i = 1; i <= n; i++)
	    dis[i] =p[i].x + p[i].y;

	sum[0] = 0;
	for(int i = 1; i <= n; i++)
	    sum[i] = sum[i - 1] + distan(i, i - 1); 

	deque<int> que;

	dp[0] = 0;
	que.push_back(0);
	for(int i = 1; i <= n; i++){
	    while(!que.empty() && w[i] - w[que.front()] > c)
		que.pop_front();
	    int j = que.front();

	    dp[i] = dp[j] + dis[j+1] - sum[j+1] + dis[i] + sum[i];

	    while(!que.empty() && dp[que.back()] + dis[que.back() + 1] - sum[que.back()+1] >= dp[i] + dis[i+1] - sum[i+1])
		que.pop_back();
	    que.push_back(i);
	}

	printf("%d\n", dp[n]);
	if(kcase) printf("\n");
    }
    return 0;
}
