#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 2011;
const int cnt[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

typedef int* LL;
int num[MAXN][MAXN*5];
int sum[MAXN][MAXN*5];

//a = a + b
void plus(LL a, LL b){
    a[0] = (a[0] > b[0]) ? a[0] : b[0];

    int i, j = 0;
    for (i = 1;i <= a[0]; i++){
	a[i] += j + b[i];
	j = a[i] / 10;
	a[i] %= 10;
    }

    while(j != 0){
	a[++a[0]] = j % 10;
	j /= 10;
    }

    while(a[a[0]] == 0 && a[0] != 1)
	a[0]--;
}

void println(int who){
    for(int i = sum[who][0]; i > 0; i--)
	printf("%d", sum[who][i]);
    printf("\n");
}

void init(){
    memset(num, 0, sizeof(num));
    num[0][0] = 1;
    num[0][1] = 1;

    for(int i = 0; i < MAXN; i++)
	for(int j = 0; j < 10; j++)
	    if(!(i == 0 && j == 0) && i + cnt[j] < MAXN){
		plus(num[i+cnt[j]], num[i]);
	    }

    sum[0][0] = 1;
    sum[0][1] = 0;

    for(int i = 1; i < MAXN; i++){
	sum[i][0] = 1;
	sum[i][1] = 0;

	plus(sum[i], sum[i-1]);
	plus(sum[i], num[i]);
	if(i == cnt[0])
	    plus(sum[i], num[0]);
    }
}


int main(){
    init();
    int n ;
    while(scanf("%d", &n) != EOF){
	if(n == 0) printf("0\n");
	else println(n);
    }
}
