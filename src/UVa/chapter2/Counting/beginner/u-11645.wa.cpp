#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long LL;
const int MAXN = 70;
LL f[MAXN];//代表有i个星星,有几个连续的11
int num[MAXN];

void convert_to_binary(LL n, int a[]){
    a[0] = 0;
    if(n == 0){
	a[0] = 1;
	a[1] = 0;
	return ;
    }
    while(n != 0){
	a[++a[0]] = n % 2;
	n = n / 2;
    }
}

LL calc(LL n, int a[]){
    convert_to_binary(n, a);

    LL ans = 0;
    LL right = n;

    for(int i = a[0]; i > 0; i--){
	if(i !=  a[0] && a[i] == 1 && a[i + 1] == 1){
	    LL now = right - a[i] * (((LL)1) << (i - 1)) * a[i];
	    ans += now + 1;
	}

	if(a[i] == 1){
	    ans += f[i - 1];	    
	}

	right -= a[i] * (1 << (i - 1)) * a[i];
    }

    return ans;
}

void init(){
    LL dp[MAXN][2];

    memset(f, 0, sizeof(f));
    memset(dp, 0, sizeof(dp));

    int n = 30;
    LL one = 1;
    
    for(int i = 2; i <= n; i++){
	//1
	dp[i][1] += dp[i - 1][0] + dp[i - 1][1];	
	dp[i][1] += one << (i - 2);
	//0
	dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    }

    for(int i = 0; i <= n; i++)
	f[i] = dp[i][0] + dp[i][1];

    printf("%lld\n", f[n]);
}

int main(){
    int kcase = 0;
    LL n;
    init();

    while(scanf("%lld", &n) != EOF){
	if(n < 0) break;
	printf("Case %d: %lld\n", ++kcase, calc(n, num));
    }

    return 0;
}
