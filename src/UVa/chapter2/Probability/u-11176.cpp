#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 600;
double f[MAXN][MAXN];

double pow(double p, int n){
    if(n == 0) return 1;
    double result = pow(p, n >> 1);
    result *= result;
    if(n & 1) result *= p;
    return result;
}

int main(){
    int n;
    double p;
    while(scanf("%d%lf", &n, &p) == 2){
	if(n == 0) break;
	double ans = 0;
	f[0][0] = 1.0;
	for(int i = 1; i <= n; i++)
	    f[0][i] = 1.0;
	for(int i = 1; i <= n; i++)
	    for(int j = 0; j <= n; j++){
		f[i][j] = f[i - 1][j];
		if(i == j + 1){
		    f[i][j] -= pow(p, i);
		}else if(i > j + 1){
		    f[i][j] -= pow(p, j + 1) * (1 - p) * f[i - j - 2][j];
		}
	    }

	for(int i = 1; i <= n; i++)
	    ans += i * (f[n][i] - f[n][i - 1]);
	printf("%0.6lf\n", ans);
    }
    return 0;
}
