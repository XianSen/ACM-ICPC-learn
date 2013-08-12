#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using std::sort;
using std::vector;

const int maxn = 1100;
int speed[maxn];

struct Pair{
    int a;
    int b;
};

int main(){
    int t, n, time, ok = 0;
    scanf("%d", &t);
    while(t--){
	if(ok) printf("\n");
	ok = 1;
	scanf("%d", &n);

	time = 0;
	for(int i = 0; i < n; i++)
	    scanf("%d", speed + i);
	sort(speed, speed + n);

	vector<Pair> history;

	int a = speed[0];
	int b = speed[1];

	while(n > 0){		
	    if(n <= 3){
		if(n == 1){
		    time += speed[0];
		    history.push_back((Pair){speed[0], -1});
		}else if (n == 2){
		    time += speed[1];
		    history.push_back((Pair){speed[0],speed[1]});
		}else if (n == 3){
		    time += speed[2] + speed[0] + speed[1];
		    history.push_back((Pair){speed[0],speed[2]});
		    history.push_back((Pair){speed[0],-1});
		    history.push_back((Pair){speed[0],speed[1]});
		}
		n = 0;
	    }else{
		int c = speed[n - 2];
		int d = speed[n - 1];
		if(2*b - a < c){
		    time += a + 2 * b + d;
		    history.push_back((Pair){a, b});
		    history.push_back((Pair){a, -1});
		    history.push_back((Pair){c, d});
		    history.push_back((Pair){b, -1});
		}else{
		    time += 2*a + c + d;
		    history.push_back((Pair){a, c});
		    history.push_back((Pair){a, -1});
		    history.push_back((Pair){a, d});
		    history.push_back((Pair){a, -1});
		}
		n -= 2;
	    }
	}

	printf("%d\n", time);

	for(int i = 0; i < history.size(); i++)
	    if(history[i].b != -1)
		printf("%d %d\n", history[i].a, history[i].b);
	    else
		printf("%d\n", history[i].a);
    }
    return 0;
}
