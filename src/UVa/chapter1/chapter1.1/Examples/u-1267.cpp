#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using std::vector;

const int maxn = 2000;

vector<int> gr[maxn], nodes[maxn];
int n, s, k, fa[maxn];
bool covered[maxn];

int change(int root, int father, int d){
   fa[root] = father; 
   int nr = gr[root].size();
   if(nr == 1 && d > k) nodes[d].push_back(root);
   for(int i = 0; i < nr; i++){
       int v = gr[root][i];
       if(v != father) change(v, root, d + 1);
   }
}

/* come to root is d*/
void cover(int root, int father, int d){
    covered[root] = true;
    int nr = gr[root].size();
    for(int i = 0; i < nr; i++){
	int v = gr[root][i];
	if(v != father && d < k) cover(v, root, d+1);
    }
}

int solve(){
    int ans = 0;
    memset(covered, false, sizeof(covered));
    for(int d = n - 1; d > k; d--){
	for(int i = 0; i < nodes[d].size(); i++){
	    int u = nodes[d][i];
	    if(covered[u]) continue;
	    int v = u;
	    for(int j = 0; j < k; j++) v = fa[v];
	    cover(v, -1, 0);
	    ans++;
	}
    }
    return ans;
}

int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
	scanf("%d%d%d", &n, &s, &k);
	for(int i = 0; i < maxn; i++){
	    gr[i].clear();
	    nodes[i].clear();
	}

	for(int i = 1; i < n; i++){
	    int a, b;
	    scanf("%d%d", &a, &b);
	    gr[a].push_back(b);
	    gr[b].push_back(a);
	}

	change(s, -1, 0);
	printf("%d\n", solve());
    }
    return 0;
}
