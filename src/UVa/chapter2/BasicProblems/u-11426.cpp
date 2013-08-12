#include <stdio.h>
#include <string.h>
#include <string.h>

typedef long long LL;
const LL MAXN = 4000001;

LL f[MAXN + 10];
LL s[MAXN + 10];
LL phi[MAXN + 10];

void phi_table(LL n){
    memset(phi, 0, sizeof(phi));
    phi[1] = 1;
    for(LL i = 2; i <= n; i++)
	if(!phi[i])
	    for(LL j = i; j <= n; j += i){
		if(phi[j] == 0)
		    phi[j] = j;
		phi[j] = phi[j] / i * (i - 1);
	    }
//printf("%lld\n", n);
}

void init(){
    LL n = MAXN - 1;

    phi_table(n);

    memset(f, 0, sizeof(f));
    memset(s, 0, sizeof(s));

    for(LL i = 1; i <= n; i++)
	for(LL j = i * 2; j <= n; j += i)
	   s[j] += i * phi[j / i]; 

    f[2] = s[2];
    for(LL i = 3; i <= n; i++)
	f[i] = f[i - 1] + s[i];
}

int main(){
    init();
    LL n;
    while(scanf("%lld", &n) != EOF){
	if(n == 0) break;
	printf("%lld\n", f[n]);
    }
    return 0;
}
