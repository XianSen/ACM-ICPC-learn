#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
	double ans = 0;
	for(int i = 1; i < n; i++){
	    double pos = (double)i*(n+m)/n;
	    ans += fabs(pos - floor(pos + 0.5))/(n+m);
	}
	printf("%0.4lf\n",ans*10000);
    }
    return 0;
}
