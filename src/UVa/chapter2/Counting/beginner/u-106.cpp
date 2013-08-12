#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

const int MAXN = 1001000;
int vist[MAXN];
typedef long long LL;

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
    int n, kcase = 0;;
    memset(vist, 0, sizeof(vist));
    while(scanf("%d", &n) != EOF){
	kcase ++;
	int ans = 0;
	LL max = (LL)sqrt(n * 1.0);

	for(LL r = 1; r <= max; r++){
	    for(LL s = 1; s < r; s++){
		LL x = r * r - s * s;
		LL y = 2 * r * s;
		LL z = r * r + s * s;
		if(x * x + y * y == z * z && z <= n){
		    if(gcd(x, y) == 1){
			ans++;
			for(LL k = 1; k * z <= n; k++){
			    vist[k * x] = kcase;
			    vist[k * y] = kcase;
			    vist[k * z] = kcase;
			}
		    }
		}
	    }
	}

	int p = 0;
	for(int i = 1; i <= n; i++)
	    if(vist[i] != kcase)
		p++;
	cout << ans << " " << p << endl;
    }
    return 0;
}
