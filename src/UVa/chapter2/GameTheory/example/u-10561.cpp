#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN = 210;
int value[MAXN];

int sg(int n){
    if(value[n] != -1) return value[n];
    int vist[MAXN];
    memset(vist, 0, sizeof(vist));
    for(int i = 1; i <= n; i++){
	int left = i - 2 - 1;
	int right = n - i - 2;
	if(left < 0) left = 0;
	if(right < 0) right = 0;
	vist[value[left] ^ value[right]] = 1;
    }

    for(int i = 0; i <= n; i++)
	if(!vist[i]){
	    value[n] = i;
	    break;
	}

    return value[n];
}

void init(){
    memset(value, -1, sizeof(value));
    value[0] = 0;
    value[1] = 1;
    int n = 201;
    for(int i = 2; i <= n; i++)
	value[i] = sg(i);
}

char s[MAXN];

bool check(const char *s, int n){
    for(int i = 2; i < n; i++)
	if(s[i] == 'X' && s[i - 1] == 'X' && s[i - 2] == 'X')
	    return true;
    return false;
}

//在s状态是不是N状态
bool win(const char * s, int n){
    if(check(s, n)) return false;
    int status = 0;
    int len = 0;
    for(int i = 0; i < n; i++)
	if(s[i] == 'X'){
	    len = len - 4;
	    if(len < 0) len = 0;
	    status ^= value[len];
	    len = 0;
	}else{
	    len++;
	}
    return status != 0 ? true: false;
}

int main(){
    init();
    int tt;
    scanf("%d", &tt);
    getchar();

    while(tt--){
	s[0] = 'X';
	s[1] = s[2] = '.';
	gets(s + 3);
	vector<int> ans;

	int n = strlen(s);

	for(int i = 3; i < n; i++)
	    if(s[i] == '.'){
		s[i] = 'X';
		if(check(s, n))
		    ans.push_back(i - 2);
		s[i] = '.';
	    }

	s[n] = s[n + 1] = '.';
	s[n + 2] = 'X';

	n = n + 3;
	if(ans.size() == 0)
	    for(int i = 3; i < n - 3; i++)
		if(s[i] == '.'){
		    int sum = 0;
		    s[i] = 'X';
		    if(check(s, n)){
			s[i] = '.';
			//  ans.push_back(i - 2);
		    continue;
		}
		s[i] = '.'; 

		if(i >= 2 && s[i - 2] == 'X') sum++;
		if(i >= 1 && s[i - 1] == 'X') sum++;
		if(i + 1 < n && s[i + 1] == 'X') sum++;
		if(i + 2 < n && s[i + 2] == 'X') sum++;

		if(sum != 0) continue;
		s[i] = 'X';
		if(!win(s, n))
		    ans.push_back(i - 2);
		s[i] = '.';
	    }

	sort(ans.begin(), ans.end());
	int size = ans.size();
	puts(size == 0 ? "LOSING" : "WINNING");
	for(int i = 0; i < size; i++)
	    if(i == 0) printf("%d", ans[i]);
	    else printf(" %d", ans[i]);
	printf("\n");
    }
    return 0;
}
