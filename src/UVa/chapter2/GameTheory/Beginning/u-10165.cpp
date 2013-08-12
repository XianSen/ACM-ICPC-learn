#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    while(scanf("%d", &n) == 1){
	if(n == 0) break;
	int stone, result = 0;
	for(int i = 0; i < n; i++){
	    scanf("%d", &stone);
	    result ^= stone;
	}
	puts(result ? "Yes" : "No");
    }
    return 0;
}
