#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 110000;
int n, k, y[30][MAXN];

int find(int a);
int win(int a, int b);

int find(int a){
    return y[k][a];
}

int win(int a, int b){
    if(a > b) return win(b, a);
    int c = find(a);
    return c != b;
}

void init(){
    memset(y, -1, sizeof(y));
}

void init(int k){
    if(y[k][0] != -1) return;
    long long now = k;
    y[k][0] = 0;
    long long a, b;
    for(a = 1; a < MAXN && now < MAXN; a++){
	if(y[k][a] >= 0) continue;

	b = a + now + 1;
	if(b >= MAXN) break;

	if(b < a) return;

	y[k][a] = b;
	y[k][b] = a;

	now += k + 1;
    }
}

int main(){
    int tt;
    init();
    scanf("%d", &tt);
    while(tt--){
	int Q;
	scanf("%lld%d", &k, &Q);
	init(k);
	while(Q--){
	    int a, b;
	    scanf("%d%d", &a, &b);
	    puts(win(a, b) ? "WINNING" : "LOSING");
	}
	printf("\n");
    }
    return 0;
}
