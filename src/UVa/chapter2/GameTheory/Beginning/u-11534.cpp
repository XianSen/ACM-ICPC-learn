#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int MAXN = 200;

int sg[4][MAXN];

int mex(vector<int> & sg){
    if(sg.empty()) return 0;
    sort(sg.begin(), sg.end());
    if(sg[0] != 0) return 0;
    int size = sg.size();
    for(int i = 1; i < size; i++)
	if(sg[i] > sg[i - 1] + 1)
	    return sg[i - 1] + 1;
    return sg[size - 1] + 1;
}

//type 0 _______
//type 1 x______
//type 2 x_____x
//type 3 x_____o
int f(int type, int n){
    if(sg[type][n] != -1) 
	return sg[type][n];

    int & ans = sg[type][n];

    if(n == 0){
	ans = 0;
	return ans;
    }

    vector<int> result;
    if(type == 0){
	for(int i = 1; i <= n; i++)
	    result.push_back(f(1, i - 1) ^ f(1, n - i));
    }else if(type == 1){
	//x___
	for(int i = 1; i <= n; i++)
	    for(int j = 0; j < 2; j++)
		if(!(i == 1 && j == 1)){
		    if(j) result.push_back(f(2, i - 1) ^ f(1, n - i));
		    else result.push_back(f(3, i - 1) ^ f(1, n - i));
		}
    }else if(type == 2){
	//x--x
	for(int i = 1; i <= n; i++)
	    for(int j = 0; j < 2; j++)
		if(!(i == 1 && j == 1 || i == n && j == 1)){
		    if(j) result.push_back(f(2, i - 1) ^ f(2, n - i));
		    else result.push_back(f(3, i - 1) ^ f(3, n - i));
		}
    }else if(type == 3){
	//x--o
	for(int i = 1; i <= n; i++)
	    for(int j = 0; j < 2; j++)
		if(!(i == 1 && j == 1 || i == n && j == 0)){
		    if(j) result.push_back(f(2, i - 1) ^ f(3, n - i));
		    else result.push_back(f(3, i - 1) ^ f(2, n - i));
		}
    }

    ans = mex(result);
    return ans;
}

void init(){
    memset(sg, -1, sizeof(sg));
    for(int i = 1; i <= 100; i++)
	for(int j = 0; j < 4; j++)
	    f(j, i);
}

//1代表先手必胜
int win(char * s){
    int n = strlen(s);
    /*
    //先判断自己是不是胜了
    for(int i = 1; i < n; i++)
	if(s[i] == s[i - 1] && s[i] != '.')
	    return 1;
	    */

    int ans = 0;
    for(int i = 0; i < n; i++){
	int left, right, flag;

	flag = 0;
	for(left = i; left < n; left++)
	    if(s[left] == '.') {
		flag = 1;
		break;
	    }

	if(!flag) break;

	/*
	//..o..x..会有BUG
	for(right = left; right < n; right++)
	    if(s[right] != '.' || right == n - 1){
		i = right + 1;
		if(s[right] != '.')
		    right = right - 1;
		break;
	    }
	    */

	for(right = left; right < n; right++)
	    if(s[right] != '.' || right == n - 1){
		i = right;
		if(s[right] != '.')
		    right = right - 1;
		break;
	    }
//printf("%d %d\n", left, right);
	if(left == 0 && right == n - 1){
	    ans ^= f(0, right - left + 1);
	}else if(left == 0 || right == n - 1){
	    ans ^= f(1, right - left + 1);
	}else if(s[left - 1] == s[right + 1]){
	    ans ^= f(2, right - left + 1);
	}else{
	    ans ^= f(3, right - left + 1);
	}
    }

    return (ans == 0 ? 0 : 1);
}

char s[MAXN];

int main(){
    init();
    int tt = 0;

    scanf("%d", &tt);
    getchar();

    while(tt--){
	gets(s);

	int status = win(s);
	int n = strlen(s), sum = 0;

	for(int i = 0; i < n; i++)
	    if(s[i] != '.')
		sum ++;
	
	if(sum % 2 == 1) status = 1 - status;

	puts(status == 0 ? "Impossible." :"Possible.");
    }
    return 0;
}
