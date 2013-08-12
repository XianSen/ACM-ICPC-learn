#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 110000;
int que[MAXN];
int sum[MAXN];

char getZeroOrOne(){
    char c = getchar();
    while(c != '0' && c != '1')
	c = getchar();
    return c;
}

double getAve(int a, int b){
    return (sum[b] - sum[a])*1.0/(b - a);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++){
	int n, len;
	scanf("%d%d", &n, &len);
	sum[0] = 0;
	for(int i = 1; i <= n; i++)
	    sum[i] = sum[i-1] + getZeroOrOne() - '0';

	double ans = 0;
	int left;
	int right;
	left = -1, right = n + n;

	int first = 0, second = -1;

	for(int i = len; i <= n; i++){
	    while(first < second && getAve(que[second], i - len) <= getAve(que[second-1],que[second]))
		second--;
	    que[++second] = i - len;
	    while(first < second &&
		    getAve(que[first+1],i) >= getAve(que[first],i))
		first++;

	    if(ans == getAve(que[first], i) && i - que[first] < right - left){
		left = que[first];
		right = i;
	    }else if(ans < getAve(que[first], i)){
		ans = getAve(que[first], i);
		left = que[first];
		right = i;
	    }
	}

	printf("%d %d\n", left + 1, right);
    }
    return 0;
}
