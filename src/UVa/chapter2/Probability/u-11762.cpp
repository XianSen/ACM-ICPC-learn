#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXM = 1100;
const int MAXN = MAXM * MAXM + 100;

int vist[MAXN];
int num[MAXN];
int primes[MAXN];
double record[MAXN];

#include <math.h>
void sieve(int n){
    int m = (int)sqrt(n + 0.5);
    memset(vist, 0, sizeof(vist));
    for(int i = 2; i <= m; i++) if(!vist[i])
	for(int j = i * i; j <= n; j += i)
	    vist[j] = 1;
}

int get_primes(int n){
    sieve(n);
    int &c = primes[0];
    c = 0;
    num[0] = num[1] = 0;
    for(int i = 2; i <= n; i++)
	if(!vist[i]) {
	    primes[++c] = i;
	    num[i] = num[i - 1] + 1;
	}else{
	    num[i] = num[i - 1];
	}
    return c;
}

void init(){
    get_primes(MAXN - 1);
    memset(vist, 0, sizeof(vist));
    vist[1] = 1 ;
    record[1] = 0;
}

double calc(int n){
    if(vist[n]) return record[n];
    vist[n] = 1;
    double &ans = record[n];
    ans = 0;
    int sum = 0;
    for(int i = 1; i <= primes[0] && primes[i] <= n; i++)
	if(n % primes[i] == 0){
	    sum++;
	    ans += calc(n / primes[i]);
	}
    ans = (ans + num[n]) / sum;
    return ans;
}

int main(){
    int tt;
    init();
    scanf("%d", &tt);
    for(int kcase = 1; kcase <= tt; kcase++){
	int n;
	scanf("%d", &n);
	printf("Case %d: %0.10lf\n", kcase, calc(n));
    }
    return 0;
}
