#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 100;
const int MAXK = 91000000;

typedef long long LL;
LL f[MAXN];
LL dp[MAXN][2];

void init(){
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;
    dp[1][1] = 1;

    int i = 1;
    while(dp[i][1] < MAXK){
	i = i + 1;
	dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
	dp[i][1] = dp[i - 1][0];
    }

    int n = 40;
    //f[i]表示i位的第一个数为1后面i个0有是第几个 
    f[0] = 1;
    for(int i = 1; i <= n; i++){
	f[i] = dp[i - 1][0] + dp[i - 1][1] + 1;
//	printf("i = %d f[i] = %lld\n", i, f[i]);
    }

}

int ans[50];

int main(){
    init();
    int n, tt;
    scanf("%d", &tt);
    while(scanf("%d", &n) == 1){
	memset(ans, 0, sizeof(ans));
	n = n + 1;

	int max = 40;
	for(int i = 40; i >= 1; i--)
	    if(f[i] <= n){
		max = i;
		break;
	    }

	//范围为now 
	LL now = f[max];
	ans[max] = 1;

//	if(now != n)
	dp[0][1] = 1;
	for(int i = max - 1; i >= 1; i--){ 
	    if(now + dp[i-1][0] + dp[i-1][1] > n)
		ans[i] = 0;
	    else{
		ans[i] = 1;
		now += dp[i-1][0] + dp[i-1][1];
	    }
	}

	for(int i = 40; i >= 1; i--)
	    if(ans[i] != 0 || i == 1){
		for(int j = i; j >= 1; j--)
		    printf("%d", ans[j]);
		break;
	    }
	printf("\n");
    }
    return 0;
}
