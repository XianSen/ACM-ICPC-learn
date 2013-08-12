#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int tt;
    scanf("%d", &tt);
    for(int kcase = 1; kcase <= tt; kcase++){
	double d, v, u;
	scanf("%lf%lf%lf", &d, &v, &u);
	printf("Case %d: ", kcase);
	if(v >= u || u <= 1e-6 || v <= 1e-6)
	    puts("can't determine");
	else{
	    double t1 = d / u;
	    double v2 = sqrt(u * u - v * v);
	    double t2 = d / v2;
	    double t = t2 - t1;
	    printf("%0.3lf\n", t);
	}
    }
    return 0;
}
