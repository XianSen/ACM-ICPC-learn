#include <map>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
const int MAXN = 20;

int tt = 0, sum;
int cannot[1 << (MAXN + 1)]; 
int sg[1 << (MAXN + 1)]; 
int ok[1 << (MAXN + 1)]; 
int vist;


int mex(int v){
    for(int i = 0; i <= 30; i++)
	if((v & (1 << i)) == 0)
	    return i;
}

int g(int status){
    if(cannot[status] != -1) return cannot[status];
    int &result = cannot[status];
    result = 0;
    for(int i = 1; i < 20; i++)
	if( (status & (1 << i)) != 0){
	    result = g(status - (1 << i));
	    result |= (1 << i);
	    for(int j = i + 2; j <= 20; j++){
		int k = j - (i + 1) - 1;
		if((result & (1 << k)) != 0)
		    result |= (1 << (j - 1));
	    }
	    break;
	}
    return result;
}

int f(int status){
    if( (status & sum) == sum) return 0;
    if(ok[status] == tt) return sg[status];

    int v = 0;
    int vist = g(status);
    for(int i = 1; i < 20; i++)
	if((sum & (1 << i)) != 0 && (vist & (1 << i )) == 0){
	    int s = f(status | (1 << i));
	    if(s <= 30)
		v |= (1 << s);
	}

    ok[status] = tt;
    sg[status] = mex(v);

    return sg[status];
}

int main(){
    int n, kcase, tt;
    tt = 0;
    memset(ok, -1, sizeof(ok));
    memset(cannot, -1, sizeof(cannot));

    int ddd = 0;
    for(int i = 1; i < 20; i++)
	if((sum & (1 << i)) == 0){
	    ddd |= (1 << i);
	}

    scanf("%d", &kcase);
    while(kcase--){
   // while(scanf("%d", &n) == 1){
	scanf("%d", &n);
	sum = 0;
	for(int i = 0; i < n; i++){
	    int a;
	    scanf("%d", &a);
	    if(a <= 20 && a >= 1)
		sum |= (1 << (a - 1));
	}

	vector<int> ans;
	int t = 0;

	t = ddd - sum;
	for(int i = 1; i < 20; i++)
	    if((sum & (1 << i)) != 0){
		if(f( (1 << i) | t) == 0)
		    ans.push_back((i + 1) );
	    }

	printf("Scenario #%d:\n", ++tt);
	if(ans.empty()){
	    puts("There is no winning move.");
	}else{
	    printf("The winning moves are: ");
	    int size = ans.size();
	    for(int i = 0; i < size; i++)
		if(i == size - 1) printf("%d.\n", ans[i]);
		else printf("%d ", ans[i]);
	}
	printf("\n");
    }
    return 0;
}
