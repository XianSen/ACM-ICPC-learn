#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long LL;

//n个人分sum个
bool check(LL n, LL sum){
    for(int i = 1; i <= n; i++){
	if(sum % n != 1) return false;
	//一个给猴子
	sum -= 1;
	sum = sum - sum / n;
    }
    return sum % n == 0 ? true : false; 
}

int calc(int n){
    int most = 100;
    if(n < most) most = n;
    for(int i = most; i > 0; i--)
	if(check(i, n))
	    return i;
//    printf("%d\n", check(3, 25));
    return -1;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
	if(n < 0) break;
	int people = calc(n); 
	if(people > 0){
	    printf("%d coconuts, %d people and 1 monkey\n", n, people);
	}else{
	    printf("%d coconuts, no solution\n", n);
	}
    }
    return 0;
}
