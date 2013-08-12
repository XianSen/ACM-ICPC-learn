#include <map>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#define FOR(i) for(t[i] = t[i-1] + 1; t[i] < n; t[i]++)
#define FOR1(i) for(t[i] = 0; t[i] < n; t[i]++)

using namespace std;

int n = 16;
const int MAXN = 16;
const int MAXK = (1 << MAXN);

int b[MAXN];
int a[MAXN];

typedef long long LL;

LL count[MAXK];
LL find(int a[]){
    LL ans = 0;
    int t[4];
    map<int,map<int,int> > mimi;
    int n = 8;
    
    FOR1(0) FOR1(1) FOR1(2) FOR1(3){
	int can = true;
	for(int i = 0; i < 4; i++)
	    for(int j = i + 1; j < 4; j++)
		if(t[i] == t[j]){
		    can = false;
		    break;
		}
	if(can){
	    int status = 0, sum = 0;
	    for(int i = 0; i < 4; i++){
		status = status + (1 << t[i]);
		sum += a[t[i]]*(i+1);
	    }
	    int s = 1; 
	    if(mimi.find(status) != mimi.end() && 
		    mimi[status].find(sum) != mimi[status].end())
		s = mimi[status][sum] + 1;
	    mimi[status][sum] = s;
	}
    }

    FOR1(0) FOR1(1) FOR1(2) FOR1(3){
	int can = true;
	for(int i = 0; i < 4; i++)
	    for(int j = i + 1; j < 4; j++)
		if(t[i] == t[j]){
		    can = false;
		    break;
		}
	if(can){
	    int status = 0, sum = 0;
	    for(int i = 0; i < 4; i++){
		status = status + (1 << t[i]);
		sum += a[t[i]] * (i + 1);
	    }
	    int s = 0;
	    status = 255 - status;
	    if(mimi.find(status) != mimi.end() && 
		    mimi[status].find(sum) != mimi[status].end())
		s = mimi[status][sum];
	    ans +=  s; 
	}
    }
    return ans/2;
}

int main(){
    int cas = 0;
    while(scanf("%d", &a[0]) != EOF){
	if(a[0] == 0) break;
	for(int i = 1; i < n; i++)
	    scanf("%d", a+i);
	int t[9];
	LL ans = 0;

	t[0] = -1;		
	memset(count, 0, sizeof(count));

	FOR(1) FOR(2) FOR(3) FOR(4)
	FOR(5) FOR(6) FOR(7) FOR(8){
	    int status = 0;
	    for(int i = 1; i <= 8; i++)
		status = status + (1 << t[i]);
	    for(int i = 0; i < 8; i++)
		b[i] = a[t[i + 1]];

	    count[status] = find(b);
	}
	int sum = (1 << MAXN) - 1;
	FOR(1) FOR(2) FOR(3) FOR(4)
	FOR(5) FOR(6) FOR(7) FOR(8){
	    int status = 0;
	    for(int i = 1; i <= 8; i++)
		status = status + (1 << t[i]);
	    ans += count[status] * count[sum - status];
	}
	printf("Case %d: ", ++cas);
	cout << ans/2 << endl;
    }
    return 0;
}
