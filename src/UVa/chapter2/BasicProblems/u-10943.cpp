#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 110;
const int MOD = 1000000;
int dp[MAXN][MAXN];

int init(){
    int n = 100, k = 100;
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for(int i = 0; i <= n; i++)
	for(int j = 1; j <= k; j++)
	    for(int k = 0; k <= i; k++){
		dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) % MOD;
	    }
}

int main(){
    init();
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF){
	if(n == 0 && k == 0) break;
	printf("%d\n", dp[n][k]);
    }
    return 0;
}
