#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;
typedef long long LL;

int n, k;

int num[100];
int next(int n, int k){
    if(k == 0) return 0;
    LL k2 = (LL)k * (LL)k;
    num[0] = 0; 
    while(k2 != 0){
	num[++num[0]] = k2 % 10;
	k2 = k2 / 10;
    }

    if(n > num[0]) n = num[0]; 
    int result = 0;
    for(int i = num[0]; i >= num[0] - n + 1; i--)
	result = result * 10 + num[i];
    return result;
}

int main(){
    int t;
    scanf("%d", &t);
    while(scanf("%d%d", &n, &k) != EOF){
	int ans = k;
	int k1 = k, k2 = k;
	do{
	    k1 = next(n, k1);
	    k2 = next(n, k2);
	    ans = max(ans, k2);
	    k2 = next(n, k2);
	    ans = max(ans, k2);
	}while(k1 != k2);
	printf("%d\n", ans);
    }
    return 0;
}
