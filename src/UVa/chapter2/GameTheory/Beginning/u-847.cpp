#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long LL;

LL begin[10];
LL end[10];

LL pow9(int n){
    if(n == 0) return 1;
    LL now = 1;
    for(int i = 1; i <= n; i++)
	now = now * 9;
    return now;
}

void init(){
    LL a = 1, b = 1; 
    for(int i = 1; i <= 8; i++){
	begin[i] = pow9(a) * b;
	end[i] = pow9(a) * b * 2;
	a = a + 1;
	b = b * 2;
//	printf("%llu %llu\n", begin[i], end[i]);
    }
}

bool win(LL n){
    for(int i = 1; i <= 8; i++)
	if(begin[i] < n && n <= end[i])
	    return false;
    return true;
}

int main(){
    init();
    LL n;
    while(scanf("%llu", &n) == 1){
	puts(win(n) ? "Stan wins." : "Ollie wins.");
    }
    return 0;
}
