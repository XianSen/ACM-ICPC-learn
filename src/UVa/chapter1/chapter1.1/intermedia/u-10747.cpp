#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using std::sort;
using std::vector;

int n, k;
const int maxn = 11000;

int zero = 0;
int match[maxn];

struct CMP{
    bool operator()(const int &a, const int &b)const{
	if(abs(a) > abs(b)) return true;
	if(abs(a) < abs(b)) return false;
	return a > b;
    }
};

struct CMP1{
    bool operator()(const int &a, const int &b)const{
	if(abs(a) > abs(b)) return true;
	if(abs(a) < abs(b)) return false;
	return a < b;
    }
};

inline int getFloorEven(int n){
    if(n % 2 == 0) return n;
    else return n  - 1;
}

int main(){
    int ans = 0;
    int cas = 0;
    while(scanf("%d%d", &n, &k) == 2){
	if(n == 0 && k == 0) break;

	zero = 0;
	cas++;
	vector<int> postive;
	vector<int> negative;

	int max = -2147483647;
	for(int i = 0; i < n; i++){
	    int val;
	    scanf("%d", &val);
	    if(val > 0) postive.push_back(val);
	    else if (val < 0) negative.push_back(val);
	    else zero++;
	    if(val > max) max = val;
	}

	sort(postive.begin(), postive.end(), CMP());
	sort(negative.begin(), negative.end(), CMP());

	int pNum = postive.size();
	int nNum = negative.size();

	int first = false;
	if(zero == 0 && pNum + getFloorEven(nNum) < k || pNum == 0 && zero == 0 && k % 2 == 1)
	    first = true;

	int second = false;
	if(zero != 0 && pNum + getFloorEven(nNum) < k || zero != 0 && pNum == 0 && k % 2 == 1)
	    second = true;
//    printf("%d\n", first);
	if( first || second){
		vector<int> num; 
		for(int i = 0; i < pNum; i++)
		    num.push_back(postive[i]);

		for(int i = 0; i < nNum; i++)
		    num.push_back(negative[i]);

		for(int i = 0; i < zero; i++)
		    num.push_back(0);

		//minutes
		if(first){
		   sort(num.begin(), num.end(), CMP1());
	       }else{
		   //for zero
		   sort(num.begin(), num.end());
		}

	       ans = 0;
	       int nr = num.size();
	       for(int i = 0; i < k; i++)
		   ans += num[nr - i - 1];
	}else{
	    vector<int> num;
	    for(int i = 0; i < pNum; i++)
		num.push_back(postive[i]);

	    //只存偶数个负数
	    int next = getFloorEven(negative.size()); 
	    for(int i = 0; i < next; i++)
		num.push_back(negative[i]);

	    sort(num.begin(), num.end(), CMP());
	    /*
for(int i = 0; i < num.size(); i++)
printf("%d ", num[i]);
printf("\n");
*/
	    
	    //以下对负数进行配对
	    int nr = num.size();
	    memset(match, -1, sizeof(match));
	    for(int i = 0; i < nr; i++){
		if(match[i] != -1 || num[i] >= 0)
		    continue;
		for(int j = i + 1; j < nr; j++)
		    if(num[j] < 0){
			match[i] = j;
			match[j] = i;
			break;
		    }
	    }

	    //选择k个数，同时判断负数是否成对
	    vector<int> result; 
	    int hasNegative = -1;
	    int lastPostive = -1;

	    for(int i = 0; i < k; i++){
		result.push_back(num[i]);
		if(num[i] > 0){
		    lastPostive = i;
		}else if(num[i] < 0 && match[i] >= k){
		    hasNegative = i;
		}
	    }

	    if(hasNegative >= 0){
		int nextPos = -1;
		for(int i = k; i < nr; i++)
		    if(num[i] > 0){
			nextPos = i;
			break;
		    }

		if(nextPos >= 0){
		    if(lastPostive == -1){
			for(int i = 0; i < k; i++)
			    if(result[i] == num[hasNegative]){
				result[i] = num[nextPos];
				break;
			    }
			goto L;
		    }
		    
		    if(lastPostive != -1)
		    if(num[nextPos] * num[lastPostive] >= 
		       num[hasNegative] * num[match[hasNegative]]){
			for(int i = 0; i < k; i++)
			    if(result[i] == num[hasNegative]){
				result[i] = num[nextPos];
				break;
			    }
		    }else{
			if(lastPostive != -1)
			for(int i = 0; i < k; i++)
			   if(result[i] == num[lastPostive]){
				result[i] = num[match[hasNegative]];
				break;
			    }
		    }
		}else{
		    for(int i = 0; i < k; i++)
			if(result[i] == num[lastPostive]){
			    result[i] = num[match[hasNegative]];
			    break;
			}
		}
	    }

	L:
	    ans = 0;
	    for(int i = 0; i < k; i++)
		ans += result[i];
	}

	if(k == 1) ans = max;
	printf("%d\n", ans);
    }
    return 0;
}
