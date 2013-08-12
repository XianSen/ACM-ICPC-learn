#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using std::sort;

int n, m, l;
const int maxn = 110;

struct Agency{
    int cost;
    char  name[20];
    bool operator<(const Agency & a)const{
	if(cost < a.cost) return true;
	if(cost > a.cost) return false;
	return (strcmp(name, a.name) < 0); 
    }
};

Agency agency[maxn];

int calc(int a, int b){
    int h = n;
    int cost = 0;
    while(h > m){
	int mid = (h + 1) / 2;
	if(h - mid < m){
	    h--; 
	    cost = cost + a;
	}else{
	    int cost1 = b;
	    int cost2 = mid * a;
	    if(cost1 <= cost2){
		h -= mid;
		cost = cost + b;
	    }else{
		h--; 
		cost = cost + a;
	    }
	}
    }
    return cost;
}

void getName(char *s){
    char c = getchar();
    while(c == '\n' || c == ' ')
	c = getchar();
    for(int i = 0;; i++){  
	s[i] = c;
	c = getchar();
	if(c == ':') return; 
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
	scanf("%d%d%d", &n, &m, &l); 
	for(int i = 0; i < l; i++){
	    int a, b;
	    memset(agency[i].name, 0, sizeof(agency[i].name));
	    getName(agency[i].name);
	    scanf("%d,%d", &a, &b);
	    agency[i].cost = calc(a, b);
	}

	printf("Case %d\n", cas);
	sort(agency, agency + l);
	for(int i = 0; i < l; i++)
	    printf("%s %d\n", agency[i].name, agency[i].cost);
    }
    return 0;
}
