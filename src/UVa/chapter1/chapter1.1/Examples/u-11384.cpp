#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int work(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return work(n/2) + 1;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
	printf("%d\n",work(n));
    }
    return 0;
}
