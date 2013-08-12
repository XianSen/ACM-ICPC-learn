#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 1010;
int f[MAXN];

int get_sign(){
    char c = getchar();
    while(c != '0' && c != '1')
	c = getchar();
    return c;
}

int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
	int n;
	scanf("%d", &n);
	memset(f, 0, sizeof(f));

	for(int i = 1; i <= n; i++){
	    for(int j = i + 1; j <= n; j++)
		if (get_sign() == '1'){
		    f[i] ++;
		    f[j] ++;
		}
	    }

	int ans = 0;
	for(int i = 1; i <= n; i++){
	    ans += f[i] * (n - f[i] - 1);
	}
	

	ans = n * (n - 1) * (n - 2) / 3 / 2 - ans / 2;
	printf("%d\n", ans);
    }
    return 0;
}
