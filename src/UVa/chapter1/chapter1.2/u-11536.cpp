#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 1200001;
const int MAXM = 1021;
int num[MAXN];
int *a = num;
int count[MAXM];

int main(){
    int t, n, m, k;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++){
	memset(count, 0, sizeof(count));
	scanf("%d%d%d", &n, &m, &k);

	num[1] = 1;	
	num[2] = 2;
	num[3] = 3;

	for(int i = 4; i <= n; i++)
	    num[i] = (num[i-1] + num[i-2] + num[i-3]) % m + 1;

	int sum = 0;
	int ans = -1;
	int last = 1;
	int ansleft = 0;
	int ansright = 0;

	for(int i = 1; i <= n; i++){
	    count[a[i]]++;
	    if(a[i] > k) continue;

	    while(last < i && a[last] > k)
		last++;

	    if(count[a[i]] == 1){
		sum++;
	    }else{
		while(last < i &&(a[last] > k || count[a[last]] != 1)){
		    if(a[last] <= k) count[a[last]]--;
		    last++;
		}
	    }

	    if(sum == k && (ans == -1 || ans > i - last + 1)){
		    ans = i - last + 1;
		    ansleft = last;
		    ansright = i;
	    }
	}

	if(ans != -1)
	    printf("Case %d: %d\n", cas, ans);
	else
	    printf("Case %d: sequence nai\n", cas);
    }
    return 0;
}
