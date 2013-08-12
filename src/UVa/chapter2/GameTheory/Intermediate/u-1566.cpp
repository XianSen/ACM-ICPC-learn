#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
	int n, sum = 0, one = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
	    int a;
	    scanf("%d", &a);
	    sum ^= a;
	    if(a > 1) one++;
	}

	if(one) puts(sum ? "John" : "Brother");
	else puts(n % 2 ? "Brother" : "John");
    }
    return 0;
}
