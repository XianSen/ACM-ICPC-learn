#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
const int MAXN = 1100;
int n;
char s[MAXN];
int dp[MAXN];
int isPalindrome[MAXN][MAXN];

int main(){
    int kcase;
    scanf("%d", &kcase);
    getchar();
    while(kcase--){
	n = 0;
	char c;
	while((c = getchar()) != '\n')
	    s[n++] = c;
	memset(isPalindrome, 0, sizeof(isPalindrome));
	for(int i = 0; i < n; i++)
	    isPalindrome[i][i] = 1;
s[n] = 0;
	for(int i = 1; i < n; i++)
	    if(s[i] == s[i-1])
		isPalindrome[i-1][i] = 1;
	    else
		isPalindrome[i-1][i] = 0;

	for(int L = 2; L <= n; L++)
	    for(int i = 0; i + L < n; i++){
		int j = i + L;
		if(s[i] == s[j] && isPalindrome[i + 1][j-1])
		    isPalindrome[i][j] = 1;
		else
		    isPalindrome[i][j] = 0;
	    }
/*
	for(int i = 0; i < n; i++){
	    for(int j = i; j < n; j++)
		printf("%d ", isPalindrome[i][j]);
	    printf("\n");
	}
	*/

	memset(dp, 0x7f, sizeof(dp));
	dp[0] = 0;
	for(int i = 0; i < n; i++){
	    dp[i] = i + 1;
	    if(isPalindrome[0][i])
		dp[i] = 1;
	    else
		for(int j = 1; j <= i; j++)
		    if(isPalindrome[j][i])
			dp[i] = min(dp[i], dp[j-1] + 1);
	}

	printf("%d\n", dp[n-1]);
    }
    return 0;
}
