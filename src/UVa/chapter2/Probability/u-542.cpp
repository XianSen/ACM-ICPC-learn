#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 100;

int who[MAXN];
double dp[MAXN];
double ans[MAXN];
double p[MAXN][MAXN];
char name[MAXN][MAXN];

void calc(int now){
    if(now == 0) 
	ans[who[1]] += dp[1];
    else{
	int left = now * 2;
	int right = now * 2 + 1;
	//选择left
	who[now] = who[left];
	dp[now] = dp[left] * dp[right] * p[who[left]][who[right]];

	calc(now - 1);
	//选择right
	who[now] = who[right];
	dp[now] = dp[left] * dp[right] * p[who[right]][who[left]];
	calc(now - 1);
    }
}

int main(){
    int n = 16;
    for(int i = 1; i <= n; i++)
	scanf("%s", name[i]);
    for(int i = 1; i <= n; i++){
	who[15 + i] = i;
	dp[15 + i] = 1.0;
    }
    for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++){
	    scanf("%lf", &p[i][j]);
	    p[i][j] /= 100.0;
	}
    memset(ans, 0, sizeof(ans));
    calc(15);
    for(int i = 1; i <= n; i++)
	printf("%-10s p=%0.2lf%%\n", name[i], ans[i] * 100);
    return 0;
}
