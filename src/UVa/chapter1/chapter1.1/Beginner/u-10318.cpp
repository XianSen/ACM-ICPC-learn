#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int getC();

int row, col, ans;

const int maxn = 10;
const int maxm = 3;

const int dx[] = {-1, -1, -1, -0, +0, -0, +1, +1, +1};
const int dy[] = {-1, +0, +1, -1, +0, +1, -1, +0, +1};

int que[maxn*maxn];
int used[maxn][maxn];
int patten[maxm][maxm];
int matrix[maxn][maxn];

/*对x行进行检查*/
bool checkRow(int x){
    for(int i = 0; i < col; i++)
	if(!matrix[x][i])
	    return false;
    return true;
}

/*对所有的行列进行检查*/
bool checkAll(){
    for(int i = 0; i < row; i++)
	if(!checkRow(i))
	    return false;
    return true;
}

/*改变(x,y)的状态对周围的影响*/
bool light(int x, int y){
    int nr = sizeof(dx);
    int change = false;
    used[x][y] ^= 1;
    for(int i = 0; i < nr; i++){
	int u = x + dx[i];
	int v = y + dy[i];
	if(u < 0 || u >= row) continue;
	if(v < 0 || v >= col) continue;
	if(patten[1 + dx[i]][1 + dy[i]]){
	    change = true;
	    matrix[u][v] ^= 1;
	}
    }
    return change;
}

/*对(x,y)进行搜索, 现在按了count 次*/
void dfs(int x,  int y, int count){
    //step1 count < ans
    if(count >= ans) return ;

    //step 2 坐标的调整
    if(y == col){
	x += 1;
	y = 0;
    }

    //x = row, y = col
    if(x == row){  
	if(checkAll()){
	    ans = 0;
	    for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
		    if(used[i][j])
			que[ans++] = i * col + j;
	}
   }else{
       if(light(x, y)){
	    if(x - 2 < 0 || checkRow(x-2))
		dfs(x, y+1, count+1);
	    light(x, y);
	}

	if(x - 2 < 0 || checkRow(x-2))
	    dfs(x, y+1, count);
    }
}

int main(){
    int cas = 0;
    while(scanf("%d%d", &row, &col) == 2){
	if(row == 0 && col == 0) break;
	for(int i = 0; i < 3; i++)
	    for(int j = 0; j < 3; j++)
		patten[i][j] = getC();

        //init
	ans = row * col + 1;
	memset(used, false, sizeof(used));
	memset(matrix, 0, sizeof(matrix));

	dfs(0, 0, 0);

	printf("Case #%d\n", ++cas);

	if(ans == row * col + 1)
	    printf("Impossible.\n");
	else{
	    for(int i = 0; i < ans; i++)
		if(i == ans - 1) printf("%d\n", que[i] + 1);
		else printf("%d ", que[i] + 1);
	}
    }
    return 0;
}

/*读入. 和　＊　*/
int getC(){
    char c = getchar();
    while(c != '.' && c != '*')
	c = getchar();
    return (c == '*');
}
