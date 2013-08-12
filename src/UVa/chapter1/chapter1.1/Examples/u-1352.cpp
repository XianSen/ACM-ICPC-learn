#include <map>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using std::cin;
using std::map;
using std::string;

int dice24[24][6] = {
	{3, 1, 0, 5, 4, 2}, {3, 5, 1, 4, 0, 2}, {3, 4, 5, 0, 1, 2}, 
	{3, 0, 4, 1, 5, 2}, {4, 3, 0, 5, 2, 1}, {0, 3, 1, 4, 2, 5}, 
	{1, 3, 5, 0, 2, 4}, {5, 3, 4, 1, 2, 0}, {0, 1, 2, 3, 4, 5}, 
	{1, 5, 2, 3, 0, 4}, {5, 4, 2, 3, 1, 0}, {4, 0, 2, 3, 5, 1}, 
	{5, 1, 3, 2, 4, 0}, {4, 5, 3, 2, 0, 1}, {0, 4, 3, 2, 1, 5}, 
	{1, 0, 3, 2, 5, 4}, {1, 2, 0, 5, 3, 4}, {5, 2, 1, 4, 3, 0}, 
	{4, 2, 5, 0, 3, 1}, {0, 2, 4, 1, 3, 5}, {2, 4, 0, 5, 1, 3}, 
	{2, 0, 1, 4, 5, 3}, {2, 1, 5, 0, 4, 3}, {2, 5, 4, 1, 0, 3}};
    
const int maxn = 4;
int n, ans;
int order[maxn];
int color[maxn][6];
int status[maxn][6];
map<string, int> msi;

int sum;
int ID(string color){
    if(msi.find(color) == msi.end())
	msi[color] = sum++;
    return msi[color];
}

void check(){
    /*
    for(int i = 0; i < n; i++)
	printf("%d ", order[i]);
    printf("\n");
    */

    for(int i = 0; i < n; i++)
	for(int j = 0; j < 6; j++)
	    status[i][j] = color[i][dice24[ order[i] ][j]];

    int now = 0;
    for(int i = 0; i < 6; i++){
	int col[sum];
	memset(col, 0, sizeof(col));
	for(int j = 0; j < n; j++)
	    col[status[j][i]]++;
	int  max = 0;
	for(int j = 0; j < sum; j++)
	    if(col[j] > max) max = col[j];
	now += n - max;
   }
    if(now < ans) ans = now;
}

void dfs(int now){
    if(now == n) 
	check();
    else{
	for(int i = 0; i < 24; i++){
	    order[now] = i;
	    dfs(now + 1);
	}
    }
}

int main(){
    while(scanf("%d", &n) != EOF && n){ 
	int sum = 0;
	msi.clear();
	for(int i = 0; i < n; i++)
	    for(int j = 0; j < 6; j++){
		string s;
		cin >> s;
		color[i][j] = ID(s);
	    }
	ans = n * 6;
	order[0] = 0;
	dfs(1);
	printf("%d\n", ans);
    }
    return 0;
}
