#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int left[] = {1, 5, 2, 3, 0, 4};
int up[] = {3, 1, 0, 5, 4, 2};


//T是模式， p是结果
void rot(int *T, int *p){
    int q[6]; 
    memcpy(q, p, sizeof(q));
    for(int i = 0; i < 6; i++)
	p[i] = T[q[i]];
}

int main(){
    int sum = 0;
    int p0[6] = {0, 1, 2, 3, 4, 5}; 
    for(int k = 0; k < 6; k++){ 
	int p[6];
	memcpy(p, p0, sizeof(p0));
	if(k == 0) rot(up, p);		
	if(k == 1) {rot(left, p); rot(left, p); rot(left,p), rot(up,p);}
	if(k == 3) {rot(up, p); rot(up, p);}
	if(k == 4) {rot(left, p); rot(up, p);}
	if(k == 5) {rot(left,p); rot(left,p); rot(up,p);}
	for(int i = 0; i < 4; i++){
	    printf("{%d, %d, %d, %d, %d, %d}, ", p[0],p[1],p[2],p[3],p[4],p[5]);
	    rot(left, p);
	    sum++;
	    if(sum % 3 == 0) printf("\n");
	}
    }
    return 0;
}
