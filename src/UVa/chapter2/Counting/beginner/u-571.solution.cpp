#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using std::min;

//a 小 b 大
void solve(int a, int b, int n, char ca, char cb){
    int x, y;
    x = y = 0;
    while(y != n){
	if(x == 0){
	    printf("fill %c\n", ca);
	    x = a;
	}else if(y == b){
	    printf("empty %c\n", cb);
	    y = 0;
	}else {
	    printf("pour %c %c\n", ca, cb);
	    int sum = x + y;
	    y = min(b, sum);
	    x = sum - y;
	}
    }
    printf("success\n");
}

int main(){
    int a, b, n;
    while(scanf("%d%d%d", &a, &b, &n) != EOF){
	if(a > b) solve(b, a, n, 'B', 'A');
	else solve(a, b, n, 'A', 'B');
    }
    return 0;
}
