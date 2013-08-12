#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
const int MAXN = 17;
int n;
int p[MAXN];
int dp[1 << MAXN];
int cover[1 << MAXN];

int main(){
    int tt = 0;
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;

	for(int i = 0; i < n; i++){
	    int m;
	    p[i] = (1 << i);
	    scanf("%d", &m);
	    for(int j = 0; j < m; j++){
		int x;
		scanf("%d", &x);
		p[i] |= (1 << x);
	    }
	}

	int ALL = (1 << n) - 1;

	cover[0] = 0;
	for(int i = 0; i < n; i++)
	    cover[1 << i] = p[i];

	for(int i = 1; i <= ALL; i++){
	    int first = (i & (i - 1));
	    int second = i - first;
	    cover[i] = (cover[first] | cover[second]);
	}

	dp[0] = 0;
	for(int s = 1; s <= ALL; s++){
	    dp[s] = 0;
	    for(int s0 = s; s0; s0 = ((s0 - 1) & s))
		if(cover[s0] == ALL)
		    dp[s] = max(dp[s], dp[s^s0] + 1);
	}

	printf("Case %d: %d\n", ++tt, dp[ALL]);
    }
    return 0;
}
