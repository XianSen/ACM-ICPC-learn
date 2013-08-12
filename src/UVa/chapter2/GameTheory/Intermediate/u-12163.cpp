#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int MAXN = 110;
int n, m;
int k[MAXN];
int sg[MAXN];
vector<int> g[MAXN];

int mex(vector<int> &v){
    if(v.empty()) return 0;
    sort(v.begin(), v.end());
    if(v[0] != 0) return 0;
    int size = v.size();
    for(int i = 1; i < size; i++)
	if(v[i] > v[i-1] + 1)
	    return v[i - 1] + 1;
    return v[size - 1] + 1;
}

int get_sg(int n){
    if(sg[n] != -1) return sg[n];
    vector<int> v;
    int size = g[n].size();
    int final_status = (1 << size) - 1;

    if(size > 0)
	for(int status = 0; status <= final_status; status++){
	    int cnt = 0, result = 0;
	    for(int i = 0; i < size; i++)
		if( (status & (1 << i)) != 0){
		    cnt++;
		    result ^= get_sg(g[n][i]);
		}
	    if(cnt <= k[n] && (k[n] - cnt) % 2 == 0)
		v.push_back(result);
	}

    return (sg[n] = mex(v));
}

int main(){
    int tt;
    scanf("%d", &tt);
    for(int kcase = 1; kcase <= tt; kcase++){
	scanf("%d%d", &n, &m);
	printf("Game#%d:\n", kcase);

	for(int i = 0; i < m; i++){
	    int from, to;
	    scanf("%d%d", &from, &to);
	    g[from].push_back(to);
	}

	for(int i = 0; i < n; i++)
	    scanf("%d", k + i);

	memset(sg, -1, sizeof(sg));
	for(int i = 0; i < n; i++)
	    get_sg(i);

	for(int i = 0; i < n; i++)
	    g[i].clear();

	int round;
	scanf("%d", &round);
	for(int r = 1; r <= round; r++){
	    int value, result = 0;
	    for(int i = 0; i < n; i++){
		scanf("%d", &value);
		if(value % 2 == 1)
		    result ^= sg[i];
	    }
	    printf((result? "Round#%d: WINNING\n":"Round#%d: LOSING\n"), r);
	}
	printf("\n");
    }
    return 0;
}
