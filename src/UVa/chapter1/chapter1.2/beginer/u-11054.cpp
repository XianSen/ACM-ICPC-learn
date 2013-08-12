#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

typedef long long LL;
using std::cout;
using std::endl;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;
	int val;
	LL ans = 0, now = 0;
	for(int i = 0; i < n; i++){
	    scanf("%d", &val);
	    now = now + val; 
	    if(now < 0) ans += (-now);
	    else ans += now;
	}
	cout << ans << endl;
    }
    return 0;
}
