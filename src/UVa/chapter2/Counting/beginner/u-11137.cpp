#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int  MAXN = 10001;
const int  MAXM = 22;
unsigned long long dp[MAXM][MAXN];

int main(){
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i < MAXM; i++)
	for(int j = 0; j < MAXN; j++){
	    dp[i][j] = dp[i-1][j]; 
	    if(j >= i * i * i)
		dp[i][j] += dp[i][j - i * i * i];
	}	

    int n;
    while(scanf("%d", &n) != EOF){
	printf("%lld\n", dp[21][n]);
    }
    return 0;
}
