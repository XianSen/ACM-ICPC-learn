#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 1001;
char s[MAXN];

double calc(int begin, int end){
    double ans = 0;
    //去掉空白字符
    while(begin <= end && s[begin] == ' ') begin++;
    while(begin <= end && s[end] == ' ') end--;

    //判断类型
    int type = 0;
    for(int i = begin; i <= end; i++)
	if(s[i] == '(') {
	    type = 1;
	    break;
	}
    if(type){
	double p;
	sscanf(s + begin, "(%lf", &p);
	double x, y;
	for(int i = begin + 1; i <= end; i++)
	    if(s[i] == ' '){
		int j = i + 1;
		while(s[j] == ' ') j++;
		if(s[j] == '('){
		    int first = j;
		    //找到匹配的)
		    int now = 1;
		    while(now){
			j++;
			if(s[j] == '(') now++;
			else if(s[j] == ')') now--;
		    }
		    x = calc(first, j);
		    y = calc(j + 1, end - 1);
		}else{
		    int first = j;
		    while(s[j] != ' ') j++;
		    x = calc(first, j - 1);
		    y = calc(j + 1, end - 1);
		}
		break;
	    }
	ans = p * (x + y) + (1 - p) * (x - y);
    }else{
	sscanf(s + begin, "%lf", &ans);
    }
    return ans;
}

int main(){
    while(gets(s) != NULL){
	if(strcmp(s, "()") == 0) break;
	int begin = 0;
	int end = strlen(s) - 1;
	printf("%0.2lf\n", calc(begin, end));
    }
    return 0;
}
