#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using std::sort;

const int maxn = 200;
int a[maxn];
int b[maxn];

int main(){
    int n, d, r;
    while(scanf("%d%d%d", &n, &d, &r)){
	if(n == 0 && d == 0 && r == 0) break;
	for(int i = 0; i < n; i++)
	    scanf("%d", a+i);
	for(int i = 0; i < n; i++)
	    scanf("%d", b+i);

	sort(a, a + n);
	sort(b, b + n);

	int ans = 0;
	for(int i = 0; i < n; i++){
	    int time = a[i] + b[n-i-1];
	    if(time > d)
		ans += (time - d) * r;
	}

	printf("%d\n", ans);
    }
    return 0;
}
