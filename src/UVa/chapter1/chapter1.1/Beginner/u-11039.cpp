#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 540000;

//blue
int h1[maxn];
//red
int h2[maxn];

int solve(int h1[], int blue, int h2[], int red, int & ans){
    int h;

    h = 0;
    red--;
    blue--; 
    ans = 0x7fffffff;

    while(blue >= 0){     
	while(blue >= 0 && h1[blue] > ans)
	    blue--;
	if(blue < 0 || h1[blue] > ans)
	    return h;

	h++;
	ans = h1[blue--];

	while(red >= 0 && h2[red] > ans)
	    red--;

	if(red < 0 || h2[red] > ans)
	    return h;

	h++;
	ans = h2[red--];
    }

    return h;
}

int main(){
    int i, n, T, blue, red, value, ans1, ans2;
    scanf("%d", &T);

    while(T--){
	blue = red = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
	    scanf("%d", &value);
	    if(value < 0) h1[blue++] = -value;
	    else h2[red++] = value;
	}

	sort(h1, h1+blue);
	sort(h2, h2+red);

	int first = solve(h1, blue, h2, red, ans1);	
	int second = solve(h2, red, h1, blue, ans2);

//	printf("%d %d\n", first, second);

	if(first > second)
	    printf("%d\n", first);
	else
	    printf("%d\n", second);
	    
    }

    return 0;
}
