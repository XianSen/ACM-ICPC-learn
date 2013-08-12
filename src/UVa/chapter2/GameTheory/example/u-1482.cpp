#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned long long LL;

LL SG(LL stone){
    if(stone <= 1) 
	return 0;
    if(stone % 2 == 0){
	return stone / 2;
    }else{
	return SG(stone/2);
    }
}

int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
	int n;
	LL status = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
	    LL stone;
	    scanf("%lld", &stone);
	    status ^= SG(stone);
	}
	puts(status == 0 ? "NO" : "YES");
    }
    return 0;
}
