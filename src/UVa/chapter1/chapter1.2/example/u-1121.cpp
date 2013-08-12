#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 110000;

int n, s;
int sum[MAXN];

bool check(int len){
    if(len == n + 1) return true; 
    for(int i = len; i <= n; i++)
	if(sum[i] - sum[i - len] >= s)
	    return true;
    return false;
}

int main(){
    while(scanf("%d%d", &n, &s) != EOF){
	sum[0] = 0;
	for(int i = 1; i <= n; i++)
	    scanf("%d", sum + i);
	for(int i = 1; i <= n; i++)
	    sum[i] += sum[i-1];

	int ans = n + 1;
	int left = 0;
	int right = n + 1;

	while(left <= right){
	    int mid = left + (right - left)/2;
	    if(check(mid)){
		if(mid < ans) ans = mid;
		right = mid - 1;
	    }else{
		left = mid + 1;
	    }
	}

	if(ans == n + 1) ans = 0; 
	printf("%d\n", ans);
    }
    return 0;
}
