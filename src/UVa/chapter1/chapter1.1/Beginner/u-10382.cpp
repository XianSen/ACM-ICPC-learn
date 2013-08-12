#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 21000;

typedef struct Sprinkler{
    double l;
    double r;
    bool operator<(const Sprinkler s) const{ 
	if(l < s.l) return true;	
	return false;
    }
}Sprinkler;

Sprinkler sprinkler[maxn];

int main(){
    int i, j, n1, n, l, w, pos, radius;
    while(scanf("%d%d%d",&n1, &l, &w) != EOF){
	n = 0;

	//l*l, w*w超过整型
	for(i = 0; i < n1; i++){
	    scanf("%d%d", &pos, &radius);
	    if(radius * 2.0 >= w) {
		double tmp = sqrt(radius*1.0*radius - w*1.0*w/4.0);
		sprinkler[n].l = pos -  tmp;
		sprinkler[n].r = pos +  tmp;
		n++;
	    }
	}

	sort(sprinkler, sprinkler+n);

	int ans = 0;
	double max = 0;
	i = 0;

	int ok = 0;
	while(i < n){
	    ok = 0;
	    double nowmax = max;

	    while(sprinkler[i].l <= max && i < n){
		if(sprinkler[i].r >= nowmax){
		    nowmax = sprinkler[i].r;
		    ok = 1;
		}
		i++;
	    }

	    if(!ok) break;
	    ans++;
	    max = nowmax;
	    if(max >= l) break;
	}

	if(max < l) ans = -1;
	printf("%d\n", ans);
    }
    return 0;
}
