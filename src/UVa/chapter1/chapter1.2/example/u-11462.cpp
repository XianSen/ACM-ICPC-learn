#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxn = 110;
int age[maxn];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
	int val;
	if(n == 0) break;
	memset(age, 0, sizeof(age));
	for(int i = 0; i < n; i++){
	    scanf("%d", &val);
	    age[val] ++;
	}
	bool flag = true;
	for(int i = 0; i < maxn; i++)
	    for(int j = 0; j < age[i]; j++)
		if(!flag) printf(" %d", i);
		else{
		    flag = false;
		    printf("%d", i);
		}
	printf("\n");
    }
    return 0;
}
