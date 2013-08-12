#include <map>
#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#define MK(x, y) (make_pair<int,int>((x), (y)))

using namespace std;
const int MAXN = 110;

int n;
typedef pair<int,int> Edge;
vector<Edge> edge;

bool find(int n, queue<int> que[]){
    int i, j;
    while(!que[1].empty() || !que[2].empty() || !que[3].empty()){
	for(i = 3; i >= 0; i--)
	    if(!que[i].empty())
		break;
	Edge now;
	now.first = i;
	now.second = que[i].front();
	que[i].pop();

	//得到i个元素
	Edge ele[3];
	for(i = 0; i < now.first; i++){
	    int done = false;
	    for(int j = 3; j > 0; j--)
		if(!que[j].empty()){
		    ele[i].first = j;
		    ele[i].second = que[j].front();
		    que[j].pop();
		    done = true;
		    break;
		}
	    if(!done) return false;
	}

	for(i = 0; i < now.first; i++){
	    edge.push_back(MK(now.second, ele[i].second));
	    ele[i].first--;
	    if(ele[i].first > 0)
		que[ele[i].first].push(ele[i].second);
	}
    }
    return true;
}

int main(){
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;

	edge.clear();
	queue<int> que[4];

	for(int i = 1; i <= n; i++)
	    que[3].push(i);

	if(n % 2 == 1 ){
	    printf("Impossible\n");
	}else if (!find(n, que)){
	    printf("Impossible\n");
	} else{
	    int sumEdge = (n * 3) / 2; 
	    printf("%d\n", sumEdge);
	    sort(edge.begin(), edge.end());
	    for(int i = 0; i < sumEdge; i++)
		printf("%d %d\n", edge[i].first, edge[i].second);
	}
    }
    return 0;
}
