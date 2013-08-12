#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
const int MAXN = 11000;
const int MAXM = 30;

int n, k;
char s[MAXN];
int size[MAXN];
int dp[MAXN][MAXM];
int word[MAXN][MAXM];

int main(){
    int kcase;
    scanf("%d", &kcase);
    getchar();

    while(kcase--){
	scanf("%d %s", &k, s);
	getchar();

	int n = strlen(s);
	memset(size, 0, sizeof(size));	
	memset(word, 0, sizeof(word));

	for(int i = 0; i < n/k; i++){
	    int begin = i * k;
	    for(int j = 0; j < k; j++){
		printf("");
		if(word[i][s[begin+j] - 'a'] == 0){
		    size[i]++;
		    word[i][s[begin+j] - 'a'] = 1;
		}
	    }
	}

	memset(dp, 0x7f, sizeof(dp));
	for(int i = 0; i < 26; i++){
	    if(word[0][i])
		dp[0][i] = size[0];
	}
//printf("%d %d\n", size[0], size[1]);

	for(int i = 1; i < n/k; i++)
	    if(size[i] == 1){
		int who = 0;
		for(int j = 0; j < 26; j++)
		    if(word[i][j]){
			who = j;
			break;
		    }
		for(int j = 0; j < 26; j++)
		    if(who == j)
			dp[i][who] = min(dp[i-1][j], dp[i][who]);
		    else
			dp[i][who] = min(dp[i-1][j]+1, dp[i][who]);
	    }else{
//		printf("%d\n", size[i]);
		for(int j = 0; j < 26; j++)
		    for(int k = 0; k < 26; k++)
			if(j != k && word[i][k]){
			    if(word[i][j]){
				dp[i][k] = min(dp[i][k], dp[i-1][j] + size[i] - 1);
			    }
			    else
				dp[i][k] = min(dp[i][k], dp[i-1][j] + size[i]);
			}
	    }


	int ans = 2147483647;
	int final = n/k - 1;

	for(int i = 0; i < 26; i++){
//	    printf("%d ", dp[final][i]);
	    if(dp[final][i] < ans)
		ans = dp[final][i];
	}

	printf("%d\n", ans);
    }
    return 0;
}
