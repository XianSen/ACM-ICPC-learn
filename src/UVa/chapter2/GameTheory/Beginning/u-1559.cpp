#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int MAXN = 22;
int n, num[MAXN];

int mex(vector<int> & v){
    if(v.empty()) return 0;
    sort(v.begin(), v.end());

    if(v[0] != 0) return 0;
    int n = v.size();
    for(int i = 1; i < n; i++)
	if(v[i] > v[i - 1] + 1)
	    return v[i-1] + 1;

    return v[n - 1] + 1;
}

int sg[22][9000];

//人从0-n-1
int f(int who, int s){
    if(sg[who][s] != -1) return sg[who][s];
    int &result = sg[who][s];
    vector<int> v;
    for(int i = num[who]; i > 0; i--)
	if(i < s) v.push_back(f((who + 1) % n, s - i));
    result = mex(v);
    return result;
}

int main(){
    while(scanf("%d", &n) == 1){
	if(n == 0) break;
	n = n * 2;
	int s;
	memset(sg, -1, sizeof(sg));
	scanf("%d", &s);
	for(int i = 0; i < n; i++)
	    scanf("%d", num + i);
	puts(f(0, s) ? "1" : "0");
    }
    return 0;
}
