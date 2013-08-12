#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAXN = 10000 + 100;
struct Point{
    int x;
    int y;
}p[MAXN];

int dx[] = {0, -1, -1, 0, +1, +1};
int dy[] = {+1, +1, 0, -1, -1, 0};
int dz[] = {0, -1, 0, 0, 0, 0};

void init(){
    int n = 10000;
    int x = 0, y = 0, count, index = 2, num;
    p[1].x = 0, p[1].y = 0;

    for(num = 1; index <= n; num++)
	for(int i = 0; i < 6; i++)
	  for(count = 0; count < num + dz[i] && index <= n; count++,index++)
	  {
	      x = x + dx[i];
	      p[index].x  = x; 
	      y = y + dy[i];
	      p[index].y = y;
	  }

}

int main(){
    init();
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
	if(a == 0 && b == 0) break;
	int dx = p[a].x - p[b].x;
	int dy = p[a].y - p[b].y;
	printf("The distance between cells %d and %d is %d.\n", a, b, (abs(dx) + abs(dy) + abs(dx + dy)) / 2);
    }
    return 0;
}
