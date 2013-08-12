#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using std::sort;

const int maxn = 200;
int num1[30];
int num2[30];
char s1[maxn];
char s2[maxn];

bool check(){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len1 != len2) return false;
    memset(num1, 0, sizeof(num1));
    memset(num2, 0, sizeof(num2));
    for(int i = 0; i < len1; i++)
	num1[s1[i] - 'A']++;
    for(int i = 0; i < len2; i++)
	num2[s2[i] - 'A']++;
    sort(num1, num1+30);
    sort(num2, num2+30);
    for(int i = 0; i < 30; i++)
	if(num1[i] != num2[i]) return false;
    return true;
}

int main(){
    while(scanf("%s%s", s1, s2) != EOF){
	if(check()) printf("YES\n");
	else printf("NO\n");
    }
    return 0;
}
