#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 10000;
int num[MAXN];

int main(){
    int n, kcase = 0, k;
    scanf("%d", &k);
    while(k--){
	scanf("%d", &n);
	printf("Case #%d: ", ++kcase);

	num[0] = 0;

	while(n != 0){
	   int mod =  n % (-2);
	   n = n / (-2);
	   if(mod < 0){
	       mod = mod - (-2);
	       n = n + 1;
	   }
	   num[++num[0]] = mod;//n % (-2);
	}

	if(num[0] == 0)
	    num[++num[0]] = 0;

	for(int i = num[0]; i >= 1; i--)
	    printf("%1d", num[i]);
	printf("\n");
    }
    return 0;
}
