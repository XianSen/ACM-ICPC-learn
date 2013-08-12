#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 100;
int dp[i][j];
int mat[MAXN][MAXN];

int main(){
    int i, j, n;
    for(int i = 0; i < n; i ++)
	for(int j = 0; j < n; j++)
	    scanf("%d",&mat[i][j]);
    
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++){
	}
    return 0;
}
