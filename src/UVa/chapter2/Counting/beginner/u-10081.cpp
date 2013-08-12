#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 110;
const int MAXM = 20;

int vist[MAXN][MAXM];
double dp[MAXN][MAXM];
double ans[MAXN][MAXM];

void calc(int n, int k){
    if(vist[n][k] != -1)
	return ;

    vist[n][k] = 1;
    memset(dp, 0, sizeof(dp)); 
    for(int i = 0; i <= k; i++)
	dp[1][i] = 100;

    for(int i = 2; i <= n; i++)
	for(int j = 0; j <= k; j++){
	    dp[i][j] += dp[i-1][j];
	    if(j > 0)
		dp[i][j] += dp[i - 1][j - 1];
	    if(j < k)
		dp[i][j] += dp[i - 1][j + 1];
	}

    double sum = 0;
    for(int i = 0; i <= k; i++)
	sum += dp[n][i];

//    printf("%d\n", sum);
    /*
    double nsum = 1;
    for(int i = 0; i < n; i++)
	nsum *= (k + 1);
	*/
//    ans[n][k] = sum / nsum;
    ans[n][k] = exp(log(sum * 1.0) - n * log(k + 1));
}

int main(){
    int n, k;
    memset(vist, -1, sizeof(vist));
    while(scanf("%d%d", &k, &n) != EOF){
	calc(n, k);
	printf("%0.5lf\n", ans[n][k]);
    }
    return 0;
}
