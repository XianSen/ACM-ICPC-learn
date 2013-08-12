#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
const int MAXN = 1100;
const int MAXM = 2;
const int INF = 2000;

vector<int> adj[MAXN];
int n, m;
int dp[MAXN][MAXM];
int vist[MAXN][MAXM];

int treedp(int root, int status, int f){
    if(vist[root][status])
	return dp[root][status];

    int &ans = dp[root][status];
    vist[root][status] = 1;

    ans = INF;//root place lamp
    for(int i = 0; i < adj[root].size(); i++)
	if(adj[root][i] != f)
	    ans += treedp(adj[root][i], 1, root);
    if(!status && f >= 0) ans++;

    //root not place lamp
    if(status || f < 0){
	int sum = 0;
	for(int i = 0; i < adj[root].size(); i++)
	    if(adj[root][i] != f)
		sum += treedp(adj[root][i], 0, root);
//	if(status) sum++;
	if(f >= 0) sum++;
	ans = min(ans, sum);		
    }

    return ans;
}

int main(){
    int cases;
    scanf("%d", &cases);
    while(cases--){
	scanf("%d%d", &n, &m);
	for(int i = 0; i <= n; i++)
	    adj[i].clear();
	for(int i = 0; i < m; i++){
	    int a, b;
	    scanf("%d%d", &a, &b);
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}

	memset(vist, 0, sizeof(vist));

	int ans = 0;
	for(int i = 0; i < n; i++)
	    if(!vist[i][0])
		ans += treedp(i, 0, -1);
//printf("%d %d\n", m, ans);
	printf("%d %d %d\n", ans / INF, m - ans % INF, ans % INF);
    }
    return 0;
}
