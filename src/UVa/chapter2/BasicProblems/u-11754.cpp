#include <set>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

typedef long long LL;
using namespace std;

const int MAXC = 90;
const int MAXS = 100;
const int LIMIT = 10000;

int a[MAXC];

vector<LL> sol;
set<int> values[MAXC];

int S, C;
int X[MAXC], k[MAXC];
int Y[MAXC][MAXS];

//数论常用函数
LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}

//求 ax + by = d的一组(x,y), 并且使得 |x| + |y|的值最小
void gcd(LL a, LL b, LL &d, LL &x, LL &y){
    if(!b) {d = a; x = 1; y = 0;}
    else {gcd (b, a % b, d, y, x); y -= x * (a / b);}
}

//计算n下a的逆.如果不存在逆,返回-1
LL inv(LL a, LL n){
    LL d, x, y;
    gcd(a, n, d, x, y);
    return d == 1 ? (x + n) % n : -1;
}

//n 个方程: x = a[i] (mod m[i]) (0 <= i < n)
LL china(int n, int * a, int *m){
    LL M = 1, d, y, x = 0;
    for(int i = 0; i < n; i++)
	M *= m[i];
    for(int i = 0; i < n; i++){
	LL w = M / m[i];
	gcd(m[i], w, d, d, y);
	x = (x + y * w * a[i]) % M;
    }
    return (x + M) % M;
}

void solve_enum(int S, int bc){
    for(int i = 0; i < C; i++){
	values[i].clear();
	if(i != bc)
	    for(int j = 0; j < k[i]; j++)
		values[i].insert(Y[i][j]);
    }

    for(int t = 0; S != 0; t++){
	for(int y = 0; y < k[bc]; y++){
	    LL now = t * (LL)X[bc] + (LL)Y[bc][y];
	    if(now == 0) continue;

	    int ok = true;
	    for(int i = 0; i < C && ok; i++) 
		if(i != bc)
		    if(!values[i].count(now % X[i]))
			ok = false;
	    if(ok) {
		printf("%lld\n", now);
		if(--S == 0) break;
	    }
	}
    }
}

void dfs(int dep){
    if(dep == C){
	sol.push_back(china(C, a, X));
    }else{
	for(int i = 0; i < k[dep]; i++){
	    a[dep] = Y[dep][i];
	    dfs(dep + 1);
	}
    }
}

void solve_china(int S){
    sol.clear();
    dfs(0);
    sort(sol.begin(), sol.end());

    LL M = 1;
    for(int i = 0; i < C; i++) M *= X[i];

    for(int i = 0; S != 0; i++){
	for(int j = 0; j < sol.size(); j++){
	    LL now = M * i + sol[j];
	    if(now > 0){
		printf("%lld\n", now);
		if(--S == 0) break;
	    }
	}
    }
}

int main(){
    while(scanf("%d%d", &C, &S) != EOF){
	int tot = 1;
	int bestc = 0;

	if(S == 0 && C == 0) break; 

	for(int c = 0; c < C; c++){
	    scanf("%d%d", &X[c], &k[c]);
	    tot = tot * k[c];
	    for(int i = 0; i < k[c]; i++)
		scanf("%d", &Y[c][i]);
	    sort(Y[c], Y[c] + k[c]);
	    if(k[c] * X[bestc] < k[bestc] * X[c]) bestc = c;
	}

	if(tot > LIMIT) solve_enum(S, bestc);
	else solve_china(S);

	printf("\n");
    }
    return 0;
}
