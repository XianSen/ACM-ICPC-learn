#include <map>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define MK(x,y) (make_pair((x), (y)))
using namespace std;

int getLongNum(){
    char c = getchar();
    while(!isdigit(c) && c != '-')
	c = getchar();
    if(c == '-') return -getLongNum();
    int num = 0;
    while(isdigit(c)){
	num = c - '0' + num * 10;
	c = getchar();
    }
    return num;
}


int main(){
    int n;
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;
	map<pair<int,int>, int> mpi;
	for(int i = 0; i < n; i++){
//	    int a;
//	    int b;
//	    cin >> a >> b;
	    int a = getLongNum();
	    int b = getLongNum();
	    if(mpi.count(MK(a,b)) != 0){
		mpi[MK(a,b)]++;
	    }else{
		mpi[MK(a,b)] = 1;
	    }
	}

	map<pair<int,int>,int>::iterator it = mpi.begin();
	map<pair<int,int>,int>::iterator end = mpi.end();

	bool can = true;
	while(it != end){
	    pair<int,int> re = MK(it->first.second, it->first.first);

	    if(mpi.find(re) == end || mpi[re] != it->second){
//    printf("%d %d\n", re.first, re.second);
		can = false;
		break;
	    }
	    it++;
	}
	if(can) printf("YES\n");
	else printf("NO\n");
    }
    return 0;
}
