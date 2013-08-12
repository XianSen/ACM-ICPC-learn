#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 110000;
const int maxm = 1100000;

struct Gate{
    int x;
    int y;
};

double time[maxn];
int speed[maxm];
Gate gate[maxn];

bool check(int speed, double a[]);
void getTime(int speed, double a[]);

int i, j, cas, w, vh, n, s;


int main(){
    scanf("%d", &cas);
    while(cas--){
	scanf("%d%d%d", &w, &vh, &n);
	for(i = 0; i < n; i++)
	    scanf("%d%d", &gate[i].x, &gate[i].y);

	scanf("%d", &s);
	speed[0] = 0; 
	for(i = 1; i <= s; i++)
	    scanf("%d", speed+i);

	sort(speed, speed+s+1);

	int left = 0, right = s;		

	while(left < right){
	    int mid = (left + right) / 2; 
	    if(check(speed[mid], time)) left = mid + 1;
	    else right = mid - 1;
	}

	while(left > 0 && !check(speed[left], time))
	    left--;

	if(speed[left] == 0)
	    printf("IMPOSSIBLE\n");
	else
	    printf("%d\n", speed[left]);
    }
    return 0;
}

void getTime(int speed, double time[]){
    for(int i = 1; i < n; i++)
	time[i] = gate[i].y - gate[i-1].y;
}

bool check(int speed, double time[]){
    int i;
    double leftmost = gate[0].x;
    double rightmost = gate[0].x + w;
    

    if(speed == 0) return true;

    getTime(speed, time);

    for(i = 1; i < n; i++){
	double dis = time[i] / speed;
	leftmost -= vh * 1.0 * dis;
	rightmost += vh * 1.0 * dis;

	leftmost = max<double>(leftmost,gate[i].x);
	rightmost= min<double>(rightmost,gate[i].x+w);

	if(leftmost > rightmost) return false;
    }
    return true;
}
