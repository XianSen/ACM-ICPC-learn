#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 200;
int g[MAXN][MAXN];

int main(){
    int tt;
    scanf("%d", &tt);
    for(int kcase = 1; kcase <= tt; kcase++){
	int n, m;
	memset(g, 0, sizeof(g));
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
	    scanf("%d%d", &u, &v);
	    g[u][v] = g[v][u] = 1;
	}
    }
    return 0;
}
