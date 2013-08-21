#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
	double a, b, s;
	scanf("%lf%lf%lf",&a, &b, &s);
	double ans = 0;
	if(s < a * b){
	    double area1 = 0;//s * log(a) - s*log(s / b);
	    if(s / b > 0)
		area1 = s * log(a) - s * log(s / b);
	    double area2 = b * (a - s / b);
	    ans = (area2 - area1) / (a * b); 
	}
	printf("%.6lf%%\n", ans * 100);
    }
    return 0;
}
