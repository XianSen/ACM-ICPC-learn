#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 11000;

int main(){
    int cow, car, show;
    while(scanf("%d%d%d", &cow, &car, &show) == 3){
	double sum = car + cow;
	//第一次选的是car,没有顺序
	double ans1 = car * 1.0 /sum * (car - 1) / (sum - 1 - show) ;

	//第一次选的是cow, 没有顺序
	double ans2 = cow * 1.0 /sum * car / (sum - 1 - show) ;
	printf("%0.5lf\n", ans1 + ans2);
    }
}
