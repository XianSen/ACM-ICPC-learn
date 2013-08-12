#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define RUN(x) loop()

typedef long long LL;

const int MAXN = 11;
LL f[MAXN + 10];
LL dp[MAXN + 10];
LL pow10[MAXN + 10];

char s[MAXN + 10];

void init(){
    memset(f, 0, sizeof(f));
    memset(dp, 0, sizeof(dp));
    memset(pow10, 0, sizeof(pow10));

    pow10[0] = 1;
    for(int i = 1; i < MAXN; i++)
	pow10[i] = pow10[i-1] * 10;

    for(int i = 1; i < MAXN; i++){
	dp[i] = 10 * dp[i-1] + pow10[i-1];
    }

    f[1] = 1;
    for(int i = 2; i < MAXN; i++)
	f[i] = f[i-1] + 9 * dp[i-1];
}

/*
LL calc_zero(LL num){
    //计算小于num的数的0的总数
    num = num + 1;

    LL ans = 0;
    sprintf(s, "%lld", num);
    int n = strlen(s);

    ans = f[n - 1];
    printf("n = %d, f[n-1] = %lld\n", n, f[n - 1]);
printf("%lld\n", ans);
//printf("%lld\n", ans);

    int zero = 0;//前面有多少个0
    for(int l = 0; l < n; l++){
	int i = n - l - 1;//代表有多少个星星

	int min = 0;
	if(l == 0 && l != n - 1) min = 1;

	for(int j = min; j < s[l] - '0'; j++){
	    if(j == 0) ans += f[i] + pow10[i];
	    else ans += f[i];
	}

	num -= (s[l] - '0' ) * pow10[i];
	if(s[l] == '0') zero++;
	ans += zero * (num - 1);
    }

    return ans;
}*/

LL calc_zero(LL num){
    sprintf(s, "%lld", num);
    int n = strlen(s);
     
    LL ans = 0;
    LL fnum = 0;
    LL bnum = num;

    for(int l = 0; l < n; l++){
	bnum = bnum - (s[l] - '0') * pow10[n - l - 1];
	if(s[l] != '0'){
	    ans += fnum * pow10[n - l - 1];
	}else{
	    ans += (fnum - 1) * pow10[n - l - 1];
	    ans += (bnum + 1);
	}
	fnum = fnum * 10 + s[l] - '0';
    }
    return (ans + 1);
}

void test(){
    printf("test\n");
    LL num;
    while(true){
	scanf("%lld", &num);
	printf("%lld\n", calc_zero(num));
    }
}

void loop(){
    LL n, m;
    while(scanf("%lld%lld", &n, &m )!= EOF){
	if(n < 0 || m < 0) break;
	if(n == 0) printf("%lld\n", calc_zero(m));
	else printf("%lld\n", calc_zero(m) - calc_zero(n - 1));
    }
}
int main(){
    init();
    RUN(0);
    return 0;
}
