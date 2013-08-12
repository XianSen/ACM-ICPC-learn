#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using std::vector;
typedef long long LL;
const int MAXN = 40011;
const int INF = 1000000007;

int ex_gcd(int a, int b, int &x, int &y){
    if(b == 0){
	x = 1;
	y = 0;
	return a;
    }else{
	int d = ex_gcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - (a/b)*y;
	return d;
    }
}

int c[MAXN];
int ss[MAXN];
int dp[MAXN];
int father[MAXN];
vector<int> tree[MAXN];

void init(){
    c[0] = 1;
    for(int i = 1; i < MAXN; i++){
	LL a = c[i-1];
	LL b = i; 
	c[i] = (a  * b) % INF;
    }

    int x, y;
    ex_gcd(1, INF, ss[1], y);
    ss[1] = (ss[1] + INF) %INF;

    for(int i = 2; i < MAXN; i++){
	ex_gcd(i, INF, x , y);
	ss[i] = ((LL)ss[i-1]*x) %INF;
	ss[i] = (ss[i] + INF) % INF;
    }

//    printf("%d\n", ss[1]);
}

int treedp(int root, int &num){
//    printf("%d\n", root);
    num = 1;
    //a是son dp的和
    LL a = 1;
    //b是阶乘的和
    LL b = ss[1];

    for(int i = 0; i < tree[root].size(); i++){
	int son = 0;
	LL cc = treedp(tree[root][i], son);
	num += son;
	a = (a * cc) % INF;
	b = (b * ss[son]) % INF;
    }
//printf("%d\n", ss[3]);
    a = (a * c[num - 1]) % INF;
  //  printf("%lld %lld\n", a, b);
    dp[root] = (a * b) % INF;
    dp[root] = (dp[root] + INF) % INF;
//printf("root = %d dp[root] = %d\n", root, dp[root]);

    return dp[root];
}

int main(){
    init();
    int kcase, tcase;
    scanf("%d", &tcase);
    for(kcase = 1; kcase <= tcase; kcase++){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i <= n; i++)
	    tree[i].clear();

	memset(father, -1, sizeof(father));
	for(int i = 0; i < m; i++){
	    int a, b;
	    scanf("%d%d", &a, &b);
	    father[a] = b;
	    tree[b].push_back(a);
	}

	for(int i = 1; i <= n; i++)
	    if(father[i] == -1)
		tree[0].push_back(i);

	int num;
	printf("%d\n", treedp(0, num));
    }
    return 0;
}
