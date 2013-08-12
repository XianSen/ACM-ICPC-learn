#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
	int n, now, m1 = 0, m2 = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
	    scanf("%d", &now);
	    if(now == 1) m1 ++;
	    else if(now > 0) m2 ++;
	}
	if(m2 > 0) puts("poopi");
	else puts((m1 & 1) ? "poopi" : "piloop");
    }
    return 0;
}
