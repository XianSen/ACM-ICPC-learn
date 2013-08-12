#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n = 2;
    int x = 3, y = 2;
    int x1 = 3, y1 = 2;
    for(int i = 1; i <= 10; i++){ 
	int x0 = x, y0 = y;
	x = x1 * x0 + n * y1 * y0;
	y = x1 * y0 + y1 * x0;
	printf("%10d%10d\n", y/2, x/2);
    }
    return 0;
}
