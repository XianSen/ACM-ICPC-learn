//Minimal coverage
#include <map>
#include <vector>
#include <iterator>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#define MP(a,b) (make_pair((a),(b)))

using std::pair;
using std::sort;
using std::vector;
using std::unique;
using std::make_pair;

typedef pair<int,int> Pair;

const int maxn = 110000;

int m;

int main(){
    int cas;
    scanf("%d", &cas);
    while(scanf("%d", &m) != EOF){
	vector<Pair> vp;
	vector<Pair> ans;

	int a, b;
	scanf("%d%d", &a, &b);
	while(a != 0 || b != 0){
	    if(a != b && b > 0 && a < m)
		vp.push_back(MP(a, b));
	    scanf("%d%d",&a, &b);
	}

	sort(vp.begin(), vp.end());

	int nr = unique(vp.begin(), vp.end()) - vp.begin();
	
	int cur = 0;
	int last = 0;

	for(int i = 0; i < nr && last < m; i++){
	    if(vp[i].first > last) break;
	    if(vp[i].second < last) continue;

	    if(vp[i].first > cur){
		cur = last;
		last = vp[i].second;
		ans.push_back(vp[i]);
	    }else{
		last = vp[i].second;
		if(ans.size() == 0){
		    ans.push_back(vp[i]);
		}
	        ans.back() = vp[i];
	    }
	}

	if(last >= m){
	    int size = ans.size(); 
	    printf("%d\n", size);
	    for(int i = 0; i < size; i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	}else{
	    printf("0\n");
	}
    
	cas--;
	if(cas > 0) printf("\n");
    }
    return 0;
}
