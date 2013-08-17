#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 110;
double dp[MAXN][MAXN];

int main(){
    int tt;
    scanf("%d", &tt);
    for(int kcase = 1; kcase <= tt; kcase++){
	int n, a, b;
	scanf("%d/%d%d", &a, &b, &n);
	if(a == 0){
	    printf("Case #%d: %d\n", kcase, 1);
	    continue;
	}
	double p = a*1.0 / b;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1; 
	for(int i = 1; i <= n; i++){
	    dp[i][0] = dp[i - 1][0] * (1 - p);
	    for(int j = 1; j * b <= a * i; j++){
		dp[i][j] = dp[i-1][j-1] * p + dp[i-1][j] * (1 - p);
	    }
	}

	double sum = 0;
	for(int i = 1; i <= n; i++){
	    int k = (a * i + b - 1) / b;
	    if(k * b <= a * i) k++;
	    sum += dp[i - 1][k - 1] * p;
	}

	double ans = 1/(1 - sum);
	int day = ans;
	printf("Case #%d: %d\n", kcase, day);
    }
    return 0;
}
