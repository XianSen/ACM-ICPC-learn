#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using std::max;
using std::min;

const int maxn = 201000;
int n, ans;

int l[maxn];
int r[maxn];
int req[maxn];

bool test(int m){
    int x = req[0], y = m - req[0];
    l[0] = x, r[0] = 0;

    for(int i = 1; i < n; i++)
	if(i % 2 == 0){
	    r[i] = min(req[i], y - r[i-1]);//拿右边的礼物
	    l[i] = req[i] - r[i];
	}else{
	    l[i] = min(req[i], x - l[i-1]);//拿左边的礼物
	    r[i] = req[i] - l[i];
	}

    return (l[n-1] == 0);
}

int main(){
    while(scanf("%d", &n) != EOF && n){
	ans = 0;
	for(int i = 0; i < n; i++)
	    scanf("%d", req+i);

	int l = 0, r = 0;  	    
	for(int i = 0; i < n; i++)
	    l = max(l, req[i] + req[(i + 1) % n]);

	for(int i = 0; i < n; i++)
	    r = max(r, req[i]*3);

	if(n % 2 == 1){
	    while(l < r){
		int m = l + (r - l) / 2; 
		if(test(m)) r = m;
		else l = m + 1;
	    }
	}

	if(n == 1) l = req[0];

	printf("%d\n", l);
    }
    return 0; 
}
