#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 13;
int count[10];
int num[MAXN];

typedef unsigned long long LL;

LL fact(int n){
    LL ans = 1;
    for(int i = 1; i <= n; i++)
	ans = ans * i;
    return ans;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;
	LL ans = 0;
	for(int i = 0; i < n; i++)
	    scanf("%d",num + i);
	memset(count, 0, sizeof(count));
	for(int i = 0; i < n; i++)
	    count[num[i]]++;

	
	LL pow = 1;
	LL F = fact(n - 1);
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < 10; j++)
		if(count[j] != 0){
		    count[j] = count[j] - 1;
		    LL f = F;
		    for(int k = 0; k < 10; k++)
			if(count[k] != 1 && count[k] != 0)
			    f = f / fact(count[k]);
		    ans += j * pow * f;
		    count[j] = count[j] + 1;
		}
	    pow *= 10;
	}
	printf("%llu\n", ans);
    }
    return 0;
}
