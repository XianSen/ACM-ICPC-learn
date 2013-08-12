#include <map>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
const int MAXN = 21;

int tt = 0, sum;
int cannot[1 << (MAXN + 1)]; 
int sg[1 << (MAXN + 1)]; 
int ok[1 << (MAXN + 1)]; 
int vist;


int mex(vector<int> & v){
    if(v.empty()) return 0;
    sort(v.begin(), v.end());
    if(v[0] != 0) return 0;
    int size = v.size();
    for(int i = 1; i < size; i++)
	if(v[i] > v[i - 1] + 1)
	    return v[i - 1] + 1;
    return v[size - 1] + 1;
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

    vector<int> v;
    int vist = g(status);
    for(int i = 1; i < 20; i++)
	if((sum & (1 << i)) != 0 && (vist & (1 << i )) == 0){
	    v.push_back(f(status | (1 << i)));
	}

    ok[status] = tt;
    sg[status] = mex(v);

    return sg[status];//mex(v);//sg[status];
}

int main(){
    int n, kcase, tt;
    tt = 0;
    memset(ok, -1, sizeof(ok));
    memset(cannot, -1, sizeof(cannot));

    scanf("%d", &kcase);
    while(kcase--){
//while(scanf("%d", &n) == 1){
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
	for(int i = 1; i < 20; i++)
	    if((sum & (1 << i)) == 0){
		t |= (1 << i);
	    }

	for(int i = 1; i < 20; i++)
	    if((sum & (1 << i)) != 0){
		if(f( (1 << i) | t) == 0)
		    ans.push_back((i + 1) );
	    }

	//if(tt != 0) printf("\n");
//	printf("Test Case #%d\n", ++tt);
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
