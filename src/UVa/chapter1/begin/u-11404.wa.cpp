#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 1100;
int n;
char s[MAXN];
int w[MAXN][MAXN];
int dp[MAXN][MAXN];

int main(){
    while(scanf("%s",s) != EOF){
	int n = strlen(s);
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++)
	    for(int j = 1; j <= n; j++){
		int x = i - 1;
		int y = n - j;

		if(s[x] == s[y]){
		    dp[i][j] = dp[i-1][j-1] + 1;
		    w[i][j] = 0;
		}else if(dp[i-1][j] > dp[i][j-1]){
		    dp[i][j] = dp[i - 1][j];
		    w[i][j] = 1;
		}else if(dp[i-1][j] < dp[i][j-1]){
		    dp[i][j] = dp[i][j - 1];
		    w[i][j] = 2;
		}else if(dp[i-1][j] == dp[i][j-1]){
		    if(s[x] < s[y]){
			dp[i][j] = dp[i][j-1];
			w[i][j] = 2;
		    }else{
			dp[i][j] = dp[i-1][j];
			w[i][j] = 1;
		    }
		}
	    }
	int x, y, len = dp[n][n];
	x = y = n;
	while(len > 0){
	    if(w[x][y] == 0){
		len --;
		x -= 1;
		y -= 1;
		printf("%c", s[x]);
	    }else if(w[x][y] == 1){
		x -= 1;
	    }else if(w[x][y] == 2){
		y -= 1;
	    }
	}
	printf("\n");
    }
    return 0;
}
