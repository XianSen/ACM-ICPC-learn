#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//判断点是否在矩形内,包括端点
int check(int x, int y, int t1, int t2, int s1, int s2){
    if(!(t1 <= x && x <= t2)) return false;
    if(!(s1 <= y && y <= s2)) return false;
    return true;
}

//计算矩形被直线切的面积 y = x + k
double calc(int t1, int t2, int s1, int s2, int k){
    //    if(t2 - t1 < s2 - s1) return calc(s1, s2, t1, t2, k);
    //第一种情况，切成三角形
    if(check(s1, s1 + k, s1, s2, t1, t2) && check(t2 - k, t2, s1, s2, t1, t2)){
#ifdef NOTHI_DEBUG
	printf("第一种情况\n");
#endif
	int len1 = t2 - (s1 + k);
	int len2 = t2 - k - s1; 
	return len1 * len2 / 2.0;
    }

    //第二种情况,剩下的是三角形
    if(check(t1 - k, t1, s1, s2, t1, t2) && check(s2, s2 + k, s1, s2, t1, t2)){
#ifdef NOTHI_DEBUG
	printf("第二种情况\n");
#endif
	int area = (t2 - t1) * (s2 - s1);
	int len1 = s2 - (t1 - k);
	int len2 = s2 + k - t1;
	return area - len1 * len2 / 2.0;
    }

    //第三，第四种情况，即没有写矩形接触
    if(s1 + k >= t2 || s2 + k <= t1){
#ifdef NOTHI_DEBUG
	printf("第三，四种情况\n");
#endif
//	return 0;
	return s2 + k <= t1 ? (s2 - s1) *(t2 - t1):0;
    }

    //第五种，是梯形
#ifdef NOTHI_DEBUG
    printf("第五种情况\n");
#endif
    //  第一种梯形
    if(check(t1 - k, t1, s1, s2, t1, t2) && check(t2 - k, t2, s1, s2, t1, t2)){
	int len1 = t1 - k - s1;
	int len2 = t2 - k - s1;
	int len = t2 - t1;
	return (len1 + len2) * len / 2.0;
    }
    //  第二种梯形
    if(check(s1 , s1 + k, s1, s2, t1, t2) && check(s2 , s2 + k, s1, s2, t1, t2)){
	int len1 = t2 - (s1 + k);
	int len2 = t2 - (s2 + k);
	int len = s2 - s1;
	return (len1 + len2) * len / 2.0;
    }
    return 0;
}

int main(){
    int tt;
    scanf("%d", &tt);
    for(int kcase = 1; kcase <= tt; kcase++){
	int s1, s2, t1, t2, w;
	scanf("%d%d%d%d%d", &t1, &t2, &s1, &s2, &w);
	double area1 = calc(s1, s2, t1, t2, w);
	double area2 = calc(s1, s2, t1, t2, -w);
	double area = (t2 - t1) * (s2 - s1);
	printf("Case #%d: %0.8lf\n", kcase, fabs((area2 - area1) / area));
#ifdef NOTHI_DEBUG
	printf("%lf %lf\n", area1, area2);
#endif
    }
    return 0;
}
