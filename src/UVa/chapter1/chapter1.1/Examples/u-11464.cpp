#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using std::swap;

int n;
const int maxn = 15;
int test[maxn];
int mat[maxn][maxn];
int now[maxn][maxn];

int getOld(int);
int getChange();

int main(){
    int t, now, ans;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	    for(int j = 0; j < n; j++)
		scanf("%d", &mat[i][j]);
	ans = -1;
	int sum = (1 << n);
	for(int i = 0; i < sum; i++){
	    int cost1 = getOld(i); 
	    if(cost1 == -1) continue;
	    int cost2 = getChange(); 
	    if(cost2 == -1) continue;
	    if(cost1 + cost2 < ans || ans == -1)
		ans = cost1 + cost2;
	}
	printf("Case %d: %d\n", cas, ans);
    }
}

int getOld(int status){
    for(int i = 0; i < n; i++){
	test[i] = status & 1;
	status >>= 1;
    }
    int cost = 0;
    for(int i = 0; i < n; i++)
	if(mat[0][i] == 1 && test[i] == 0)
	    return -1;
	else if(mat[0][i] == 0 && test[i] == 1)
	    cost ++;
    return cost;
}

int calc(int x, int y){
    int cost = 0;
    if(x > 0) cost += now[x-1][y];
    if(y > 0) cost += now[x][y-1];
    if(y < n - 1) cost += now[x][y+1];
    return (cost % 2);
}

int getChange(){
    int cost = 0;
    for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++)
	    now[i][j] = mat[i][j];
    for(int i = 0; i < n; i++)
	now[0][i] = test[i];
    for(int i = 1; i < n; i++){
	for(int j = 0; j < n; j++){
	    int tmp = calc(i-1, j);
	    if(now[i][j] == 1 && tmp == 0)
		return -1;
	    if(now[i][j] == 0 && tmp == 1){
		cost ++;
		now[i][j] = 1;
	    }
	}
    }
    for(int i = 0; i < n; i++)
	if(calc(n-1, i) != 0)
	    return -1;
    return cost;
}
