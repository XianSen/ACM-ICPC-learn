#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#define FOR(i) for(t[i] = 0; t[i] < n; t[i]++)
using namespace std;

const int MAXN = 16;
const int MAXM = 10240;
typedef long long LL;
int num[MAXN];
LL res[1 << 16];

int main(){
    int cas = 0, n = 16;
    while(scanf("%d", &num[0]) != EOF){
	if(num[0] == 0) break;
	for(int i = 1; i < n; i++)
	    scanf("%d", num+i);
	vector<int> vi[MAXM];
	int t[MAXN];
	FOR(0) FOR(1) FOR(2) FOR(3){
	    int can = true;
	    for(int i = 0; i < 4; i++)
		for(int j = i + 1; j < 4 && can; j++)
		    if(t[i] == t[j]) can = false;
	    if(can){
		int sum = 0;
		int status = 0;
		for(int i = 0; i < 4; i++){
		    sum += num[t[i]] * (i+1);
		    status +=  (1 << t[i]);
		}
		vi[sum].push_back(status);
	    }
	}

	memset(res, 0, sizeof(res));
	for(int i = 0; i < MAXM; i++){
	    int size = vi[i].size();
	    for(int j = 0; j < size; j++)
		for(int k = j + 1; k < size; k++)
		    if((vi[i][j] & vi[i][k]) == 0)
			res[vi[i][j] | vi[i][k]]++;
	}

	LL ans = 0;
	int max = (1 << 16) - 1;
	for(int i = 0; i < max/2; i++)
	    ans += res[i] * res[max - i];

	printf("Case %d: ",++cas);
	cout << ans << endl;
    }
    return 0;
}
