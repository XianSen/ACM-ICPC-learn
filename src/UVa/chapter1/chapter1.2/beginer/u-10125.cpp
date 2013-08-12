#include <map>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define MPI(x,y) ((Point){(x),(y)})
#define MP(x,y,z) make_pair((x),MPI(y,z))

using namespace std;
const int MAXN = 1100;

struct Point{
    int x;
    int y;
};

typedef long long LL;
typedef multimap<LL, Point> MLP;
typedef MLP::iterator Pint; 
const LL INF = 546870912;


int n;
LL s[MAXN];

LL getLongNum(){
    char c = getchar();
    while(!isdigit(c) && c != '-')
	c = getchar();

    if(c == '-') return -getLongNum();
    LL num = 0;
    while(isdigit(c)){
	num = c - '0' + num * 10;
	c = getchar();
    }

    return num;
}



int distinct(int a, int b, int c, int d){
    if(a == b || a == c || a == d) return false;
    if(b == c || b == d) return false;
    if(c == d) return false;
    else return true;
}

int main(){
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;
	for(int i = 0; i < n; i++){
//	    cin >> s[i];
	    s[i] = getLongNum();
	}

	sort(s, s + n);
	multimap<LL, Point> mlp;

	for(int i = 0; i < n; i++)
	    for(int j = i + 1; j < n; j++){
		LL val = s[i] + s[j];
		mlp.insert(MP(val,i,j));
	    }

	LL ans;
	bool find = false;
	
	for(int i = n - 1; i >= 0 && !find; i--)
	    for(int j = 0; j <  n && !find; j++)
		if(i != j && mlp.count(s[i] - s[j]) ){
		    LL val = s[i] - s[j];

		    pair<Pint,Pint> pp = mlp.equal_range(val);

		    Pint start = pp.first;
		    Pint end = pp.second;
		    while(start != end){
		     if(distinct(i, j, start->second.x, start->second.y)){
			    ans = s[i];
			    find = true;
			    break;
		       }
		     start++;
		    }
		}

	if(find){
	    cout << ans << endl;
	}else{
	    printf("no solution\n");
	}
    }
    return 0;
}
