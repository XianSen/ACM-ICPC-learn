#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long LL;

const int MAXN = 12;
const int MAXM = 120;

LL k;
LL num[20];
LL pow10[MAXN];

LL dp[MAXN][MAXM][MAXM];

void split(LL a[], LL num){
    if(num == 0){
	a[0] = 1;
	a[1] = 0;
    }

    a[0] = 0;
    while(num != 0){
	a[++a[0]] = num % 10;
	num /= 10;
    }
}

LL need(LL num){
    num = (num % k + k) % k;
    return num;
}

LL ff(LL d, LL m1, LL m2){
    if(d == 0) return 
	(m1 == 0 && m2 == 0 ? 1 : 0);

    LL& sum = dp[d][m1][m2];
    if(sum >= 0) return sum;

    sum = 0;
    for(int i = 0; i < 10; i++)
	sum += ff(d - 1, need(m1 + i * pow10[d-1]), need(m2 + i));

    return sum;
}

LL f(LL b){
    memset(dp, -1, sizeof(dp));
    split(num, b);

    LL now1 = 0;
    LL now2 = 0;

    LL *a = num;
    LL ans = 0;
    for(int l = 0; l < a[0]; l++){
	int i = a[0] - l - 1;//有i个星号
	for(int j = 0; j < a[i + 1]; j++)
	    ans += ff(i, need(now1 + j * pow10[i]), need(now2 + j)); 
//printf("d %lld\n", a[i]);
	//这边写错了,把a[i+1]写成a[i]了
	now1 = now1 + a[i + 1] * pow10[i];
	now2 += a[i + 1];
    }

    return ans;
}

int main(){
    LL a, b, kcase;

    pow10[0] = 1;
    for(int i = 1; i < MAXN; i++)
	pow10[i] = pow10[i-1] * 10;

    scanf("%lld", &kcase);
    while(kcase--){
	scanf("%lld%lld%lld", &a, &b, &k);
	if(k >= 90) printf("0\n");
	else printf("%lld\n", f(b + 1)  - f(a));
    }
    return 0;
}
