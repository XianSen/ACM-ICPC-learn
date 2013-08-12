#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using std::stack;

const int maxn = 61;
typedef unsigned long long ull;

int n = 1; 
ull f[maxn];
stack<int> start[3], end[3];

/*calc the power of 2*/
void init();

/*clean the stack*/
void clean();

int input(stack<int> start[]);

/*计算从把所有的东西都移动到一个a塔的代价*/
ull solve(int a);

int main(){
    init();
    while(scanf("%d", &n) == 1){
	if(n == 0) break;
	clean();
	input(start);
	input(end);

	ull ans = 0;
	for(int i = 0; i < n; i++){
	    int max = 0, val = -1;
	    for(int j = 0; j < 3; j++)
		if(!start[j].empty() && start[j].top() > val){
		    max = i;
		    val = start[j].top();
		}
	    if(end[max].top() == val)
		continue;
	    else{
		int dis = 0;
		for(int j = 0; j < 3; j++)
		    if(!end[j].empty() && end[j].top() == val)
			dis = j;

		start[max].pop();
		end[dis].pop();

		ans += solve(3 - dis - max);
	    }
	}

	printf("%lld\n", ans);
    }
    return 0;
}

void init(){
    f[0] = 1;
    for(int i = 0; i < maxn; i++)
	f[i] = f[i-1] * 2;
}

void clean(){
    for(int i = 0; i < 3; i++){
	while(!start[i].empty())
	    start[i].pop();
	while(!end[i].empty())
	    end[i].pop();
	}
}

ull solve(int dis){
    int done = 0, who = 0;  
    for(int i = 0; i < 3; i++)
	if(start[dis].empty())
	    done++;
    if(done == 3) return 0;
    if(done == 2){
	if(!start[dis].empty())
	    return 0;
	else{
	    for(int i = 0; i < 3; i++)
		if(!start[i].empty()){
		    who = i;
		    break;
		}
	    size_t size = start[who].size();
	    while(!start[who].empty()){
		start[dis].push(start[who].top());
		start[who].push();
	    }
	    return (f[size] - 1);
	    
	}
    }else{
	int max = 0, val = -1;	
	for(int i = 0; i < 3; i++)
	    if(!start[i].empty() && start[i].top > val){
		max = i;	
		val = start[i].top();
	    }
	//do something
    }
}

int input(stack<int> start[]){
    int val;
    for(int i = 0; i < n; i++){
	scanf("%d", &val);
	start[val].push(val);
    }
}
