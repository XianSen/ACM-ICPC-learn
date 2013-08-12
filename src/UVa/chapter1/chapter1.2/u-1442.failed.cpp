#include <deque>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int MAXN = 1100000;
const int INF = 2147483640;

int l[MAXN]; 
int h[MAXN]; 
int sum[MAXN];

int main(){
    int z;
    scanf("%d", &z);
    while(z--){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	    scanf("%d", l + i);

	for(int i = 1; i <= n; i++){
	    scanf("%d", h + i);
	    h[i] = h[i] - 1;
	}
	
	sum[0] = 0;
	for(int i = 1; i <= n; i++)
	    sum[i] = sum[i-1] + l[i];
	l[0] = h[0] = INF;
	h[n + 1] = l[n + 1] = INF;
	n = n + 1;

	deque<int> last;
	deque<int> minh;
	deque<int> maxl;

	last.push_back(0);
	minh.push_back(INF);
	maxl.push_back(INF);

	int ans = 0;
	for(int i = 1; i <= n; i++){
	    while(l[last.back()] < l[i]){
		int suml = sum[i - 1] - sum[last.back() - 1];
		int area = i - last.back();
		int hm = minh.back();
		last.pop_back();
		minh.pop_back();

		if(hm >= maxl.back()){
		    int d= min( (min(l[i],hm)), l[last.back()]);
		    area *= d;
		    if(ans < area - suml) ans = area - suml;
		}

		int lma = maxl.back();	
		maxl.pop_back();
		maxl.back() = max(maxl.back(), lma);
		minh.back() = min(minh.back(), hm);
	    }
	    if(l[last.back()] == l[i]){
		minh.back() = min(minh.back(), h[i]);
	    }else{
	    }
	}
	printf("%d\n", ans);
    }
    return 0;
}
