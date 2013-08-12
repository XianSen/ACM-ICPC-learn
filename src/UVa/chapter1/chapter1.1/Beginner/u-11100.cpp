#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using std::sort;
using std::vector;

const int maxn = 12000;
int line[maxn];

int main(){
    int n, sum;
    while(scanf("%d", &n) != EOF && n){
	for(int i = 0; i < n; i++)	    
	    scanf("%d", line+i);
	sort(line, line+n);
	int ans = 1, last = 1;
	for(int i = 1; i < n; i++)
	    if(line[i] != line[i-1]){
		if(last > ans) ans = last;
		last = 1;
	    }else{
		last++;
	    }

	if(ans < last) ans = last;

	vector<int> vi[ans];

	int r = 0;
	for(int i = 0; i < n; i++){
	    vi[r].push_back(line[i]);
	    r = (r + 1) % ans;
	}

	printf("%d\n", ans);
	for(int i = 0; i < ans; i++)
	    for(int j = 0; j < vi[i].size(); j++)
		if(j == vi[i].size() - 1)
		    printf("%d\n", vi[i][j]);
		else
		    printf("%d ", vi[i][j]);
    }
    return 0;
}
