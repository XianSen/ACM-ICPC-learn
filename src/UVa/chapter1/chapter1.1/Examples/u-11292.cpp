#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 21000;

int a[maxn];
int b[maxn];

int main(){
    int i, j, n, m;
    while(~scanf("%d%d",&n,&m)){
	if(n == 0 && m == 0) break;
	for(i = 0; i < n; i++)
	    scanf("%d",a+i);

	for(i = 0; i < m; i++)
	    scanf("%d",b+i);

	sort(a,a+n);
	sort(b,b+m);

	int cur, ans;
	cur = ans = 0;

	for(i = 0; i < m; i++){
	    if(a[cur] <= b[i]){
		ans += b[i];
		cur++;
	    }
	    if(cur == n) break;
	}

	if(cur == n) printf("%d\n",ans);
	else printf("Loowater is doomed!\n");
    }
    return 0;
}
