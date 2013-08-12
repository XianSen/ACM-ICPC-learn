#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

const int MAXN = 1000003;
using namespace std;
unsigned long long sum[MAXN];

//返回c(n,2)
unsigned long long co(unsigned long long n){
    if(n < 2) return 0;
    else return n * (n - 1);
}

void init(){
    sum[0] = sum[1] = 0;
    for(unsigned long long i = 2; i < MAXN; i++)
	sum[i] = sum[i - 1] + co(i);
}

int main(){
    init();
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
	unsigned long long ans = 0;
	if(n == 0 && m == 0) break;
	if(n < m)  swap(n, m);
	ans = n * co(m) + m * co(n);
	ans += (sum[m-1] * 2 + (n - m + 1) * co(m)) * 2;
	cout << ans << endl;
   }
    return 0;
}
