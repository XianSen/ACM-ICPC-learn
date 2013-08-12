//UVa1330-City Game

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
const int MAXN = 1100;
int mat[MAXN][MAXN];

int getC(){
    char c = getchar();
    while(c != 'R' && c != 'F')
	c = getchar();
    return (c == 'F');
}

int n, m;
int up[MAXN];
int left[MAXN];
int right[MAXN];

//求n,m的矩阵的最大子矩阵
int getMaxMatrix(){
    memset(up, 0, sizeof(up));
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));

    int ans = 0;
    for(int i = 1; i <= n; i++){
	int leftmost = 0;
	for(int j = 1; j <= m; j++)
	    if(!mat[i][j]){
		leftmost = left[j] = up[j] = right[j] = 0;
	    }else{
		leftmost += 1;		
		up[j] += 1;
		if(up[j] != 1)
		    left[j] = min(left[j], leftmost);
		else
		    left[j] = leftmost;
	    }
	int rightmost = 0;
	for(int j = m; j > 0; j--)
	    if(!mat[i][j]){
		rightmost = 0;
	    }else{
		rightmost += 1;
		if(up[j] != 1)
		    right[j] = min(right[j], rightmost);
		else
		    right[j] = rightmost;
		ans = max(ans, up[j]*(left[j] + right[j] - 1));
	    }
    }
    return ans; 
}

int main(){
    int k;
    scanf("%d", &k);
    while(k--){
	scanf("%d%d", &n, &m);
	memset(mat, 0, sizeof(mat));
	for(int i = 1; i <= n; i++)
	    for(int j = 1; j <= m; j++)
		mat[i][j] = getC();
	int ans = getMaxMatrix();
	printf("%d\n", ans * 3);
    }
    return 0;
}
