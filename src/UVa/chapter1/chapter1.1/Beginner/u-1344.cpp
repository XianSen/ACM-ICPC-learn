#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using std::sort;

const int maxn = 1100;
int speed1[maxn];
int speed2[maxn];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;
	for(int i = 0; i < n; i++)
	    scanf("%d", speed1+i);
	for(int i = 0; i < n; i++)
	    scanf("%d", speed2+i);

	sort(speed1, speed1+n);
	sort(speed2, speed2+n);

	int win = 0;
	int equal = 0;

	int l1 = 0, r1 = n - 1;
	int l2 = 0, r2 = n - 1;

	while(l1 <= r1){
	    if(speed1[r1] > speed2[r2]){
		r1--, r2--, win++;
	    }else if(speed1[r1] < speed2[r2]){
		l1++, r2--;	
	    }else if(speed1[r1] == speed2[r2]){
		if(speed1[l1] > speed2[l2]){
		    l1++,l2++; 
		    win++;
		}else {
		    if(speed1[l1] == speed2[r2])
			equal++;
		    l1++, r2--;
		}
	    }
	}

	int ans = win*200 - (n - win - equal) * 200;

	printf("%d\n", ans);
    }
    return 0;
}
