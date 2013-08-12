#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FORE2(i) for(int i = 0; i < 2; i++)

const int MAXN = 31;
int f[MAXN];
int dp[2][2][MAXN];

int main(){
    int n;

    memset(f, 0, sizeof(f));
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < 2; i++)
	for(int j = 0; j < 2; j++)
	    dp[i][j][2] = 1;

    for(int k = 3; k < MAXN; k++)
	FORE2(i) FORE2(j) FORE2(l)
	    if(!(i == 0 && j == 0 && l == 0))
		dp[j][l][k] += dp[i][j][k - 1];

    f[1] = 2;
    for(int i = 2; i < MAXN; i++)
	FORE2(j) FORE2(k)
	    f[i] += dp[j][k][i];

    for(int i = 1; i < MAXN; i++)
	f[i] = (1 << i) - f[i];

    while(scanf("%d", &n) != EOF){
	if(n == 0) break;
	printf("%d\n", f[n]);
    }
    return 0;
}
