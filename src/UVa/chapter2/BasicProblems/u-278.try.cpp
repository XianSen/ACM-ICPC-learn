#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int know_who(){
    char c = getchar();
    while(c != 'r' && c != 'k' && c != 'Q' && k != 'K')
	c = getchar();
    return c;
}

typedef int LL;

void init(){
}

int main(){
    int kcase;
    init();
    scanf("%d", &kcase);
    while(kcase--){
	int status = know_who();	
	LL ans = 0;
	int n, m;
	scanf("%d%d", &n, &m);
	if(status == 'r'){
	    ans = n < m ? n : m;
	}else if(status == 'k'){
	    
	}else if(status == 'Q'){

	}else if(status == 'K'){
	    ans = ((n + 1) / 2) * ((m + 1) / 2);
	}
	printf("%lld\n", ans);
    }
    return 0;
}
