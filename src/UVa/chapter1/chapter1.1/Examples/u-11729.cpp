#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 1100;

struct Sold{
    int b;
    int j;
    bool operator<(const Sold & s)const{
	return (j > s.j);
    }
}sold[maxn];

int main(){
    int i, j, n, ans, sum, cas = 0;
    while(~scanf("%d",&n) && n){
	for(i = 0; i < n; i++){
	    scanf("%d%d",&sold[i].b, &sold[i].j);
	}
	sort(sold,sold+n);
	ans = sum = 0;
	for(i = 0; i < n; i++){
	    sum += sold[i].b;
	    if(sum + sold[i].j > ans)
		ans = sum + sold[i].j;
	}
	printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
