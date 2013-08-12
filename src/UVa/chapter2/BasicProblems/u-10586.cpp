#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 11000;
int a[MAXN];
int b[MAXN];

int main(){
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF){
	if(n == -1 && k == -1) break;
	for(int i = 0; i <= n; i++)
	    scanf("%d", a + i);
	int now = n;
	while(now >= k){
	    int a0 = a[now];
	    int k1 = now - k;
	    a[now] = a[now] - a0;
	    if(k1 != now)
		a[k1] = a[k1] - a0;
	    now --;
	}

	int sum = 0;
	for(int i = n; i >= 0; i--)
	    if(a[i] != 0){
		sum = i;
		break;
	    }

	for(int i = 0; i <= sum; i++)
	    if(i == sum) printf("%d\n", a[i]);
	    else printf("%d ", a[i]);
    }
    return 0;
}
