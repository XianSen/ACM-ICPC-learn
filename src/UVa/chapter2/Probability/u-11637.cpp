#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using std::min;
const int MAXN = 101000;
//f[i] = ln(i!);
long double f[MAXN];

void init(){
    int n = MAXN - 1;
    f[0] = log(1.0);
    for(int i = 1; i <= n; i++)
	f[i] = f[i - 1] + log((long double)i);
}

int main(){
    int n, k, tt = 0;
    init();
    while(scanf("%d%d", &n, &k) == 2){
	if(n == 0 && k == 0) break;
	printf("Case %d: ", ++tt);
	double ans = 0;
	if(n == 1){
	    printf("%0.4lf\n", ans);
	}else if(n <= 2 * k + 1){
	    //全部都可以到达
	    printf("%0.4lf\n", (double)n);
	}else{
	    //y是共有多少个有意义的单词
	    int y = n - 2 * k - 1;
	    //计算每一个位置，平均有多少个有意义的单词
	    for(int i = 1; i <= n; i++){
		int x = min(i - 1, k) + min(n - i, k);
		if(x <= y){
		    ans += n * exp(f[y] + f[n - x - 1] - f[n] - f[y-x]);
		}
	    }
	    printf("%0.4lf\n", n - ans);
	}
    }
    return 0;
}
