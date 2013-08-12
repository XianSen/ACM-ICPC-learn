#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;
const int MAXN = 510000;
const int INF = 2147483647;

int n;
long long ans;

int num[MAXN];
int left[MAXN];
int right[MAXN];

void sort(int st, int en){
    if(st >= en) return;
    int m = (en + st) >> 1;
    if(st <= m) sort(st, m);
    if(m + 1 <= en) sort(m+1, en);

    int i, j;
    int leftNum = m - st + 1;
    int rightNum = (en - (m + 1)) + 1;

    for(i = st; i <= m; i++)
	left[i - st] = num[i];

    for(i = m + 1; i <= en; i++)
	right[i - (m + 1)] = num[i];

    i = j = 0;
    left[leftNum] = right[rightNum] = INF;
    for(int k = st; k <= en; k++)
	if(left[i] <= right[j]){
	    num[k] = left[i++];
	}else{
	    num[k] = right[j++];
	    ans += leftNum - i;
	}
}

int main(){
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;
	for(int i = 1; i <= n; i++)
	    scanf("%d", num + i);
	ans = 0;
	sort(1, n);
	cout << ans << endl;
    }
    return 0;
}
