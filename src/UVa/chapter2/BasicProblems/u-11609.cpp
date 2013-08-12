#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MOD = 1000000007;
typedef unsigned long long LL;

int pow(int n){
    if(n == 0) return 1;
    if(n == 1) return 2;

    LL ans = pow(n / 2);
    ans = (ans * ans) % MOD;

    if(n % 2 == 1)
	ans = (ans * 2) % MOD;	

    return ans;
}

int main(){
    int n, kcase = 0;
    scanf("%d", &n);
    while(scanf("%d", &n) != EOF){
	LL ans = ((LL)pow(n - 1) * (LL)(n % MOD));
	int d = ans % MOD;
	printf("Case #%d: %d\n", ++kcase, d);
    }
    return 0;
}
