#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

const int MAXN = 1001;
const int MAXM = 2000;

int now;
int vist[MAXN][MAXN];
int father[MAXN][MAXN];

using namespace std;

inline int encode(int a, int b, int t){
    return (((a * MAXM + b) << 3) + t);
}

inline void decode(int &a, int &b, int &c, int value){
    c = value % 8;
    value = value >> 3;
    a = value / MAXM;
    b = value % MAXM;
}

void add(int a, int b, int c, int fa, queue<int>& que){
    if(vist[a][b] != now){
//    printf("%d %d\n", a, b);
	vist[a][b] = now;
	int status = encode(a, b, c);
	que.push(status);
	father[a][b] = fa;
    }
}

const char * action[] = {"0", "empty A", "empty B", 
    "fill A", "fill B", 
    "pour A B", "pour B A"};

void getfather(int status){
    int a, b, c; 
    decode(a, b, c, status);
    if(c != 0){
	getfather(father[a][b]);
	printf("%s\n", action[c]);
    }
}

void bfs(int A, int B, int n){
    now++;
    queue<int> que;
    add(0, 0, 0, encode(0,0,0), que);
    while(!que.empty()){
	int status = que.front();
	que.pop();
	int a, b, c;
	decode(a, b, c, status);

	if(a == n || b == n){
	    getfather(status);
	    printf("success\n");
	    return ;
	}

	//六种可能
	//Case 1: 把A倒了 0, b 1
	add(0, b, 1, status, que);
	//Case 2: 把B倒了 a, 0, 2
	add(a, 0, 2, status, que);
	//Case 3: 把A倒满 A, b, 3
	add(A, b, 3, status, que);
	//Case 4: 把B倒满
	add(a, B, 4, status, que);
	//Case 5: A 倒给 B
	int sum = a + b;
	int b1 = min(B, a + b);	
	add(sum - b1, min(B, a + b), 5, status, que);

	//Case 6: B 倒给 A
	b1 = min(A, a+b);
	add(min(A, a + b), sum - b1, 6, status, que);
    }
}

int main(){
    int a, b, n;

    now = 0;
    memset(vist, 0, sizeof(vist));

    while(scanf("%d%d%d", &a, &b, &n) != EOF){
	bfs(a, b, n);
    }
    return 0;
}
