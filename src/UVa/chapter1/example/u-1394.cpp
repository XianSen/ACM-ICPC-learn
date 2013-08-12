#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 12000;
int f[MAXN];

int main(){
    int n, k, m;
    while(scanf("%d%d%d", &n, &k, &m) != EOF){
	if(n == 0 && k == 0 && m == 0) break;
	f[1] = 0;
	for(int i = 2;  i < n; i++)
	    f[i] = (f[i-1] + k) % i;
	int ans = (f[n - 1] + m) % n;
	printf("%d\n", ans + 1);
    }
    return 0;
}
