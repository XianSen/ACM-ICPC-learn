#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ull;
const int maxn = 1100001;

ull coin[maxn];
ull c[maxn];

int main(){
    ull ans, sum, ave;
    int i, j, n;
    while(~scanf("%d",&n) && n){
	ans = sum = 0;
	for(i = 0; i < n; i++){
	    scanf("%lld",coin+i);
	    sum += coin[i];
	}

	ave = sum / n;
	c[0] = 0;
	for(i = 1; i < n; i++)
	    c[i] = coin[i]-ave + c[i-1];

	sort(c,c+n);

	ull x1 = c[n/2];		
	for(i = 0; i < n; i++)
	    ans += abs(x1-c[i]);

	cout << ans << endl;
    }
    return 0;
}
