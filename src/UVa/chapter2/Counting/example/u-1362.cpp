#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 300 + 30;
const int MOD = 1000000000;
typedef long long LL;

char s[MAXN];
int dp[MAXN][MAXN];

int work(int st, int en){
    if(st == en) return 1;
    if(s[st] != s[en]) return 0;
    int &ans = dp[st][en];
    if(ans >= 0) return ans;

    ans = 0;
    for(int k = st + 2; k <= en; k++)
	if(s[k] == s[st])
	    ans = (ans + (LL)work(st + 1, k - 1) * (LL)work(k, en)) % MOD;
    return ans;
}

int main(){
    while(scanf("%s", s) != EOF){
	memset(dp, -1, sizeof(dp));
	printf("%d\n", work(0, strlen(s) - 1));
    }
    return 0;
}
