#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 1100;
char s[MAXN];
char ans[MAXN];
int w[MAXN][MAXN];
int dp[MAXN][MAXN];

int main(){
    while(~scanf("%s", s)){
	int n = strlen(s);
	if(n == 0){
	    for(int i = 0; i >= 0; i++);
	    break;
	}
	memset(dp, 0, sizeof(dp));

	for(int i = 0; i < n; i++){
	    dp[i][i] = 1;
	    w[i][i] = i;
	}

	for(int i = 1; i < n; i++)
	    if(s[i] == s[i-1]){
		dp[i-1][i] = 2;
		w[i-1][i] = i - 1;
	    }else{
		dp[i-1][i] = 1;
		if(s[i-1] <= s[i]){
		    w[i-1][i] = i-1;
		}else{
		    w[i-1][i] = i;
		}
	    }
	
	for(int L = 3; L <= n; L++)
	    for(int i = 0; i + L - 1 < n; i++){
		int j = i + L - 1;
		if(s[i] == s[j]){
		    dp[i][j] = dp[i+1][j-1] + 2;
		    w[i][j] = i;
		}else if(dp[i+1][j] > dp[i][j-1] || 
			(dp[i+1][j] == dp[i][j-1] && s[i] >= s[j])){
		    dp[i][j] = dp[i+1][j];
		    w[i][j] = w[i+1][j];
		}else{
		    dp[i][j] = dp[i][j-1];
		    w[i][j] = w[i][j-1];
		}
	    }

	int begin = 0;
	int end = dp[0][n-1] - 1;
	int first = 0;
	int second = n - 1;
	ans[end+1] = 0;

	while(begin <= end && first <= second){
	    if(w[first][second] != first){
		first += 1;
	    }else {
		while(s[second] != s[first])
		    second--;
		ans[begin++] = s[first];
		ans[end--] = s[first];
		first++,second--;
	    }
	}
	printf("%s\n", ans);
    }
    return 0;
}
