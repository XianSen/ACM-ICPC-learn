#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 1100;
double dp[MAXN];

int main(){
    int n;
    double pl, pr, p;
    while(scanf("%d",&n) == 1){
	if(n == 0) break;
	scanf("%lf%lf", &pl, &pr);
	p= 1 - pl - pr;
	dp[0] = 0;
	dp[1] = 1.0/p;
	for(int i = 2; i <= n; i++){
	    dp[i] = 1e300;
	    double now = 0;
	    //枚举最后一个放在哪

	    //最后一个放最左边
	    now = (1 + (1 - pl) * dp[i - 1]) / p;
	    if(now < dp[i]) dp[i] = now;

	    //最后一个放最右边
	    now = (1 + (1 - pr) * dp[i - 1]) / p;
	    if(now < dp[i]) dp[i] = now;

	    //最后一个在中间
	    for(int l = 1; l < i - 1; l++){
		double now = 0;
		int r = i - l - 1;
		now =  (1 + dp[l]  + dp[r] - pl * dp[r] - pr * dp[l])/p;
		if(now < dp[i]) dp[i] = now;
	    }
	}

	printf("%0.2lf\n", dp[n]);
    }
    return 0;
}
