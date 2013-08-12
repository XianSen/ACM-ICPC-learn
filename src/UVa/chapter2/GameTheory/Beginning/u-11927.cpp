#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int MAXN = 1100;

int sg[MAXN];
vector<int> g[MAXN];

int mex(vector<int> & g){
    if(g.size() == 0) return 0;
    sort(g.begin(), g.end());

    if(g[0] != 0) return 0;
    for(int i = 1; i < g.size(); i++)
	if(g[i] > g[i - 1] + 1)
	    return g[i - 1] + 1;

    return g[g.size()-1] + 1;
}

int SG(int n){
    if(sg[n] != -1) return sg[n];

    vector<int> min;
    for(int i = 0; i < g[n].size(); i++)
	min.push_back(SG(g[n][i]));

    sg[n] = mex(min);
    return sg[n];
}

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
	memset(sg, -1, sizeof(sg));
	if(n == 0 && m == 0) break;

	for(int i = 0; i <= n; i++)
	    g[i].clear();

	for(int i = 0; i < m; i++){
	    int a, b;
	    scanf("%d%d", &a, &b);
	    g[a].push_back(b);
	}

	int s, result = 0;
	for(int i = 0; i < n; i++){
	    scanf("%d", &s);
	    if(s & 1) result ^= SG(i);
	}

	puts(result ? "First" : "Second");
    }
    return 0;
}
