#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using std::sort;

const int maxn = 10200;

struct Ant{
    int num;
    int number;
    int localte;
    bool operator<(const Ant & ant) const{
	return localte < ant.localte;
    }
};

Ant ant[maxn], ant2[maxn];
int num[maxn];

int get(){
    char c = getchar();
    while(c != 'L' && c != 'R')
	c = getchar();
    if(c == 'L') return -1;
    else return +1;
}

int main(){
    int T, cas, L, t, n;
    scanf("%d", &T);
    for(cas = 1; cas <= T; cas++){
	scanf("%d%d%d", &L, &t, &n);
	for(int i = 0; i < n; i++){
	    int localte, direction; 
	    scanf("%d", &localte);
	    direction = get();
	    ant[i].localte = localte;	    
	    ant[i].number = direction;
	    ant[i].num = i;
	}

	sort(ant, ant + n);

	for(int i = 0; i < n; i++)
	    num[ant[i].num] = i;

	for(int i = 0; i < n; i++)
	    ant[i].localte += ant[i].number * t;

	sort(ant, ant + n);

	for(int i = 0; i < n; i++){
	    if(ant[i].localte < 0 || ant[i].localte > L)
		ant[i].number = 10;//"Fell off"
	    else if(i > 0 && ant[i].localte == ant[i-1].localte)
		ant[i].number = 11;//Turing 
	    else if(i < n - 1 && ant[i].localte == ant[i+1].localte)
		ant[i].number = 12;//Turing 
	}

//do something
	for(int i = 0; i < n; i++)
	    ant2[i] = ant[num[i]];
	    //ant2[ant[i].num] = ant[i];
	    //ant2[num[ant[i].num]] = ant[i];//do something

	printf("Case #%d:\n", cas);
	for(int i = 0; i < n; i++)
	    if(ant2[i].number == 10) 
		printf("Fell off\n");
	    else if(ant2[i].number > 10)
		printf("%d Turning\n", ant2[i].localte);
	    else if(ant2[i].number == -1)
		printf("%d L\n", ant2[i].localte);
	    else 
		printf("%d R\n", ant2[i].localte);

	printf("\n");
    }

    return 0;
}
