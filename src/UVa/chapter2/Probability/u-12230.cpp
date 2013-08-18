#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n, d, tt = 0;
    while(scanf("%d%d", &n, &d) != EOF){
	if(n == 0 && d == 0) break;
	printf("Case %d: ", ++tt);
	double t = 0;		
	int sum = 0;
	for(int i = 0; i < n; i++){
	    int p, l, v;
	    scanf("%d%d%d", &p, &l, &v);
	    sum += l;
	    t += l * 2.0 / v;
	}
	t += d - sum;
	printf("%0.3lf\n\n", t);
    }
    return 0;
}
