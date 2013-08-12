#include <map>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using std::map;

const int MAXN = 2100000;
int n;
int que[MAXN];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
	scanf("%d", &n);
	int sum = 0;
	int ans = 0;
	map<int,int> mii;

	for(int i = 0; i < n; i++)
	    scanf("%d", que + i);

	if(n != 0) ans = 1;

	int last = 0;
	for(int i = 0; i < n; i++){
	    int now = que[i];

	    if(mii.find(now) == mii.end()){
		mii[now] = 0;
	    }

	    mii[now] = mii[now] + 1;
	    while(mii[now] != 1)
		mii[que[last++]]--;

	    if(i - last + 1 > ans) 
		ans = i - last + 1;
	}

	printf("%d\n", ans);
    }
    return 0;
}
