/*精度问题*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxn = 1100000;
const double MIN = 0.000001;

double r[maxn];
int n, f, cas;

bool can(double size){
    int sum = 0;
    if(abs(size) < MIN)
	return true;
    for(int i = 0; i < n; i++){
	sum += (int)( (r[i] / (size * 1.0)) );
	if(sum >= f) break;
    }

    return (sum >=f );
}

int main(){
    double sum = 0;
    scanf("%d", &cas);
    while(scanf("%d%d",&n, &f) != EOF){

	double pi = acos(-1.0);

	sum = 0;
	f += 1;

	for(int i = 0; i < n; i++){
	    int value;
	    scanf("%d", &value);
	    r[i] = value*1.0*value;
	    sum += r[i];
	}

	double l = 0, r = ((sum + 0.1) / f), mid;

	while(r > l && r - l > MIN){
	    mid = (l + r) / 2.0;
	    if(can(mid)) l = mid + MIN;
	    else r = mid - MIN;
	}
	
	printf("%0.4lf\n", r*pi);
    }
    return 0;
}
