#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 1000000;
int a[MAXN];
int b[MAXN];

void init(int k, int N, int a[], int b[], int & size){
    int i = 0 , j = 0;
    a[0] = b[0] = 1;
    while(a[i] < N){
	i = i + 1;
	a[i] = b[i - 1] + 1;
	while(a[j + 1] * k < a[i])
	    j++;
	if(a[j] * k < a[i])
	    b[i] = b[j] + a[i];
	else
	    b[i] = a[i];
    }
    size = i + 1;
}

int main(){
    int tt;
    scanf("%d", &tt);
    for(int kcase = 1; kcase <= tt; kcase++){
	int n, k;
	scanf("%d%d", &n, &k);
	int size = 0;
	init(k, n, a, b, size);

	if(n <= k || a[size - 1] == n)
	    printf("Case %d: lose\n", kcase);
	else{
	    int last = -1;
	    size -= 1;
	    while(n){
		if(n >= a[size]){
		    n -= a[size];
		    last = a[size];
		}
		size--; 
	    }
	    printf("Case %d: %d\n", kcase, last);
	}
    }
    return 0;
}
