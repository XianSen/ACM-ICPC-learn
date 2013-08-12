#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MOD = 1000007;
const int MAXK = 500;
int C[MAXK + 10][MAXK + 10];

int main(){
    memset(C, 0, sizeof(C));
    C[0][0] = 1;
    for(int i = 0; i <= MAXK; i++){
	C[i][0] = C[i][i] = 1;
	for(int j = 1; j < i; j++)
	    C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }

    int T;
    scanf("%d", &T);
    for(int kcase = 1; kcase <= T; kcase++){
	int n, m, k, sum = 0;
	scanf("%d%d%d", &n, &m, &k);
	for(int s = 0; s < 16; s++){
	    int b = 0, r = n, c = m;
	    if(s & 1) {r--; b++;};
	    if(s & 2) {r--; b++;};
	    if(s & 4) {c--; b++;};
	    if(s & 8) {c--; b++;};
	    if(b % 2 != 0) sum = (sum + MOD - C[r*c][k]) % MOD;
	    else  sum = (sum + C[r*c][k]) % MOD;
	}
	printf("Case %d: %d\n", kcase, sum);
    }
    return 0;
}
