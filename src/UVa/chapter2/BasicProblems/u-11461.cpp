#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calc(int n){
    int ans = sqrt(n * 1.0 + 0.5);
    return ans;
}

int main(){
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
	if(a == 0 && b == 0) break;
	printf("%d\n", calc(b) - calc(a - 1));
    }
    return 0;
}
