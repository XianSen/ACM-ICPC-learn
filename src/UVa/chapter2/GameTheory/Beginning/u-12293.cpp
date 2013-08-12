#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sg(int n){
    if(n == 1) return 0;
    if(n & 1) return sg(n >> 1);
    else return (n >> 1);
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;
	n = sg(n);
	puts(n == 0 ? "Bob" : "Alice");
    }
    return 0;
}
