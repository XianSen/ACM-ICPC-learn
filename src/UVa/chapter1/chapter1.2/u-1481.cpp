#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 4000;
int a[MAXN];
int b[MAXN];

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n){
	for(int i = 0; i < n; i++)
	    scanf("%d", a + i);
	for(int i = 0; i < n; i++){
	    int val;
	    scanf("%d", &val);
	    b[val] = i;
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	    a[i] = b[a[i]];

	for(int i = 0; i < n; i++){
	    int max = -1;
	    int min = n;
	    for(int j = i; j < n; j++){
		if(a[j] > max) max = a[j];
		if(a[j] < min) min = a[j];
		if(max - min == j - i && j - i >= 1)
		    ans++;
	    }
	}
	printf("%d\n", ans);
    }
    return 0;
}
