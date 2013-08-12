#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 310;
int dp[maxn][maxn];

int find(int n, int m){
    if(dp[n][m] != -1) return dp[n][m];

    int n1, n2, tmp;
    int ans = 0x7fffffff; 
    for(int i = 1; i < n; i++){
	n1 = i, n2 = n - i;
	tmp =   find(min(n1, m), max(n1, m)) 
	      + find(min(n2, m), max(n2, m)) + 1;
	if(tmp < ans) ans = tmp;	
    }

    for(int i = 1; i < m; i++){
	n1 = i, n2 = m - i;
	tmp =   find(min(n1, n), max(n1, n)) 
	      + find(min(n2, n), max(n2, n)) + 1;
	if(tmp < ans) ans = tmp;	
    }

    dp[n][m] = ans;

    return dp[n][m];
}

int main(){
    int i, j, n, m;

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    dp[1][1] = 0;

    while(scanf("%d%d", &n, &m) != EOF){
	int ans = 0;
	if(n < m)
	    ans = find(n, m);
	else
	    ans = find(m, n);
	printf("%d\n", ans);
    }
    return 0;
}
