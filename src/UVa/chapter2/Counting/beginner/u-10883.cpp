#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 52000;
double num[MAXN];

int main(){
    int kcase;
    scanf("%d", &kcase);
    for(int tcase = 1; tcase <= kcase; tcase++){
	int n;
	double ans = 0;

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	    scanf("%lf", num + i);

	double c = 0.0;

	for(int i = 0; i < n; i++){
	    if(num[i] > 0){     
		double now = log(num[i]) + c - (n - 1) * log(2);
		ans += exp(now);
	    }else{
		double now = log(-num[i]) + c - (n - 1) * log(2);
		ans -= exp(now);
	    }
	    c = c + log(n - 1.0 - i) - log(i + 1);
	}
	
	printf("Case #%d: %0.3lf\n",tcase, ans);
    }
    return 0;
}
