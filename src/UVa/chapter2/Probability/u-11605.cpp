#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//返回成功的概率
double calc(int x, int w){
    double len1 = x - 1;
    double len2 = w - x;
    double p1 = len1 / w;
    double p2 = len2 / w;
    return 1 - p1*p1 - p2 * p2;
}

//快速幂
double pow(double p1, int k){
    if(k == 0) return 1;
    double ans = pow(p1, k >> 1);
    ans = ans * ans;
    if(k & 1) ans *= p1;
    return ans;
}

//返回 有turn轮，每轮有改变的概率为p的情况下的期望
double solve(double p, int turn){
    double p1 = (1 - p) + p;
    double p2 = (1 - p) - p;
    return (pow(p1, turn) - pow(p2, turn)) / 2.0;
}

int main(){
    int tt, n, m, p, turn;
    scanf("%d", &tt);
    for(int kcase = 1; kcase <= tt; kcase++){
	printf("Case %d: ", kcase);
	scanf("%d%d%d%d", &n, &m, &p, &turn);
	double ans = 0;
	for(int i = 1; i <= n; i++)
	    for(int j = 1; j <= m; j++)
		for(int k = 1; k <= p; k++){
		    double _p = calc(i, n) * calc(j, m) * calc(k, p);
		    ans += solve(_p, turn);
		}
	printf("%0.10lf\n", ans);
    }
    return 0;
}
