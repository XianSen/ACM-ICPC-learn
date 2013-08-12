#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN= 110000;
int sum[MAXN];
int score[MAXN];

int main(){
    int n, t;
    scanf("%d", &t);
    while(scanf("%d", &n) != EOF){
	for(int i = 0; i < n; i++)
	    scanf("%d", score + i);
	for(int i = 0; i < n - 1; i++)
	    sum[i] = score[i] - score[i+1];

	int ans = -2147483647; 
	int max = -2147483643;

	for(int i = 0; i < n - 1; i++)
	    if(sum[i] > max) max = sum[i];

	if(max > 0){
	    int val = 0;
	    for(int i = 0; i < n - 1; i++){
		val += sum[i];
		if(val > ans) ans = val;
		if(val < 0) val = 0;
	    }
	}else{
	    ans = max;
	}
	printf("%d\n", ans);
    }
    return 0;
}
