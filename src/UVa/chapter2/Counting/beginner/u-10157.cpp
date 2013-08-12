#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 155;
const int MAXM = 155;

int d[MAXN][MAXM];
//d[i][j] 代表结点个数为i, 高度为j的树的个数

int f[MAXN][MAXM];
//f[i][j] 代表结点个数为i, 高度不大于j的树的个数

void init(){
    memset(d, 0, sizeof(d));
    memset(f, 0, sizeof(f));

    d[0][0] = 1;
    f[0][0] = 1;

    int n = MAXN - 1;
    for(int node = 1; node <= n; node++)
	for(int h = 1; h <= node; h++){
	    //TODO
	}
}

int main(){
    int n, d;
    init();
    while(scanf("%d%d", &n, &d) != EOF){

    }
    return 0;
}

