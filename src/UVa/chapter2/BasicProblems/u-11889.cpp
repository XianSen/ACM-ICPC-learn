#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcd(int a, int b){
    while(b != 0){
	int c = a % b;
	a = b;
	b = c;
    }
    return a;
}

int main(){
    int kcase;
    scanf("%d", &kcase);
    while(kcase--){
	int a, l;
	scanf("%d%d", &a, &l);
	if(l % a != 0) printf("NO SOLUTION\n");
	else{
	    int i, j = l / a;
	    for(i = l/a; i <= l; i += j){
		int lcm = i / gcd(i, a) * a; 
		if(lcm == l) break;
	    }
	    printf("%d\n", i);
	}
    }
    return 0;
}
