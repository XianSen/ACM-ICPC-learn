#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 110;
int h[MAXN];

int main(){
    int n, kcase;
    kcase = 0;
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;	
	int sum = 0;
	for(int i = 1; i <= n; i++){
	    scanf("%d", h + i);
	    sum += h[i];
	}

	printf("Set #%d\n", ++kcase);
	int ans = 0;	

	int need = 0;
	int height = sum / n;

	for(int i = 1; i <= n; i++){
	    if(h[i] < height)
		ans += height - h[i];
	}

	printf("The minimum number of moves is %d.\n", ans);
	printf("\n");
    }
    return 0;
}
