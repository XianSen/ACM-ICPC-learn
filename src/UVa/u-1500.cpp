#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN = 55; 
const int MAXM = 1100;

bitset<MAXM * MAXN> dp[MAXN];
bitset<MAXM * MAXN> ok[MAXN];

//有n个1,其它的和为m
bool sg(int n, int total){
    if(ok[n].test(total)) 
	return dp[n].test(total);

    if(n == 0) 
	return (total & 1) ? true :false;

    ok[n].set(total);
    int result = 0;
    //把1个1拿掉
    if(!sg(n -1, total))
	result = 1;

    //合并两个小堆的
    int num = 3;
    if(total == 0) num = 2;

    if(n >= 2 && !sg(n - 2, total + num))
	result = 1;    

    //合并一大一小
    if(!sg(n - 1, total + 1))
	result = 1;

    //把大堆的减1
    if(total > 0){
	if(total == 2){
	    if(!sg(n + 1, 0))
		result = 1;
	}else{
	    if(!sg(n, total - 1))
		result = 1;
	}
    }

    if(result)
	dp[n].set(total);
    return result;
}

int main(){
    int tt;
    scanf("%d", &tt);
    for(int kcase = 1; kcase <= tt; kcase++){
	int n, stone, one, total, num;
	one = total = num = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
	    scanf("%d", &stone);
	    if(stone == 1) one ++;
	    else if(stone > 1) {
		num++;
		total += stone;
	    }
	}

	if(num > 0)
	    total += num - 1;

	printf("Case #%d: ", kcase);
	puts(sg(one, total) ? "Alice" :"Bob");
    }
    return 0;
}
