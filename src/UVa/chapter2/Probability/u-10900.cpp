#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 32;
//a[i]代表正确回答了剩下i题的期望
double a[MAXN];

int main(){
    int n;
    double t;
    while(scanf("%d%lf", &n, &t) == 2){
	if(n == 0 && t == 0) break;
	a[n] = (1 << n);	
	for(int i = n - 1; i >= 0; i--){
	    int value = (1 << i);
	    double ep = value / a[i + 1];
	    if(ep < t){
		a[i] = (1 + t)/2.0 * a[i + 1];
	    }else{
		a[i] = (ep - t) / (1 - t) * value +
		       (1 - ep) / (1 - t) * (1 + ep)/2.0 * a[i+1];
	    }
	}
	printf("%0.3lf\n", a[0]);
    }
    return 0;
}
