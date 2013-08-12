#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int MAXN = 110000;

struct Event{
    //0代表左边事件，1代表右边事件
    int type;
    int time;
    bool operator<(const Event &e) const{
	return (time < e.time || time == e.time && type > e.type);
    }
};

int n, h, w;

int calc(int x, int a, int w, int &left, int &right){
    if(a == 0){
	if(x <= 0 || x >= w)
	    left = right + 1;
    }else if(a < 0){
	int right1 = -x * 2520 / a; 
	int left1 = (w - x)*2520/a;
	left = max(left1, left);
	right = min(right1, right);
    }else if (a > 0){
	int left1 = -x * 2520 / a; 
	int right1 = (w - x)*2520/a;
	left = max(left1, left);
	right = min(right1, right);
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
	scanf("%d%d%d", &w, &h, &n);
	vector<Event> ve;
	for(int i = 0; i < n; i++){
	    int x, y, a, b, left, right;
	    scanf("%d%d%d%d", &x, &y, &a, &b);

	    left = -2147483640;
	    right = -left;

	    calc(x, a, w, left, right);
	    calc(y, b, h, left, right);
	    if(left < right){
		ve.push_back((Event){0, left});
		ve.push_back((Event){1, right});
	    }
	}

	sort(ve.begin(), ve.end());

	int ans = 0;
	int now = 0;

	for(int i = 0; i < ve.size(); i++){
	    Event& e = ve[i];
	    if(e.type == 0){
		now++;
		if(now > ans) ans = now;
	    }else{
		now--;
	    }
	}

	printf("%d\n", ans);
    }
    return 0;
}
