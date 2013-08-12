#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 81;
int values[MAXN];

int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	    scanf("%d", values + i);
	int left = 0;
	int now = 0;
	while(values[now] != 0){
	    now = (now + 1) % n;
	    left ++;
	}

	int right = 0;
	now = n - 1;
	if(~(left & 1))
	while(values[now] != 0){
	    now = (now - 1 + n) % n;
	    right ++;
	}

	if((left & 1) | (right & 1)) puts("YES");
	else puts("NO");
    }
    return 0;
}
