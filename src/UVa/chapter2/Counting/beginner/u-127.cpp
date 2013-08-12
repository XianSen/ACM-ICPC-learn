#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int LL;
const int MOD = 34943;
const int MAXN = 1024 + 100;
const int MUL =  (256 * 256 ) % MOD;

char s[MAXN];

int main(){
    while(gets(s) && s[0] != '#'){
	int len = strlen(s);
	LL ans = 0;
	for(int i = 0; i < len; i++){
	    ans = ((ans * 256) + s[i]) % MOD;
	}

	ans = MOD - (ans * MUL) % MOD;
	ans %= MOD;
	unsigned char c1 = (ans / 256) & 255;
	unsigned char c2 = (ans & 255);

	printf("%02X %02X\n", c1, c2);
    }
}
