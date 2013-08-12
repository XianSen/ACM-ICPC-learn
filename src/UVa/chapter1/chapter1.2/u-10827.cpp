//u-10827
#include <deque>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using std::deque;

const int MAXN = 80;
int n;
int sum[MAXN];
int mat[MAXN * 2][MAXN * 2];

struct Pair{
    int key;
    int val;
};

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
	scanf("%d", &n);	
	memset(mat, 0, sizeof(mat));
	for(int i = 1; i <= n; i++)
	    for(int j = 1; j <= n; j++)
		scanf("%d", &mat[i][j]);
	for(int i = 1; i <= 2 * n; i++)
	    for(int j = 1; j <= 2 * n; j++){
		int u = i;
		int v = j;
		if(u > n) u = i - n;
		if(v > n) v = j - n;
		if(i != u || j != v)
		    mat[i][j] = mat[u][v];
	    }

	for(int i = 1; i <= 2 * n; i++)
	    for(int j = 1; j <= 2 * n; j++)
		mat[i][j] += mat[i-1][j];	

	int ans = -2147483647;

	for(int i = 1; i <= n; i++){
	    for(int j = i; j <= 2 * n && j - i + 1 <= n; j++){
		int lastSum = 0;
		deque<Pair> que;

		for(int k = 1; k <= 2 * n; k++){
		    while(!que.empty() && que.back().val >= lastSum){
			que.pop_back();
		    }

		    que.push_back((Pair){k, lastSum});

		    while(!que.empty() && k - que.front().key + 1 > n)
			que.pop_front();

		    lastSum += mat[j][k] - mat[i-1][k];
		    if(lastSum - que.front().val > ans) 
			ans = lastSum - que.front().val;
		}
	    }
	}

	printf("%d\n", ans);
    }
    return 0;
}
