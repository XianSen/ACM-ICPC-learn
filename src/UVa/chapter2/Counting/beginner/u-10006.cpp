//Carmichael Numbers ----no a prime, but a^n mod n = a for every a

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 65000;
int prime[MAXN + 10];
int vist[MAXN + 10];

typedef long long LL;
int mod_n(int a, int n, int mod){
    if(n == 0) return 1;
    if(n == 1) return a;
    LL result = mod_n(a, n/2, mod);
    result = (result * result) % mod; 
    if(n % 2 == 1)
	result = (result * a) % mod;
    return (int)(result % mod);
}

bool is_car(int num){
    if(!prime[num]) return false;
    for(int i = 2; i < num; i++)
	if(mod_n(i, num, num) != i)
	    return false;
    return true;
}

void init(){
    //0代表是素数
    memset(prime, 0, sizeof(prime));
    for(int i = 2; i < MAXN; i++){
//	printf("%d\n",i);
	LL a = i;
	a = a * a;
	if(a >=  MAXN) continue;
	if(!prime[i])
	    for(int j = i * i; j < MAXN; j += i)
		prime[j] = 1;
    }

    memset(vist, 0, sizeof(vist));
    for(int i = 2; i < MAXN; i++)
	vist[i] = is_car(i);
}

int main(){
    int n;
    init();
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;
	if(vist[n]) printf("The number %d is a Carmichael number.\n", n);
	else printf("%d is normal.\n", n);
    }
    return 0;
}
