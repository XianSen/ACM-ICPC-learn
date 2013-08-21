#include <math.h>
#include <stdio.h>
#include <string.h>

const int MAXN = 110001;
double f[MAXN + 1];

int main(){
    int tt, n;
    double log2 = log(0.5);

    f[0] = log(1);
    for(int i = 1; i < MAXN; i++)
	f[i] = f[i - 1] + log(i);

    scanf("%d", &tt);
    while(tt > 0){
	tt--;
	scanf("%d", &n);
	int b = n / 2 - 1;
	int a = n - 2;
	double l = f[a] - f[b] - f[a - b] + a * log2;
	double ans = exp(l);
	ans = 1 - ans;
	printf("%0.4lf\n", ans);
    }
    return 0;
}
