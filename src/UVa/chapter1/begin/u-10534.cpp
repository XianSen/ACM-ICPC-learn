#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int MAXN = 11000;
int dp[MAXN];
int num[MAXN];
int a[MAXN], b[MAXN];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
	for(int i = 1; i <= n; i++)
	    scanf("%d", num+i);

	memset(dp, 0x7f, sizeof(dp));
	for(int i = 1; i <= n; i++){
	    int k = lower_bound(dp + 1, dp + 1 + n, num[i]) - dp;
	    a[i] = k;
	    dp[k] = num[i];
	}
	
	memset(dp, 0x7f, sizeof(dp));
	for(int i = n; i >= 1; i--){
	    int k = lower_bound(dp + 1, dp + 1 + n, num[i]) - dp;
	    b[i] = k;
	    dp[k] = num[i];
	}

	int ans = 0;

	for(int i = 1; i <= n; i++){
	    int now = min(a[i], b[i]) * 2 - 1;
	    ans = max(ans, now);
	}

	printf("%d\n", ans);
    }
    return 0;
}
