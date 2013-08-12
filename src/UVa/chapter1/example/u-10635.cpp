#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

const int MAXN = 320 * 320;
using namespace std;

int n, p, q;
int dp[MAXN];
int mp[MAXN];

int main(){
    int t;
    scanf("%d", &t);
    for(int kcas = 1; kcas <= t; kcas++){
	scanf("%d%d%d", &n, &p, &q);

	int size = 1;
	memset(mp, 0, sizeof(mp));
	for(int i = 1; i <= p + 1; i++){
	    int x;
	    scanf("%d", &x);
	    mp[x] = i;
	}

	vector<int> num;
	for(int i = 0; i <= q; i++){
	    int x;
	    scanf("%d", &x);
	    if(mp[x] != 0)
		num.push_back(mp[x]);
	}

	int ans = 0;
	memset(dp, 0x7f, sizeof(dp));
//printf("%d", dp[0]);

	for(int i = 0; i < num.size(); i++){	
	    int k = lower_bound(dp + 1, dp + MAXN, num[i]) - dp;
	    dp[k] = num[i];
	    if(ans < k) ans = k;
	}

	printf("Case %d: %d\n", kcas, ans);
    }
    return 0;
}
