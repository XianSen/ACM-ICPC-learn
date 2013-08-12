#include <set>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
using namespace std;

typedef unsigned long long LL;
int primes[101];

void init(){
    int n = 100;
    memset(primes, 0, sizeof(primes));
    for(int i = 2; i <= n; i++)
	if(!primes[i]){
	    for(int j = i * i; j <= n; j += i)
		primes[j] = 1;
	}
}

int main(){
    init();

    set<LL> values;
    values.insert(1);
    
    LL max_num = ULONG_LONG_MAX;
    for(int i = 2; i < (1 << 16); i++){
	LL now = i;
	int max_pow = ceil(64.0 * log10(2.0) / log10(i));

	for(int j = 2; j < max_pow; j++){
		now = now * i;
	    if(primes[j] == 1)
		values.insert(now);
	}
    }
    
    set<LL>::iterator it = values.begin();

    while(it != values.end())
	printf("%llu\n", *it++);

    return 0;
}
