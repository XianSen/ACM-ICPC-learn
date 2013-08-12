#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char get(){
    char c = getchar();
    while(!isupper(c) && c != '.')
	c = getchar();
    return c;
}
 
int n;
const int maxn = 11;

const int dx[] = {0, 0, +1, -1};
const int dy[] = {+1, -1, 0, 0};

char mat[maxn][maxn];

void input(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)	
	for(int j = 0; j < n; j++)
		mat[i][j] = get();
}

void output(){
    for(int i = 0; i < n; i++){
	for(int j = 0; j < n; j++)
	    printf("%c", mat[i][j]);
	printf("\n");
    }
}

bool check(int x, int y, char c){
    for(int i = 0; i < 4; i++){
	int u = x + dx[i];
	int v = y + dy[i];
	if(u >= 0 && u < n)
	    if(v >= 0 && v < n)
		if(mat[u][v] == c)
		    return false;
    }
    return true;
}

int solve(int x, int y){
    if(y == n && x == n - 1){
	output();
	return true;
    }
    if(y == n){
	x++;
	y = 0;
    }
    if(mat[x][y] != '.')
	solve(x, y + 1);
    else{
	for(int c = 'A'; c <= 'z'; c++)
	    if(check(x, y, c)){
		mat[x][y] = c;
		if(solve(x, y + 1))
		    return true;
		mat[x][y] = '.';
	    }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++){
	printf("Case %d:\n", cas);
	input();
	solve(0, 0);
    }
    return 0;
}
