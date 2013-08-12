#include <vector>
#include <string>
#include <iostream>
using namespace std;

const int MAXN = 400;
const int MAXM = 400;

int n;
string file[MAXN];

bool check(string s){
    for(int i = 0; i < n; i++){
	bool find = false;
	for(int j = 0; j < n && !find; j++)
	    if(i != j){
		if(file[i] + file[j] == s){
		    find = true;
		}
		if(file[j] + file[i] == s){
		    find = true;
		}
	    }
	if(!find) return false;
    }
    return true;
}

int main(){
    int t;    
    cin >> t;
    while(t--){
	n = 0;
	int len = MAXN * MAXM;
	string maxString = "";

	while(true){
	   string s; 
	   getline(cin, s);
	   if(n != 0 && s.empty())
	       break;
	   if(s.empty()) continue;
	   file[n++] = s;
	   if(s.length() > maxString.length())
	       maxString = s;
	   if(s.length() < len)
	       len = s.length();
	}


	string ans;
	for(int i = 0; i < n; i++)
	    if(file[i].length() == len){
		if(check(maxString+file[i])){
		    ans = maxString + file[i];
		    break;
		}
		if(check(file[i] + maxString)){
		    ans = file[i] + maxString;
		    break;
		}
	    }

	cout << ans << endl;
	if(t) cout << endl;
    }
    return 0;
}
