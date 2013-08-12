#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxn = 400;
const int maxk = 5;

bool ok[maxn];
char map[maxn][maxk];

char s1[maxn];
char s2[maxn];

int K, len1, len2;
int &k = K;

bool check(int, int);

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
	scanf("%d", &K);
	scanf("%s",s1);
	scanf("%s",s2);
	
	len1 = strlen(s1);
	len2 = strlen(s2);

	memset(ok, false, sizeof(ok));
	printf("%d\n", check(0, 0));
    }
    return 0;
}

bool check(int l1, int l2){
    if(len1 == l1  && len2 == l2)
	return true;
    if(len1 == l1  && len2 != l2)
	return false;
    int tmp = s1[l1];
    char s[maxk] = {0};     
    for(int i = 1; i <= k && len2 - l2 >= i; i++){
	s[i-1] = s2[l2 + i - 1];
	if(ok[tmp]){
	    if(strcmp(s, map[tmp]) == 0)
		if(check(l1+1, l2+i))
		    return true;
	}else{
	    ok[tmp] = true;
	    strcpy(map[tmp], s);;
	    if(check(l1+1, l2+i))
		return true;
	    ok[tmp] = false;
	}
    }
    return false;
}
