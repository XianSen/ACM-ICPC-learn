#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;

/*
 * 现在在跳到kth步
 * 现在在第k步
 */
int find(int k, int st){
    int step = 2 * k - 1; 
    if(st == m) return true;
    if(st - step > 0 && find(k + 1, st - step))
	return true;
    if(st + step <= n && find(k + 1, st + step))
	return true;
    return false;
}

int main(){
    while(scanf("%d%d", &n, &m) != EOF){
	if(n == 0 && m == 0) break;
	if(n >= 49 || find(2, 1))
	    printf("Let me try!\n");
	else
	    printf("Don't make fun of me!\n");
    }
    return 0;
}
