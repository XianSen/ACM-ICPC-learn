#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

const int MAXN = 830;
const int MAXM = 2100;
using namespace std;

int tmp[MAXM];
int dp[MAXN][MAXM];

void calc(int n, int t[], int ans[][MAXM]){
    int& m = t[0];
    t[0] = max(ans[n - 1][0], ans[n - 2][0]);
    for(int i = 1; i <= m; i++)
	t[i] = (n - 1) * (ans[n - 1][i] + ans[n - 2][i]);

    int j = 0;
    for(int i = 1; i <= m; i++){
	t[i] += j;
	j = t[i] / 10;
	t[i] %= 10;
    }

    while(j != 0){
	t[++m] = j % 10;
	j = j / 10;
    }

    for(int i = 0; i <= m; i++)
	ans[n][i] = t[i];
}

void init(){
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;
    dp[1][1] = 0;

    dp[2][0] = 1;
    dp[2][1] = 1;

    int n = 802;
    for(int i = 3; i <= n; i++)
	calc(i, tmp, dp);
}

int main(){
    int n;
    init();
    while(scanf("%d", &n) != EOF){
	if(n == -1) break;
	int m = dp[n][0];
	for(int i = m; i > 0; i--)
	    printf("%d", dp[n][i]);
	printf("\n");
    }
    return 0;
}
