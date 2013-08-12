#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 50001;
typedef int LL;

LL phi[MAXN];
LL sum[MAXN];


void init(){
    memset(phi, 0, sizeof(phi));
    phi[1] = 1;
    for(LL i = 2; i < MAXN; i++)
	if(phi[i] == 0){
	 //   phi[i] = i - 1;
	    for(LL j = i; j < MAXN; j += i){
		if(phi[j] == 0) phi[j] = j;
		phi[j] = phi[j] / i * (i - 1);
	    }
	}

    sum[1] = 1;
    for(int i = 2; i < MAXN; i++)
	sum[i] = phi[i] * 2;

    for(int i = 2; i < MAXN; i++)
	sum[i] += sum[i-1];

//    for(int i = 2; i < MAXN; i++)
//	printf("%lld ", sum[i]);
}

int main(){
    int n;
    init();
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;
	printf("%d\n", sum[n]);
    }
    return 0;
}
