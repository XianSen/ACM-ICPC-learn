#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long LL;

LL ex_gcd(LL a, LL b, LL &x, LL & y){
    if(b == 0){
	x = 1;
	y = 0;
	return a;
    }else{
	LL d = ex_gcd(b, a % b, x, y);
	LL t = x;
	x = y;
	y = t - (a / b) * y;
	return d;
    }
}

int main(){
    int kcase;
    scanf("%d", &kcase);
    while(kcase--){
	int x, k;
	scanf("%d%d", &x, &k);
	LL a = x / k;
	LL b = (x + k - 1) / k;
	LL p, q;
	LL d = ex_gcd(a, b, p, q);
	d = x/ d;
	printf("%lld %lld\n", p * d , q * d);
    }
    return 0;
}
