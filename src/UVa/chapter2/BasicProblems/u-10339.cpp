#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//时钟问题,以现实为标准
typedef long long LL;

const LL DAY12 = 12 * 60 *  60;
const LL DAY24 = 24 * 60 *  60;

int main(){
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
	printf("%d %d ", a, b);
	if(a == b){
	    printf("12:00\n");
	    continue;
	}

	LL x = abs(a - b);
	LL sum = (DAY12 * (DAY24 - a) / x) % DAY12;
	LL second = sum % 60;
	LL mm = (sum / 60) % 60;	

	if(second * 2 >= 60)
	    mm++;
	LL hh = sum / 3600;
	if(mm == 60){
	    mm = 0;
	    hh++;
	}

	hh %= 12;
	if(hh == 0) hh = 12;
	printf("%02lld:%02lld\n", hh, mm);
    }
    return 0;
}
