#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

const int MAXN = 15;
const int MAXM = 110;
using namespace std;

int n, x, y;
int size[MAXN];
int get_sum[(1 << MAXN) + 10];
int dp[(1 << MAXN) + 10][MAXM];

bool solve(int status, int width){
    if(dp[status][width] != -1)
	return dp[status][width];

    int sub = status & (status - 1);

    if(sub == 0) 
	return dp[status][width] = 1;

    int height = get_sum[status] / width;
    while(sub > 0){
	int cur = (status^sub);

	int first = get_sum[cur];
	int second = get_sum[sub];
	

	//split height 
	if(first % width == 0 && second % width == 0)
	    if(solve(cur, max(width, first/width)) && 
	       solve(sub, max(width, second/width)))
		return dp[status][width] = 1;

	//split width
	if(first % height == 0 && second % height == 0)
	    if(solve(cur, max(height, first/height)) && 
	       solve(sub, max(height, second/height)))
		return dp[status][width] = 1;

	sub = status & (sub - 1);
    }

    return dp[status][width] = 0;
}

int init(){	
    memset(dp, -1, sizeof(dp));
    get_sum[0] = 0;
    for(int i = 0; i < n; i++)
	get_sum[1 << i] = size[i];
    int sum = (1 << n);
    for(int i = 1; i < sum; i++){
	int next = i & (i - 1); 
	int other = i - next;
	get_sum[i] = get_sum[next] + get_sum[other];
    }
}

#ifdef DEBUG
int test_init(){
    int sum = (1 << n);
    for(int i = 0; i < sum; i++){
	int now = 0;
	for(int j = 0; j < n; j++)
	    if((i & (1 << j)) != 0)
		now += size[j];
	if(now != get_sum[i])
	    printf("??");
    }
    printf("ok");
}
#endif

int main(){
    int cas = 0;
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;
	scanf("%d%d", &x, &y);
	int sum = 0;
	for(int i = 0; i < n; i++){
	    scanf("%d", size + i);
	    sum += size[i];
	}

	init();	
#ifdef DEBUG
	test_init();
#endif

#ifdef DEBUG
	printf("sum = x * y? %d\n", sum == x * y);
#endif
	if(sum == x * y && solve((1 << n) - 1, max(x, y)))
	    printf("Case %d: Yes\n", ++cas);
	else
	    printf("Case %d: No\n", ++cas);
    }
    return 0;
}
