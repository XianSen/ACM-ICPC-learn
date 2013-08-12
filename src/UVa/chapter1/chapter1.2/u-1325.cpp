#include <cmath>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#define DIS(x,y) (((x)-(y))*((x)-(y)))

const int MAXN = 1100;
using namespace std;

int n;
double minDouble = 1e-5;

struct Planet{
    int x;
    int y;
    int z;
    int p;
}planet[MAXN];

int same[MAXN];
int diffence[MAXN];

inline double dis(int a, int b){
    return ( DIS(planet[a].x, planet[b].x)+
	    DIS(planet[a].y, planet[b].y)+
	    DIS(planet[a].z, planet[b].z));
}

struct Dist{
    int x;
    int y;
    double val;
    bool operator<(const Dist& d)const{
	return val < d.val;
    }
}dist[MAXN * MAXN];

int main(){
    while(scanf("%d", &n) != EOF){
	for(int i = 0; i < n; i++){
	    scanf("%d%d",&planet[i].x, &planet[i].y);
	    scanf("%d%d",&planet[i].z, &planet[i].p);
	}

	int sum = 0;

	for(int i = 0; i < n; i++)
	    for(int j = i + 1; j < n; j++){
		dist[sum].x = i;
		dist[sum].y = j;
		dist[sum].val = dis(i, j);
		sum++;
	    }

	memset(diffence, 0, sizeof(diffence));
	for(int i = 0; i < n; i++)
	    same[i] = 1;

	int now = 0;
	for(int i = 0; i < n; i++)
	    if(same[i] < diffence[i])
		now++;

	int maxSum = now;
	int mindis = 0;

	sort(dist, dist+sum);

	int i = 0, j;
	for(i = 0; i < sum; i++){
	    int s = i;
	    int tmp = dist[i].val;
	    for(j = i; j < sum && dist[j].val == tmp; j++) {
		    s = j;
		    int x = dist[j].x;
		    int y = dist[j].y;
		    if(same[x] < diffence[x]) now--;
		    if(same[y] < diffence[y]) now--;
		    if(planet[x].p == planet[y].p){
			same[x]++,same[y]++;
		    }else{
			diffence[x]++,diffence[y]++;
		    }
		    if(same[x] < diffence[x]) now++;
		    if(same[y] < diffence[y]) now++;
		}
	    i = s;
	    if(now > maxSum){
		maxSum = now;
		mindis = tmp;
	    }
	    if(maxSum == n) break;
	}

	printf("%d\n%0.4lf\n", maxSum, sqrt(mindis));
    }
    return 0;
}
