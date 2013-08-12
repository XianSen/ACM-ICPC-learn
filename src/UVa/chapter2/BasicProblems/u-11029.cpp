#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long LL;
const int MOD = 1000;

int calc(int n, int k){
    if(k == 0) return 1;
    int first = calc(n, k / 2);
    int result = (first * first) % MOD;
    if(k % 2 != 0)
	result = (result * n) % MOD;
    return result;
}

int work(int n1, int k1){
    double p = log10(n1 * 1.0) * k1;
    int n = (int) p;
    double re = p - n + 2;
    int ans = (int)pow(10, re);
    return ans;
}

int main(){
    int kcase;
    scanf("%d", &kcase);
    while(kcase--){
	LL n, k;
	scanf("%lld%lld", &n, &k);
	printf("%03d...%03d\n",work(n, k), calc(n % MOD, k));
    }
    return 0;
}
