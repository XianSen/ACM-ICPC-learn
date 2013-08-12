#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read(){
    int a, b, c;
    int status = scanf("%d:%d:%d", &a, &b, &c);
    if(status != 3) return -1; 
    return a * 3600 + b * 60 + c;;
}

double calc(double t[]){
    double vc = (t[3] - t[1])/(t[4] - t[1]);
    double vm = (t[3] - t[2])/(t[5] - t[2]);
    double t6 = ((t[2] - t[1]) - vc * (t[2] - t[1]))/(vc - vm) + t[2];
    return t6;
}

int main(){
    double t[10];
    while((t[1] = read()) >= 0){
	for(int i = 2; i <= 5; i++)
	    t[i] = read();
	double result = calc(t);
	int s = (int)(result + 0.5);
	printf("%.2d:%.2d:%.2d\n", s / 3600, (s / 60) % 60, s % 60);
    }
    return 0;
}
