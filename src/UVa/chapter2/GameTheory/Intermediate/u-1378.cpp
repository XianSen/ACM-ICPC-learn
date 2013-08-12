#include <vector>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int MAXN = 1100;

int sg[MAXN];
int n, tt = 0;
int stone[MAXN];

int mex(vector<int> & v){
    if(v.empty()) return 0;
    sort(v.begin(), v.end());
    if(v[0] != 0) return 0;
    int size = v.size();
    for(int i = 1; i < size; i++)
	if(v[i] > v[i-1] + 1)
	    return v[i-1] + 1;
    return v[size-1] + 1;
}

int g(int n){
    if(sg[n] != -1) return sg[n];
    vector<int> v; 
    for(int i = 0; i < n; i++) 
	for(int j = 0; j < n; j++)
	    v.push_back(g(i) ^ g(j));
    return (sg[n] = mex(v));
}

void init(){
    memset(sg, -1, sizeof(sg));
    sg[0] = 0;
}

bool check(int i, int j, int k){
    int ans = 0;
    stone[i]--;
    stone[j]++;
    stone[k]++;

    for(int l = 0; l < n; l++)
	if(stone[l] % 2 == 1)
	    ans ^= g(n - l - 1);

    stone[i]++;
    stone[j]--;
    stone[k]--;
    return ans == 0? true : false;
}

int main(){
    init();
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;

	for(int i = 0; i < n; i++)
	    scanf("%d", stone + i);

	int flag = 1;
	int ans[3];
	memset(ans, -1, sizeof(ans));
	for(int i = 0; i < n && flag; i++) 
	    if(stone[i] != 0)
	    for(int j = i + 1; j < n && flag; j++)
		for(int k = j; k < n && flag; k++)
		    if(check(i, j, k)){
			ans[0] = i; 
			ans[1] = j; 
			ans[2] = k;
			flag = 0;
			break; 
		    }

	printf("Game %d: %d %d %d\n", ++tt, ans[0], ans[1], ans[2]);
    }
    return 0;
}
