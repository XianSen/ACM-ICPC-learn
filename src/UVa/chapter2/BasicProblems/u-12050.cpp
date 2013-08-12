#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 19 + 1;
const int MAXM = 19;

typedef unsigned long long LL;

LL f[MAXN];

LL calc_one(int n){
    if(n % 2 == 0){
	if(n == 0) return 0;	
	if(n == 2) return 9;
	LL ans = 9;
	for(int i = 1; i < n/2; i++)
	    ans = ans * 10;
	return ans;
    }else{
	if(n == 1) return 9;
	LL ans = 10 * calc_one(n - 1);
	return ans;
    }
}

void init(){
    f[0] = 0;
    int n = MAXM;
    for(int i = 1; i <= n; i++)
	f[i] = f[i - 1] + calc_one(i);
}

int length(int n){
    for(int i = 1; i <=	MAXM; i++)
	if(f[i - 1] < n && f[i] >= n)
	    return i;
    return MAXM;
}

int num[100];

//对n == 0进行特判
int calc_two(int n){
    int ans = 1;
    n = (n + 1) / 2;
    for(int i = 1; i <= n; i++)
	ans = ans * 10;
    return ans;
}

int main(){
    int n;
    init();
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;
	int l = length(n);	
	int now = f[l - 1];

	int len = l;
	for(int i = 1; i <= (l + 1) / 2; i++){
	    int min = 0;   

	    len = len - 2;
	    if(len < 0) len = 0;

	    if(i == 1) min = 1;
	    LL le = calc_two(len);
	    for(int j = min; j < 10; j++){
		if(now + 1 <= n && n <= now + le){
		    num[i] = num[l - i + 1] = j;
		    break;
		}
		now = now + le;
	    }
	}

	for(int i = 1; i <= l; i++)
	    printf("%d", num[i]);

	printf("\n");
    }
    return 0;
}
