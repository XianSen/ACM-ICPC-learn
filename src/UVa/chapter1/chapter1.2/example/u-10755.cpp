#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <iostream>

#define FOR(a, b, c) for(int a = (b); a <= (c); a++)
#define FORALL FOR(x,1,a) FOR(y,1,b) FOR(z,1,c)

using namespace std;
typedef long long LL;
const int MAXN = 30;
LL mat[MAXN][MAXN][MAXN];

LL getLongNum(){
    char c = getchar();
    while(!isdigit(c) && c != '-')
	c = getchar();
    if(c == '-') return -getLongNum();

    LL num = 0;
    while(isdigit(c)){ 
	num = num * 10 + c - '0';
	c = getchar();
    }
    return num;
}

int main(){
    LL t;
    cin >> t;
    while(t--){
	int a, b, c; 
	LL max, val;
        max = -(1LL << 60);
	memset(mat, 0, sizeof(mat));

	cin >> a >> b >> c;
	FORALL{
	    val = getLongNum();
	    mat[x][y][z] = val;
	    if(val > max) max = val;
	}

	LL ans = max;
	if(max > 0){
	    FORALL{ 
		mat[x][y][z] += mat[x - 1][y][z];
	    }

	    FORALL{
		mat[x][y][z] += mat[x][y - 1][z];
	    }

	    FOR(x1, 1, a) FOR(x2,x1,a) FOR(y1,1,b) FOR(y2,y1,b){
		val = 0;
		FOR(z,1,c){
		    LL nval = mat[x2][y2][z] + mat[x1-1][y1-1][z]
			   -mat[x1-1][y2][z] - mat[x2][y1-1][z];
		    val += nval;
		    if(val < 0) val = 0;
		    if(val > ans) ans = val;
		}
	    }
	}

	cout << ans << endl;
	if(t) printf("\n");
    }
    return 0;
}
