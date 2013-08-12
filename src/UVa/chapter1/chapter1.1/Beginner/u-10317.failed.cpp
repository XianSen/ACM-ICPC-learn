#include <map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using std::map;
using std::vecotr;

const int maxm = 100;
const int maxn = 2800;

typedef map<int,int> MII;
typedef map<int,int>::iterator Point;

int a, b, sum;
char s[maxn];
int num[maxm];

/*
 * 把s数据中的数字存入num中，
 * 并计算等号两部分间有多少个数
 */
void getNum(int &a, int &b, int num[]);

/*
 *运用dp计算在x,y在等式两边时，
 *是否有解,若有解则输出解
 */
bool check(int x, int y);

int main(){
    while(scanf("%s", s) == 1){
	if(strlen(s) == 0) break;
	getNum(a, b, num);

	sum = 0;
	for(int i = 0; i < a + b; i++)
	    sum += num[i];

	bool done = false;
	for(int i = 0; i < a + b && !done; i++)
	    for(int j = i + 1; j < a + b && !done; j++){
		done = check(i, j);
	    }

	if(!done)
	    printf("no solution\n");
    }
    return 0;
}

void getNum(int &a, int &b, int num[]){
    a = 2;     
    b = 4;
    num[0] = 1;
    num[1] = 2;
    num[2] = 4;
    num[3] = 5;
    num[4] = 6;
}

bool check(int x, int y){
    int zero = maxn / 2;
    int begin = 2147483647;
    
    MII mii[maxm];  
    mii[0][num[x] - num[y]] = begin;
    mii[0][num[y] - num[x]] = begin;

    int now = 0;
    for(int i = 0; i < a + b; i++){
	if(i == x || i == y) continue;
	now++;
	Point it = mii[now - 1].begin();
	Point end = mii[now - 1].end();
	for(;it != end; it++){	
	    mii[it->first + num[i]] = i + 1;  
	    mii[it->first - num[i]] = -(i + 1);  
	}
    }
}
