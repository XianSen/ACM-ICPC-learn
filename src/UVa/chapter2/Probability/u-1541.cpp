#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 100;
const int MAXM = 100;
const int LOSE = MAXN * MAXM;

char s[MAXN];
int next[MAXN];

double dp[MAXN][MAXN];

int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
	int m, t;
	scanf("%d%d", &m, &t);
	next[m + 1] = 0;
	for(int i = 1; i <= m; i++){
	    scanf("%s", s);
	    if(sscanf(s, "%d", next + i) == 0){
		next[i] = LOSE;
	    }
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i = 0; i <= t; i++)
	    for(int j = 0; j <= m; j++)
		for(int k = 1; k <= 2; k++){
		    int where = j + k;
		    if(where > m + 1) where = m + 1;
		    if(next[where] == LOSE){
			dp[i + 2][where] += dp[i][j] * 0.5;
		    }else{
			where = where + next[where];
			if(where > m + 1) where = m + 1;
			if(where < 0) where = 0;
			dp[i + 1][where] += dp[i][j] * 0.5;
		    }
		}
	double ans = 0; 
	for(int i = 0; i <= t; i++)
	    ans += dp[i][m + 1];
	if(ans > 0.5){
	    printf("Bet for. %0.4lf\n", ans);
	}else if(ans < 0.5){
	    printf("Bet against. %0.4lf\n", ans);
	}else{
	    puts("Push. 0.5000");
	}
    }
    return 0;
}
