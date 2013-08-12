#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 27;

typedef long long LL;

LL g[MAXN];

LL f[MAXN];

LL ans[MAXN];

void init(){
    memset(f, 0, sizeof(f));
    int n = 26;
    f[0] = 1;
    for(int i = 1; i < n; i++)
	for(int j = 0; j < i; j++)
	    f[i] += f[j] * f[i - j - 1];

    g[2] = g[1] = 1;
    for(int i = 3; i <= n; i++)
	g[i] = ((6 * i - 9) * g[i - 1]  - (i - 3) * g[i - 2] ) / i;

    memset(ans, 0, sizeof(ans));
    for(int i = 1; i <= n; i++){
	ans[i] = g[i] - f[i - 1];
//	printf("%d %lld\n", i, g[i]);
    }
}

int main(){
    int n;

    init();

    while(scanf("%d", &n) != EOF){
	printf("%lld\n", ans[n]);
    }
    return 0;
}
