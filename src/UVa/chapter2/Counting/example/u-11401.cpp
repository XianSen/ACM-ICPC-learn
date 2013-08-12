#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int MAXN = 1000001;
long long f[MAXN];

int main(){
    f[3] = 0;
    for(long long x = 4; x < MAXN; x++)
	f[x] = f[x-1] + ((x - 1) * (x - 2)/2 - (x - 1)/2)/2;
    int n;
    while(scanf("%d", &n) != EOF){
	if(n < 3) break;
	cout << f[n] << endl;
    }
    return 0;
}
