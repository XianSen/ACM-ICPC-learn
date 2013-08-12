#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 110000;
const int MAXM = 110;

int n, capacity;
int dp[MAXN][MAXM];

struct Package{
    int x;
    int y;
    int w;
}pack[MAXN];

int main(){
    int cases;
    scanf("%d", &cases);
    while(cases--){
	scanf("%d%d", &capacity, &n);
	for(int i = 1; i <= n; i++)
	    scanf("%d%d%d", &pack[i].x, &pack[i].y, &pack[i].w);
	memset(dp, 0x7f, sizeof(dp));

	int INF = dp[0][0];
	dp[0][0] = 0;
	int ans = 0; 
	for(int i = 1; i <= n; i++){ 
	    dp[i][pack[i].w] = ans + pack[i].x + pack[i].y;
	    ans = ans + (pack[i].x + pack[i].y) * 2;
	}
    }
    return 0;
}
