#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 1010;
typedef int LL;
using std::set;

set<LL> win;
set<LL> lose;

LL encode(int &a, int &b, int &c){
    LL result = 0;
    result = (c * 1001 + b) * 1001 + a;
    return result;
}

void decode(LL& result, int  &a, int &b, int &c){
    a = result % 1001;
    result = result / 1001;

    b = result % 1001;
    result = result / 1001;

    c = result % 1001;
    result = result / 1001;
}

inline bool check(int b, int c){
    int result = (b * 2 + c) % 3;
    if(result == 0) return true;
    else return false;
}

char s[MAXN];

int play(int a, int b, int c){
    LL key = encode(a, b, c);

    if(win.count(key) != 0) return 1;
    if(lose.count(key) != 0) return 0;

    if(a != 0 && check(b, c) && !play(a - 1, b, c)){ 
	win.insert(encode(a, b, c));
	return 1;
    }

    if(b != 0 && check(b - 1, c) && !play(a, b - 1, c)){ 
	win.insert(encode(a, b, c));
	return 1;
    }

    if(c != 0 && check(b, c - 1) && !play(a, b, c - 1)){ 
	win.insert(encode(a, b, c));
	return 1;
    }

    lose.insert(encode(a, b, c));
    return 0;
}

int main(){
    int n, kcase = 0;
    scanf("%d", &n);
    getchar();
    while(gets(s) != NULL){
	int len = strlen(s);
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < len; i++){
	    if((s[i] - '0') % 3 == 0){
		a++; 
	    }else if((s[i] - '0') % 3 == 1){
		b++;
	    }else if((s[i] - '0') % 3 == 2){
		c++;
	    }
	}

	int ans = play(a, b, c);

	printf("Case %d: ", ++kcase);
	if(ans == 1) printf("S\n");
	else printf("T\n");
    }
    return 0;
}
