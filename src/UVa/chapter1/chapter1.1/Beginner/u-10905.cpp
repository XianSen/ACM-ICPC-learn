#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100;
typedef struct Num{
    string s;
    bool operator<(const Num n) const{
	string s1 = s + n.s;
	string s2 = n.s + s;
	if(s1 > s2) return true;
	else return false;
    }
}Num;

Num num[maxn];

int main(){
    int i, n;
    while( cin>>n ){
	if(n == 0) break;
	for(i = 0; i < n; i++)
	    cin >> num[i].s;

	sort(num,num+n);

	for(i = 0; i < n; i++)
	    cout << num[i].s;

	cout << endl;
    }
    return 0;
}
