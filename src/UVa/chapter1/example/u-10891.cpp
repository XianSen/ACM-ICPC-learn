#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

const int MAXN = 110;
using std::min;

int s[MAXN];
int num[MAXN];
int f[MAXN][MAXN];
int g[MAXN][MAXN];
int d[MAXN][MAXN];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;
	for(int i = 1; i <= n; i++)
	    scanf("%d", num + i);

	s[0] = 0;
	for(int i = 1; i <= n; i++)
	    s[i] = s[i-1] + num[i];

	for(int i = 1; i <= n; i++)
	    f[i][i] = g[i][i] = d[i][i] = num[i];

	for(int L = 1; L < n; L++)
	    for(int i = 1; i + L <= n; i++){
		int j = i + L;
		int m = 0;
		m = min(f[i+1][j], m);
		m = min(g[i][j-1], m);
		d[i][j] = s[j] - s[i-1] - m;
		f[i][j] = min(f[i+1][j], d[i][j]);
		g[i][j] = min(g[i][j-1], d[i][j]);
	    }
	printf("%d\n", 2 * d[1][n] - s[n]);
    }
    return 0;
}
