#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using std::max;

const int maxn = 11000;
const int maxm = 5;

int equip[maxn][maxm];
int dp[maxm][1 << maxm];

int main(){
    int T, n, k, m = maxm;
    scanf("%d", &T);
    while(T--){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++)
	    for(int j = 0; j < m; j++)
		scanf("%d", &equip[i][j]);

	int ans = 0;
	if(k < 5){
	    memset(dp, 0, sizeof(dp));
	    int sum = (1 << 5);
	    for(int i = 1; i <= k; i++)
		for(int j = 0; j < sum; j++)
		   for(int l = 0; l <= j; l++) 
		       if((l & ~j) == 0)
			   for(int e = 0; e < n; e++){
			       int tmp = 0;
			       for(int o = 0; o < 5; o++)
				   if(((1 << o) & l) != 0){
				       tmp += equip[e][o];
				   }
//			       printf("%d\n", tmp);
			       dp[i][j] = max(dp[i][j], dp[i-1][j-l]+tmp);
			   }
	    ans = dp[k][sum - 1];
	}else{
	    int a[maxn];
	    memset(a, 0, sizeof(a));
	    for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		    a[j] = max(a[j], equip[i][j]);
	    for(int i = 0; i < m; i++)
		ans += a[i];
	}

	printf("%d\n", ans);
    }
    return 0;
}
