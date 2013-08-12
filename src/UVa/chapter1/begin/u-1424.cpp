#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
const int MAXN = 310;

int n1, m, n;
int path[MAXN];
int dp[MAXN][MAXN];
int mat[MAXN][MAXN];

int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
	scanf("%d%d", &n1, &m);
	memset(mat, 0, sizeof(mat));
	for(int i = 0; i < m; i++){
	    int x, y;
	    scanf("%d%d", &x, &y);
	    mat[x][y] = 1;
	    mat[y][x] = 1;
	}

	for(int i = 1; i <= n1; i++)
	   mat[i][i] = 1;

	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	    scanf("%d", path+i);

	memset(dp, 0x7f, sizeof(dp));

	for(int i = 1; i <= n1; i++)
	    dp[1][i] = (i == path[1] ? 0 : 1);

	for(int i = 2; i <= n; i++)
	    for(int j = 1; j <= n1; j++)
		for(int k = 1; k <= n1; k++)
		    if(mat[j][k]){
			if(path[i] == k)
			    dp[i][k] = min(dp[i][k], dp[i-1][j]);
			else
			    dp[i][k] = min(dp[i][k], dp[i-1][j] + 1);
		    }

	int ans = 2147483645;
	for(int i = 1; i <= n1; i++){
	    if(dp[n][i] < ans)
		ans = dp[n][i];
	}

	if(n == 0) ans = 0;
	printf("%d\n", ans);
    }
    return 0;
}
