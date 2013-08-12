#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n, ans, line, cas = 0;
    while(scanf("%d", &n)){ 
	if(n < 0) break;
	ans = 0;
	line = 1;
	while(line < n){
	    ans++;
	    line *= 2; 
	}
	    
	printf("Case %d: %d\n", ++cas, ans);
    }
    return 0;
}
