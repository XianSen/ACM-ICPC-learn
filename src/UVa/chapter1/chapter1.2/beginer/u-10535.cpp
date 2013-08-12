#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN = 510 * 2;

struct Event{
    //sig -1 : left Event 
    //sig +1 : right Event
    int sig;
    int x;
    int y;
    int cross(int x1, int y1, int x2, int y2) const{  
	return x1 * y2 - x2 * y1;
    }

    int where(int x, int y)const{
	if(x == 0 && y == 0) return 0;
	if(x > 0 && y == 0) return 1;
	if(x > 0 && y > 0) return 2;
	if(x == 0 && y > 0) return 3;
	if(x < 0 && y > 0) return 4;
	if(x < 0 && y == 0) return 5;
	if(x < 0 && y < 0) return 6;
	if(x == 0 && y < 0) return 7;
	if(x > 0 && y < 0) return 8;
    }

    bool operator<(const Event & e) const{
	int w1 = where(x, y);
	int w2 = where(e.x, e.y);
	if(w1 < w2) return true;
	if(w1 > w2) return false;
	int c = cross(x, y, e.x, e.y);
	if(c > 0) return true;
	if(c < 0) return false;
	return sig < e.sig;
    }
};

int n;
int a[MAXN]; 
int b[MAXN]; 
int c[MAXN]; 
int d[MAXN];

int main(){
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;
	int x, y, ans = 0;
	for(int i = 0; i < n; i++){
	    scanf("%d%d%d%d",a+i, b+i, c+i, d+i);
	}
	scanf("%d%d", &x, &y);

	int begin = 0;
	vector<Event> ve;

	for(int i = 0; i < n; i++){
	    a[i] = a[i] - x;
	    b[i] = b[i] - y;
	    c[i] = c[i] - x;
	    d[i] = d[i] - y;
	    int cc = a[i] * d[i] - b[i] * c[i];

	    Event left, right;	
	    if(cc > 0){
		left.x = a[i], left.y = b[i];
		right.x = c[i], right.y = d[i];
		left.sig = -1, right.sig = 1;
		if(right < left){
		    begin++;
		}
	    }else if (cc <= 0){
		left.x = c[i], left.y = d[i];
		right.x = a[i], right.y = b[i];
		left.sig = -1, right.sig = 1;
		if(right < left){
		    begin++;
		}
	    }
	    ve.push_back(left);
	    ve.push_back(right);
	}

	ans = begin;
	sort(ve.begin(), ve.end());
	int size = ve.size();
	for(int i = 0; i < size; i++){
	    begin -= ve[i].sig;
	    if(begin > ans) ans = begin;
	}
	printf("%d\n", ans);
    }
    return 0;
}
