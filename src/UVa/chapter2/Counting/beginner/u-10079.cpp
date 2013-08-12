#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long LL;
int main(){
    LL n;
    while(scanf("%lld", &n) != EOF){
	if(n < 0) break;
	LL ans = (n + 2) * (n - 1) / 2 + 2;
	printf("%lld\n", ans);
    }
    return 0;
}
