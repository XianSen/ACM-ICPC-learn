#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define REP(i,n) for(int i = 0; i < (n); i++)

const int maxn = 11;

char get(){
    char c = getchar();
    while(!isalpha(c) && c != '.')
	c = getchar();
    return c;
}

int n;
char pos[maxn][maxn][maxn];
char view[6][maxn][maxn];

void change(int k, int i, int j, int len, int &x, int &y, int &z){
    if(k == 0){ x = len; y = j; z = i;}
    if(k == 1){ x = n - 1 - j; y = len; z = i;}
    if(k == 2){ x = n - 1 - len; y = n - 1 - j; z = i;}
    if(k == 3){ x = j; y = n - 1 - len; z = i;}
    if(k == 4){ x = n - 1 - i; y = j; z = len;}
    if(k == 5){ x = i; y = j; z = n - 1 - len;}
}


int work(){
    REP(i,n) REP(k,6) REP(j,n) view[k][i][j] = get();
    REP(i,n) REP(j,n) REP(k,n) pos[i][j][k] = '#';
    REP(k,6) REP(i, n) REP(j,n) 	
	if(view[k][i][j] == '.') REP(p, n){
	    int x, y, z;
	    change(k, i, j, p, x, y, z);
	    pos[x][y][z] = '.';
	}

    int done;
    for(;;){
	done = true;
	REP(k,6) REP(i,n) REP(j,n){
	    if(view[k][i][j] != '.') REP(p, n){
		int x, y, z;
		change(k, i, j, p, x, y, z);
		if(pos[x][y][z] == '.') continue;
		if(pos[x][y][z] == '#'){
		    pos[x][y][z] = view[k][i][j];  
		    break;
		}
		
		if(pos[x][y][z] == view[k][i][j]) break;

		pos[x][y][z] = '.';
		done = false;	
	    }
	}
	if(done) break;
    }
    return 0;
}

int main(){
    while(scanf("%d", &n) != EOF){
	if(n == 0) break;	
	work();
	int ans = 0;
	REP(k,n) REP(i,n) REP(j,n) 
	    if(pos[k][i][j] != '.')
		ans ++;
	printf("Maximum weight: %d gram(s)\n", ans);
	    
    }
    return 0;
}
