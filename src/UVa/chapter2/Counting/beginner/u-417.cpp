#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 100;
char s[MAXN];

typedef long long LL;
LL c(LL n, LL k){
    if(k > n) return 0;
    if(k == n) return 1;
    LL ans = 1;
    for(int i = 0; i < k; i++)
	ans = ans * (n - i);
    for(int i = 0; i < k; i++)
	ans = ans / (i + 1);
    return ans;
}

bool check(char *s){
    int n = strlen(s);
    for(int i = 1; i < n; i++)
	if(s[i] <= s[i-1]){
	    return false;
	}
    return true;
}

LL calc(char * s){
    int n = strlen(s);
    LL ans = 0;
    for(int i = 1; i < n; i++)
	ans += c(26, i);

    for(int i = 0; i < n - 1; i++){
	int remain = n - i - 1;

	char min = 'a' - 1;
	if(i != 0) min = s[i - 1];

	for(int j = min + 1; j < s[i]; j++){
	    ans += c('z' - j, remain);
	}
    }

    if(n == 1){
	ans += s[n - 1] - 'a' + 1;
    }else{
	ans += s[n - 1] - s[n - 2];
    }
    return ans;
}

int main(){
    while(scanf("%s", s) != EOF){
	LL ans = 0;
	if(check(s)) ans = calc(s);
	printf("%lld\n", ans);
    }
    return 0;
}
