#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using std::swap;

const int maxn = 30;
int patten[3][3];
int row, col, cas = 1;      
int matrix[maxn][maxn];

const int dx[] = {-1,-1,-1,+0,+0,+0,+1,+1,+1};
const int dy[] = {-1,+0,+1,-1,+0,+1,-1,+0,+1};
const int dz[] = {+2,+2,+2,+1,+1,+1,+0,+0,+0};
const int dk[] = {+2,+1,+0,+2,+1,+0,+2,+1,+0};

/*读入.和* */
int getC(){
    char c = getchar();
    while( c != '.' && c != '*')
	c = getchar();
    return (c == '*');
}

/*得到x, y的编号*/
inline int ID(int x, int y){
    return x * col + y;
}

/*得到系数*/
int getMatrix(){
    memset(matrix, 0, sizeof(matrix));
    for(int i = 0; i < row; i++)
	for(int j = 0; j < col; j++)
	    for(int k = 0; k < 9; k++){
		int u = i + dx[k];
		int v = j + dy[k];
		if(u < 0 || u > row) continue;
		if(v < 0 || v > col) continue;
		if(patten[dz[k]][dk[k]])
		    matrix[ID(i, j)][ID(u,v)] = 1;
	    }
}

int swap_row(int u, int v, int n){
    for(int i = 0; i < n; i++)
	swap(matrix[u][i], matrix[v][i]);
}

/*这是个失败的做法,编码很长*/
int gauss(int n, int matrix[][maxn]){
    int i = 0;  
    int j = 0;
    while(i < n && j < n){
	int maxi = i;
	for(int k = i ; k <  n; k++)
	    if(matrix[k][j] != 0){
		maxi = k;
		break;
	    }
	if(matrix[maxi][j] != 0){
	    swap_row(i, maxi, n);
	    for(int u = i + 1; u < n; u++)
		for(int v = 0; v < n; v++)
		    matrix[u][v] ^= matrix[i][v];
	    i = i + 1;
	}
	j = j + 1;
    }
//do something

}

int dfs(int x, int y){
}

int main(){
    while(scanf("%d%d", &row, &col) != EOF && row && col){
	scanf("%d%d", &row, &col);
	for(int i = 0; i < 3; i++)
	    for(int j = 0; j < 3; j++)
		patten[i][j] = getC();
	getMatrix();
	int ans = row * col + 1;
	dfs(0, 0);
	printf("Case #%d\n", cas++);
    }
    return 0;
}
