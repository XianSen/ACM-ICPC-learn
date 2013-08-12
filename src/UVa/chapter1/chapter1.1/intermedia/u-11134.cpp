#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
const int MAXN= 6000;

struct Point{
    int id;
    int right;
    bool operator<(const Point &p) const{ 
	return right > p.right;
    }
};

int n;
int xAns[MAXN];
int yAns[MAXN];

bool check(queue<Point> x[],  int result[]){
    priority_queue<Point> que;
    for(int i = 0; i < n; i++){
	while(!x[i].empty()){
	    que.push(x[i].front());
	    x[i].pop();
	}
	if(que.empty() || que.top().right < i) 
	    return false;
	Point next = que.top();	 
	result[next.id] = i + 1;
	que.pop();
    }
    return true;
}

int main(){
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;
	queue<Point> x[MAXN];
	queue<Point> y[MAXN];
	for(int i = 0; i < n; i++){
	    int xleft, yleft;
	    int xright, yright;

	    scanf("%d%d",&xleft, &yleft);
	    scanf("%d%d",&xright, &yright);

	    x[xleft-1].push((Point){i,xright-1});
	    y[yleft-1].push((Point){i,yright-1});
	}

	if(check(x, xAns) && check(y, yAns)){
	    for(int i = 0; i < n; i++)
		printf("%d %d\n", xAns[i], yAns[i]);
	}else{
	    printf("IMPOSSIBLE\n");
	}
    }
    return 0;
}
