//n == 1的情况要特殊考虑
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long LL;

const int MAXN = 1000021;
int vist[MAXN];
int prime[MAXN];

void init(){
    memset(vist, 0, sizeof(vist));
    prime[0] = 0;
    for(LL i = 2; i < MAXN; i++)
	if(!vist[i]){
	    prime[++prime[0]] = i;
	    for(LL j = i * i; j < MAXN; j += i)
		vist[j] = 1;
	}
}

int main(){
    init();
    LL n, kcase = 0;
    while(scanf("%lld", &n) != EOF && n){
	LL ans = 0;
	LL num = 0;
    
	LL nown = n;
	for(int i = 1; i <= prime[0]; i++)
	    if(n % prime[i] == 0){
		LL now = 1;
		num += 1;
		while(n % prime[i]  == 0){
		    now *= prime[i];
		    n = n / prime[i];
		}
		ans +=  now;
	    }

	if(n != 1){
	    ans += n;
	    num += 1;
	}

	if(num == 0)
	    ans = 2;

	if(num == 1)
	    ans += 1;

//	if(ans > nown + 1) ans = nown + 1;
	printf("Case %lld: %lld\n", ++kcase, ans);
    }
    return 0;
}
