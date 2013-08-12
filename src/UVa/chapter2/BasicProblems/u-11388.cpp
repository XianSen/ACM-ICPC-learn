#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int g, l, t;
    scanf("%d", &t);
    while(scanf("%d%d", &g, &l) != EOF){
	if(l % g == 0) printf("%d %d\n", g, l);
	else printf("-1\n");
    }
    return 0;
}
