#include <map>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1100;

struct Componet{
    int name;
    int price;
    int quality;
    bool operator<(const Componet  & s) const{
	return price < s.price;
    }
};

Componet que[maxn];
int cas, n, budget, num, l, r, m;

int ok[maxn];

bool check(int quality){
    int sum = 0, money = 0;
    memset(ok, 0, sizeof(ok));
    for(int i = 0; i < n; i++)
	if(!ok[que[i].name]  && que[i].quality >= quality){
	    sum++;
	    money += que[i].price;
	    ok[que[i].name] = 1;
	}

    return (money <= budget && sum == num);
}

int main(){
    cin >> cas; 
    while(cin >> n >> budget){
	num = 0;
	map<string, int> msi;		
	string type, name;
	int price, quality;

	r = 0;
	for(int i = 0; i < n; i++){
	    cin >> type >> name >> price >> quality;

	    if(msi.find(type) == msi.end()){
		msi[type] = num++;
	    }

	    que[i].name = msi[type];
	    que[i].price = price;
	    que[i].quality = quality;

	    if(quality > r)
		r = quality;
	}

	sort(que, que+n);

	l = 0, r = r + 1; 		
	while(l < r - 1){
	    m = (l + r) / 2;
	   if(check(m))
	       l = m;
	   else
	       r = m;
	}

	cout << l << endl;
    }
    return 0;
}
