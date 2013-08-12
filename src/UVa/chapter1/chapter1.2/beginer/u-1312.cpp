#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 110;

struct Tree{
    int x;
    int y;
    bool operator<(const Tree &t)const{
	return x < t.x;
    }
}tree[MAXN];

struct sort_by_y{
    bool operator()(const Tree& a, const Tree &b)const{
	return a.y < b.y;
    }
};

int n, w, h, ans[3];

void solve(){
    ans[0] = 0;
    sort(tree, tree+n);
    for(int i = 0; i < n; i++){
	//if((w - tree[i].x) <= ans[0])
	 //   break;

	int upmost = h;
	int downmost = 0;

	for(int j = i + 1; j < n; j++){
	    if(tree[j].y == tree[i].y ) break;//|| upmost - downmost < ans[0]) break;
	    int len = min(upmost - downmost, tree[j].x - tree[i].x);
	    if(len > ans[0]){
		ans[0] = len;
		ans[1] = downmost;
		ans[2] = tree[i].x;
	    }

	    if(tree[j].y < tree[i].y) downmost = max(tree[j].y, downmost);
	    else upmost = min(tree[j].y, upmost);
	}

	upmost = h;
	downmost = 0;
	for(int j = i - 1; j >= 0; j--){
	    if(tree[j].y == tree[i].y) break; //|| upmost - downmost < ans[0]) break;

	    int len = min(upmost - downmost, tree[i].x - tree[j].x);
	    if(len > ans[0]){
		ans[0] = len;
		ans[1] = downmost;
		ans[2] = tree[j].x;
	    }

	    if(tree[j].y < tree[i].y) downmost = max(tree[j].y, downmost);
	    else upmost = min(tree[j].y, upmost);
	}

    }

    sort(tree, tree+n, sort_by_y());
    for(int i = 1; i < n; i++){
	int len = min(w, tree[i].y - tree[i-1].y);
	if(len > ans[0]){
	    ans[0] = len;
	    ans[1] = tree[i-1].y;
	    ans[2] = 0;
	}
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++){
	scanf("%d", &n);
	scanf("%d%d", &w, &h);
	for(int i = 0; i < n; i++)
	    scanf("%d%d", &tree[i].x, &tree[i].y);

	tree[n].x = 0, tree[n].y = 0; n++;
	tree[n].x = w, tree[n].y = 0; n++;
	tree[n].x = 0, tree[n].y = h; n++;
	tree[n].x = w, tree[n].y = h; n++;

	solve();
	printf("%d %d %d\n", ans[2], ans[1], ans[0]);
	if(cas != t) printf("\n");
    }
    return 0;
}
