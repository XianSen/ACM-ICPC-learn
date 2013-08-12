#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F(n) (((n) * ((n) - 1)) / 2)

const int MAXN = 400000;

int main(){
    int n, kcase;
    scanf("%d", &kcase);
    while(kcase--){
	scanf("%d", &n);
	int n1 = n / 2;
	int n2 = n - n1;
	printf("%d\n",F(n1) + F(n2));
    }
    return 0;
}
