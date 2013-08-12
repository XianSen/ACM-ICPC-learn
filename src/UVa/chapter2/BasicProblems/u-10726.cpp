#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long LL;
bool check(int k, int num, int s, int m){
    LL now = k;
    LL absnow = k;
    for(int i = 1; i <= s; i++){
	now = (now * s) * (-1) + m;
	absnow = now < 0 ? -now : now;
	if(absnow > num) return false;
	else if(absnow == num) return true;
    }
    return absnow <= num ? true : false;
}

int find(LL k, LL b, LL mod, int n){
    k = k % mod;
    b = b % mod;
    for(int i = 1; i <= n; i++)
	if( (k * i + b) % mod == 0)
	    for(int j = n; j > 0; j--)
		if( (k * j + b) % mod == 0){
		    return ((j - i) / mod + 1);
		}
    return 0;
}

int calc(int num, int s, int mon){
    if(num == 0) return 0;
    LL an = 1;
    LL an1 = 1;
    LL ra =  (s - 1) * mon;

    num = num + ra;
    for(int i = 1; i <= s; i++){
	an = an * s;
	an1 = an1 * (s - 1);
	if(an > num) return 0;
    }

    LL ans1 = num  / an ;
    LL ans2 = ra  / an; 
    LL ans = 0;

    ans += find(an1, -ra, s, ans1);
    ans -= find(an1, -ra, s, ans2);

    return ans;
}

int main(){
    int tt;
    scanf("%d", &tt);
    for(int kcase = 1; kcase <= tt; kcase++){
	int sailor, monkey, low, high;
	scanf("%d%d%d%d", &sailor, &monkey, &low, &high);
	int ansl = calc(low - 1, sailor, monkey);
	int ansh = calc(high, sailor, monkey);
	printf("Case %d: %d\n", kcase, ansh - ansl);
    }
    return 0;
}
