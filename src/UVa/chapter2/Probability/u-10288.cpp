#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long LL;

LL gcd(LL a, LL b){
    return b ? gcd(b, a % b) : a;
}

char fmt1[200];
char fmt2[200];
char fmt3[200];

struct Fraction{
    LL a, b, c;
    Fraction(LL _a, LL _b){
	if(_a == 0){
	    c = 1;
	    a = b = 0;
	}else{
	    LL d = gcd(_a, _b);
	    _a /= d;
	    _b /= d;
	    a = _a / _b;
	    b = _a % _b;
	    c = _b;
	}
    }

    void clean(){
	if(b == 0){
	    c = 1;
	}else{
	    LL d = gcd(b, c);
	    b = b / d;
	    c = c / d;
	    a += b / c;
	    b = b % c;
	}
    }

    Fraction add(const Fraction &a1, const Fraction &a2) const{
	Fraction result(0, 1);
	result.a = a1.a + a2.a;
	result.b = a1.b * a2.c + a2.b * a1.c;	
	result.c = a1.c * a2.c;
	result.clean();
	return result;
    }

    int bit(LL d){
	int ans = 0;
	LL t = d;
	while(t != 0){
	    ans++;
	    t = t / 10;
	}
	return ans != 0? ans : 1;
    }
	
    void print(){
	if(b == 0){
	    printf("%lld\n", a);
	}else{
//	    printf("%lld %lld/%lld\n", a, b, c);	    
	    sprintf(fmt1, "%%%dlld\n", bit(a) + bit(b)+1);
	    printf(fmt1, b);
	    printf("%lld ", a);
	    for(int i = 0; i < bit(c); i++)
		printf("-");
	    printf("\n");
	    sprintf(fmt2, "%%%dlld\n", bit(a) + bit(c)+1);
	    printf(fmt2, c);
	}
    }
};

int main(){
    int n;
    while(scanf("%d", &n) == 1){
	Fraction ans(1, 1);
	for(int i = 2; i <= n; i++){
	    Fraction now(n, n - (i - 1));
	    ans = ans.add(ans, now);
	}
	ans.print();
    }
    return 0;
}
