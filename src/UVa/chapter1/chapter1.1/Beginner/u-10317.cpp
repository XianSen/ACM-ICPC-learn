#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using std::sort;
using std::swap;
using std::vector;

const int maxm = 100;
const int maxn = 8000;

int sum, n, sumAdd;
char s[maxn];
bool used[maxm];
vector<int> vi;
vector<int> num;

int getNum();

bool dfs(int cur, int sumAdd,  int curSum, int curNoSum){
    if(curSum  == sum && sumAdd == 0){
	return true;
    }

    if(curNoSum > sum) return false;

    if(cur == n) return false;

    used[cur] = true;
    if(dfs(cur + 1, sumAdd - 1, curSum + num[cur], curNoSum))        
	return true;
    used[cur] = false;

    if(dfs(cur + 1, sumAdd, curSum, curNoSum + num[cur]))        
	return true;
    return false;
}

int main(){
    while(gets(s) != NULL){
	if(strlen(s) == 0) break;
	vi.clear();
	num.clear();
	getNum();
	sort(num.begin(), num.end());

	sumAdd = sum = 0;
	n = num.size();
	for(int i = 0; i < n; i++)
	    sum += num[i];

	int opera = +1;
	for(int i = 0; i < n - 1; i++)
	    if(vi[i] == 0){
		opera = -1;	
	    }else{
		sumAdd += (vi[i] == opera);
	    }

	sumAdd++;
	if(sum % 2 != 0){	
	    printf("no solution\n");
	}else{
	    sum = sum / 2;
	    memset(used, false, sizeof(used));
	    if(!dfs(0, sumAdd, 0, 0))
		printf("no solution\n");
	    else{
		vector<int> first, second;	
		for(int i = 0; i < n; i++){
		    if(used[i]) first.push_back(num[i]);
		    else second.push_back(num[i]);
		}

		vector<int>::iterator now = first.begin();
		vector<int>::iterator last = second.begin();

		printf("%d",*now++);
		for(int i = 0; i < n - 1; i++)
		    if(vi[i] == 1){
			printf(" + %d", *now++);
		    }else if(vi[i] == -1){
			printf(" - %d", *last++);
		    }else if(vi[i] == 0){
			swap(now, last);
			printf(" = %d",*now++);
		    }
		printf("\n");
	    }
	}
    }
    return 0;
}

int getOneNum(char * &s){
    while(!isdigit(*s))
	s++;
    int cost = 0;
    while(isdigit(*s)){
	cost = cost * 10 + (*s) - '0';
	s++;
    }
    return cost;
}

int getOpera(char * &s){
    while((*s) != '+'  && (*s) != '-'  && (*s) != '=')
	s++;
    if((*s) == '+') return +1;
    if((*s) == '-') return -1;
    if((*s) == '=') return 0;
    s++;
}

int getNum(){
    int turn = 1;
    char* s1 = s;

    while((*s1) == ' ') s1++;
    while((*s1) != 0){
	if(turn){
	    num.push_back(getOneNum(s1));
	}else{
	    vi.push_back(getOpera(s1));  
	}
	while((*s1) == ' ') s1++;
	turn = 1 - turn;
    }
    return 0;
}
