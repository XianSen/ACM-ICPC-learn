#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FORE(i,j) for(int i = (j); i <= n; i++)

const int MAXN = 60;
const int MAXM = MAXN;

int coin[MAXN];
int vist[MAXM];

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int lcm(int a, int b){
    return a / gcd(a,b) * b;
}

int main(){
    int n, t;
    while(scanf("%d%d", &n, &t) != EOF){
	if(n == 0 && t == 0) break;
	for(int i = 1; i <= n; i++)
	    scanf("%d", coin + i);

	for(int i = 1; i <= t; i++){
	    int table;
	    scanf("%d", &table);
	    //int max = -1, min = table + 1;
	    int first = -1, second = 2147483647;

	    FORE(i1,1) FORE(i2,i1+1) FORE(i3, i2+1) FORE(i4, i3+1){
		int now1 = lcm(coin[i1], coin[i2]);
		int now2 = lcm(coin[i3], coin[i4]);
		int now = lcm(now1, now2);
		//if(now < min) min = now;
		int t2 = table / now * now;
		if(t2 > first) first = t2;
		int t3 = (table + now - 1) / now * now;
		if(t3 < second) second = t3;
	    }
	    printf("%d %d\n", first, second);
	}
    }
    return 0;
}
