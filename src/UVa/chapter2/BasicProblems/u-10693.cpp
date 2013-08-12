#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int l, f;
    while(scanf("%d%d", &l, &f) != EOF){
	if(l == 0 && f == 0) break;
	double v = sqrt(2 * f * l);
	double n = (v /  (v * v / (2 * f) + l)) * 3600;
	printf("%0.8lf %0.8lf\n", v, n);
    }
    return 0;
}
