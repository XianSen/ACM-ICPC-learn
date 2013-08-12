#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using std::vector;

const char * s[] = {
    "1T","2T","3T","4T","5T","6T","7T","8T","9T",
    "1S","2S","3S","4S","5S","6S","7S","8S","9S",
    "1W","2W","3W","4W","5W","6W","7W","8W","9W",
    "DONG","NAN", "XI", "BEI", "ZHONG","FA","BAI"
};


int getId(const char * s1){
    for(int i = 0; i < 34; i++)
	if(strcmp(s[i], s1) == 0)
	    return i;
}

int get(){
    char s[10];
    scanf("%s",s);
    if(s[0] == '0') return -1;
    else return getId(s);
}

int val[34];
int tile[30];
int num[100];

//没有考虑好那个顺子
bool can(int num){
    if(num == 0){ 
	int test[34];
	for(int i = 0; i < 34; i++)
	    test[i] = val[i];

	for(int k = 0; k < 25; k++)
	    for(int i = 0; i < 6; i++){
		if((k % 9 <= 6) && test[k] >= 1 && 
		    test[k+1] >= 1 && test[k+2] >= 1) {
		    test[k] -= 1;
		    test[k+1] -= 1;
		    test[k+2] -= 1;
		}
	}

	for(int i = 0; i < 34; i++)
	    if(test[i] != 0) return false;

	return true;
    }else{
	for(int i = 0; i < 34; i++)
	    if(val[i] >= 3){
		val[i] -= 3;
		if(can(num - 1)) 
		    return true;
		val[i] += 3;
	    }
	return false;
    }
}

bool check(){
    for(int i = 0; i < 34; i++){
	memset(val, 0, sizeof(val));

	for(int j = 0; j < 14; j++)
	    val[tile[j]]++;

	if(val[i] >= 2){
	    val[i] -= 2;
	    for(int j = 0; j <= 4; j++)
		if(can(j)) return true;
	    val[i] += 2;
	}
    }
    return false;
}

int main(){
    for(int cas = 1;; cas++){
	memset(num, 0, sizeof(num));
	for(int i = 0; i < 13; i++){
	    int val;
	    if((val = get()) == -1) 
		return 0;
	    num[val]++;
	    tile[i] = val;
	}

	vector<int> ans;
	for(int i = 0; i < 34; i++)
	    if(num[i] < 4){
		tile[13] = i;
		if(check())
		    ans.push_back(i);
	    }
	
	if(ans.size() == 0)
	    printf("Case %d: Not ready\n", cas);
	else{
	    printf("Case %d:", cas);
	    for(int i = 0; i < ans.size(); i++)
		    printf(" %s", s[ans[i]]);
	    printf("\n");
	}
    }
    return 0;
}
