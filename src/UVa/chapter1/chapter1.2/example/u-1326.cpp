//u-1326 Jurassic Rermains
#include <map>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;
const int MAXN = 30;
const int MAXM = 300;

int num[MAXN];
char s[MAXM];

int countBit(int i){
    if(i == 0) return 0;
    else return (countBit(i/2) + (i&1));
}

int converToBit(char *s){
    int result = 0;
    while((*s) != 0){
	result ^= (1 << ((*s) - 'A'));
	s += 1;
    }
    return result;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
	for(int i = 0; i < n; i++){
	    scanf("%s",s);
	    num[i] = converToBit(s);
	}

	int n1 = n / 2;
	int n2 = n - n1;

	map<int,int> mii;
	for(int i = 0; i < (1 << n1); i++){
	    int x = 0;
	    for(int j = 0; j < n1; j++)
		if(i & (1 << j))
		    x ^= num[j];
	    if(!mii.count(x) || countBit(mii[x]) < countBit(i))
		mii[x] = i;
	}

	int ans = 0;

	for(int i = 0; i < (1 << n2); i++){
	    int x = 0;
	    for(int j = 0; j < n2; j++)
		if(i & (1 << j))
		    x ^= num[j + n1];
	    if(mii.count(x) && countBit(ans) < countBit(i) + countBit(mii[x]))
		ans = (i << n1)^(mii[x]);
	}

	printf("%d\n", countBit(ans));
	int first = true;
	for(int i = 0; i < n; i++)
	    if(ans & (1 << i)){
		if(!first){
		    printf(" %d", i+1);
		}else{
		    first = false;
		    printf("%d", i+1);
		}
	    }
	printf("\n");
    }
    return 0;
}
