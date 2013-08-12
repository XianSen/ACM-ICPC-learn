#include <queue>
#include <vector>
#include <iostream>
using namespace std;

const int maxn = 1000;
const int INF = 0x7fffffff;

int min(int a, int b){
    if(a < b) return a;
    else return b;
}

struct Edge{
    int from, to, flow, cap;
};

struct Isap{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G;
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    int p[maxn];
    int num[maxn];
    
    void AddEdge(int from, int to, int cap){
	edges.push_back((Edge){from, to, cap, 0});
	edges.push_back((Edge){to, from, 0, 0});
	m = edges.size();
	G[from].push_back(m-2);
	G[to].push_back(m-1);
    }

    int Augment(){
	int x = t, a = INF;
	while(x != s){
	    Edge & e = edges[p[x]];
	    a = min(a, e.cap-e.flow);
	    x = edges[p[x]].from;
	}
	x = t;
	while(x != s){
	    edges[p[x]].flow += a;
	    edge[p[x]^1].flow -= a;
	    x = edges[p[x]].from;
	}
	return a;
    }

    bool BFS(){
    }

    int Maxflow(int s, int t){
	this->s = s; this->t = t;
	int flow = 0;
	BFS();
	memset(num, 0, sizeof(num));
	for(int i = 0; i < n; i++) num[d[i]]++;
	int x = s;
	memset(cur, 0, sizeof(cur));
	while(d[s] < n){
	    if(x == t){
		flow += Augment();
		x = s;
	    }
	int ok = 0;
	for(int i = cur[x]; i < G[x].size(); i++){
	    Edge & e = edges[G[x][i]];
	    if(e.cap > e.flow && d[x] == d[e.to] + 1){
		ok = 1;
		p[e.to] = G[x][i];
		cur[x] = i;
		x = e.to;
		break;
	    }
	}
	if(!ok){
	    int m = n - 1;
	    for(int i = 0; i < G[x].size(); i++){
		Edge &e = edges[G[x][i]];
		if(e.cap > e.flow) m = min(m, d[e.to]);
	    }
	    if(--num[d[x]] == 0) break;
	    num[d[x] = m+1]++;
	    cur[x] = 0;
	    if(x != s) x = edges[p[x]].from;
	}
	}
	return flow;
    }
};

int main(){
    return 0;
}
