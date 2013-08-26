#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 20;
double sum = 0;
int num[MAXN];
double mat[MAXN][MAXN];

//who是现在轮到谁选择
//p是走到现在的概率
void dfs(int who, double p){
    if(who == 0){
	sum += p;
    } else{
	for(int i = 1; i <= 5; i++)
	    if(num[i] > 0){
		num[i]--;
		dfs(who - 1, p * mat[who][i]);
		num[i]++;
	    }
    }
}

int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= 5; i++)
	    scanf("%d", &num[i]);

	for(int i = n; i >= 1; i--)
	    for(int j = 1; j <= 5; j++)
		scanf("%lf", &mat[i][j]);

	int ans1 = -1;
	double ans2 = -100;
	double pb = 0, pa = 0;

	sum = 0.0;
	dfs(n, 1.0);
	pb = sum;

	for(int i = 1; i <= 5; i++){
	    sum = 0.0;
	    if(num[i] == 0) continue;
	    num[i]--;
	    dfs(n - 1, mat[n][i] / (num[i] + 1));
	    num[i]++;
	    pa = sum / pb;
	    if(pa > ans2){
		ans1 = i;
		ans2 = pa;
	    }
	}
	printf("%d %0.3lf\n", ans1, ans2);
    }
    return 0;
}
