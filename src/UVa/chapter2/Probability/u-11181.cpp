#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

const int MAXN = 20;
int vist[(1 << 20) + 2];
double p[(1 << 20) + 2];
double dp[(1 << 20) + 2];
double ans[MAXN + 1];

using namespace std;

int main(){
    int n, r, tt = 0;
    while(scanf("%d%d", &n, &r) == 2){
	if(n == 0 && r == 0) break;
	double sum = 1;
	for(int i = 0; i < n; i++)
	    scanf("%lf", &p[1 << i]);

	memset(vist, 0, sizeof(vist));
	vector<int> v[2];
	int now = 0, last = 1;
	v[0].push_back(0);

	int max = (1 << n) - 1;
	for(int i = 0; i < r; i++){
	    now = 1 - now;
	    last = 1 - last;
	    v[now].clear();
	    int size = v[last].size();
	    for(int j = 0; j < size; j++){
		int num = v[last][j];
		int num1 = max - num;
		while(num1){
		    int next = num1 & (-num1);
		    num1 = num1 - next;
		    if(vist[num | next] == 0){
			vist[num | next] = 1;
			v[now].push_back(num | next);
		    }
		}
	    }
	}

	sum = 0;
	for(int k = 0; k < n; k++){
	    int t = (1 << k);
	    ans[k] = 0;
	    for(int i = 0; i < v[now].size(); i++){
		if(v[now][i] & t){
		    int who = v[now][i];
		    double value = 1;
		    for(int j = 0; j < n; j++)
			if(who &(1 << j)){
			    value = value * p[1 << j];
			}else{
			    value = value * (1 - p[1 << j]);
			}
		    ans[k] += value;
		}
	    }
//	    sum += ans[k];
	}
	sum = 0;
	for(int i = 0; i < v[now].size(); i++){
		int who = v[now][i];
		double value = 1;
		for(int j = 0; j < n; j++)
		    if(who &(1 << j)){
			value = value * p[1 << j];
		    }else{
			value = value * (1 - p[1 << j]);
		    }
		sum += value;
	    }
printf("%lf\n", sum);
	    printf("Case %d:\n", ++tt);
	    for(int i = 0; i < n; i++)
		printf("%0.6lf\n", ans[i] / sum);

	}
	return 0;
    }
