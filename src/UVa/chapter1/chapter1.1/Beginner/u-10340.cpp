#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 1100000;

char S[maxn];
char T[maxn];

int main(){
    while(scanf("%s%s", S, T) != EOF){
	int len1 = strlen(S);
	int len2 = strlen(T);
	int j = 0;
	for(int i = 0; i < len2 && j < len1; i++){
	    if(S[j] != T[i]) continue;
	    j++;
	}
	if(j == len1) printf("Yes\n");
	else printf("No\n");
    }
    return 0;
}
