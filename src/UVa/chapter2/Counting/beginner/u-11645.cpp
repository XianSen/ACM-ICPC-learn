#include <new>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned long long LL;
const int MAXN = 30;
const int MAXM = 300;
const int MAXD = 100;
int num[MAXN];

struct BigNum{
    int n;
    int a[MAXM];

    BigNum(){
	n = 1;
	memset(a, 0, sizeof(a));
	a[0] = 0;
    }

    BigNum(int who){
	char s[MAXM];
	sprintf(s, "%d", who);
	new(this) BigNum(s);
    }

    BigNum(unsigned long long who){
	char s[MAXM];
	sprintf(s, "%llu", who);
	new(this) BigNum(s);
    }

    BigNum(const char *s){
	n = strlen(s);
	memset(a, 0, sizeof(a));
	for(int i = 0; i < n; i++)
	    a[n - i - 1] = s[i] - '0';
    }

    //加
    BigNum operator+(const BigNum& b){
	BigNum result;
	int &len = result.n;
	int * num = result.a;

	len = n > b.n ? n : b.n;
	for(int i = 0; i < len; i++)
	    num[i] = a[i] + b.a[i];

	int j = 0;
	for(int i = 0; i < len; i++){
	    num[i] += j;
	    j = num[i] / 10;
	    num[i] %= 10;
	}

	while(j != 0){
	    num[len++] = j % 10;
	    j /= 10;
	}

	while(n > 1 && a[n - 1] == 0) n--;
	return result;
    }

    //减
    BigNum operator-(const BigNum& b){
	BigNum result;
	int & len = result.n;
	int * num = result.a;
	len = n;
	for(int i = 0; i < n; i++)
	    num[i] = a[i] - b.a[i];

	int j = 0;
	for(int i = 0; i < n; i++){
	    num[i] += j;
	    j = 0;
	    if(num[i] < 0){
		j = -1;
		num[i] += 10;
	    }
	    num[i] %= 10;
	}

	while(n > 1 && a[n - 1] == 0) n--;
	return result;
    }

    //乘
    BigNum operator*(const BigNum& b){
	BigNum result;		
	int &len = result.n;
	int *num = result.a;

	len = n + b.n;
	for(int i = 0; i < n; i++)
	    for(int j = 0; j < b.n; j++)
		num[i + j] += a[i] * b.a[j];

	int j = 0;
	for(int i = 0; i < len; i++){
	    num[i] += j;
	    j = num[i] / 10;
	    num[i] %= 10;
	}

	while(j != 0){
	    num[len++] = j % 10;
	    j /= 10;
	}

	while(n > 1 && a[n - 1] == 0) n--;

	return result;
    }

    void print(){
	while(n > 1 && a[n - 1] == 0) n--;
	for(int i = n - 1; i >= 0; i--)
	    printf("%1d", a[i]);
	printf("\n");
    }
};

BigNum zero(0);
BigNum one(1);
BigNum two(2);

void split(LL num, int a[]){
    if(num <= 0) return;
    a[0] = 0;
    while(num != 0){
	a[++a[0]] = num % 2;
	num /= 2;
    }
}

BigNum pow2[100];

void init(){
    int n = 70;
    pow2[0] = one;
    for(int i = 1; i <= n; i++)
	pow2[i] = pow2[i-1] * two;//pow2[i - 1] * 2;
//    pow2[10].print();
//    (two * two).print();
}

BigNum pow(int p, int k){
    return pow2[k];
}

BigNum calc(LL n){
    if(n == 0) return zero;
    BigNum ans = zero;
    split(n, num);

    BigNum left(0);
    BigNum right(n);

    int pow2_re = num[0] - 1;
    

    for(int i = num[0]; i > 1; i--){
	if(num[i] == 1 && num[i - 1] == 1){
	    ans = ans + left * pow(2, i - 2);
	    ans = ans + right + one - pow2[pow2_re] - pow2[pow2_re-1];
	}else{
	    ans = ans + left * pow(2, i - 2);
	}

	left = left * two; 

	if(num[i] == 1){
	    left = left + one;
	    right = right - pow2[pow2_re];
	}

	pow2_re--;
    }
    return ans;
}

char s[200];

int main(){
    LL n; 
    init();
    int kcase = 0;
    while(gets(s) != NULL){
	while(strlen(s) < 1) gets(s);
	if(s[0] == '-') break;
	sscanf(s, "%lld", &n);
	BigNum ans = calc(n);
	printf("Case %d: ", ++kcase);
	ans.print();
    }
    return 0;
}
