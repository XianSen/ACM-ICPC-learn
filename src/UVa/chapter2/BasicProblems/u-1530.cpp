#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 100;

char s[MAXN];
double pow2[MAXN];

int main(){
    puts("Program 6 by team X");
    int n = 127;
    for(int i = 0; i <= n; i++)
	pow2[i] = pow(2.0, i - 63);

    while(gets(s) != NULL){
	int k = 0;
	for(int i = 1; i <= 7; i++) 
	    k = (k << 1) + s[i] - '0';

	double ans = 1;
	double pow1 = 0.5;

	for(int i = 8; i <= 15; i++){
	    if(s[i] == '1')
		ans += pow1;
	    pow1 = pow1 / 2.0;
	}

	ans = ans * pow2[k];

	if (s[0] == '1') ans = -ans;

	if(strcmp("000000000000000", s + 1) == 0) ans = 0;

	sprintf(s, "%13e", ans);
	for(int i = 0; s[i] != 0; i++)
	    if((s[i] != '+' && s[i] != '-') || i == 0) putchar(s[i]);
	    else {
		putchar(s[i]);
		putchar('0');
	    }
	putchar('\n');
    }
    puts("End of program 6 by team X");
    return 0;
}
