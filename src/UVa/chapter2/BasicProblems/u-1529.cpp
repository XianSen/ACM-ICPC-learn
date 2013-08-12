#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calc(int a, int b, int &flag){
    flag = 0;
    int ans = a - 1;
    if(a > 12){
	a -= 12;
	ans -= 1;
    }

    if( 55 * b >= 5 * 55 * a + 25 * a){
	ans++;
    } 

    return ans;
}

int main(){
    int a, b, c, d;
    puts("Program 3 by team X");
    puts("Initial time  Final time  Passes");
    while(scanf("%d%d%d%d", &a, &b, &c, &d) == 4){
	int flag1, flag2;
	int ansl = calc(a, b, flag1);
	int ansr = 0;
	if(c < a || c == a && d < b){
	    ansr = calc(c + 12, d,flag2);
	}else{
	    ansr = calc(c, d,flag2);
	}
	int ans = ansr - ansl;

	printf("       %02d:%02d       %02d:%02d      %2d\n", a, b, c, d,ans);
    }
    puts("End of program 3 by team X");
    return 0;
}
