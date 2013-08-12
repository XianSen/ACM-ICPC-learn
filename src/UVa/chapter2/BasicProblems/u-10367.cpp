#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 1100;

char s[MAXN];

struct Equation{
    int x;
    int y;
    int ans;
};

int getElement(int left, int right, int& x, int& y, int& z){
    if(s[left] == '+' || s[left] == '-' || s[left] == '='){
	if(left == right)
	    return 0;
	else{
	    int status = getElement(left + 1, right, x, y, z);
	    if(s[left] == '-'){
		x = -x;
		y = -y;
		z = -z;
	    }
	    return status;
	}
    }

    int num = 0;
    for(int i = left; i <= right; i++)
	if(s[i] >= '0' && s[i] <= '9')
	    num = num * 10 + s[i] - '0';

    if(s[right] == 'x'){
	x = num;
	y = z = 0;
	if(x == 0) x = 1;
    }else if (s[right] == 'y'){
	y = num;
	x = z = 0;
	if(y == 0) y = 1;
    }else{
	z = num;
	x = y = 0;
    }
    return 1;
}

Equation parse(char *s){
    int begin = 0;
    int end = strlen(s);
    s[end] = ' ';
    int now = 1;
    int where = 1;

    Equation e;
    e.x = e.y = e.ans = 0;

    while(begin <= end){
	int left = -1;
	int right = -1;

	for(int i = begin; i <= end; i++)
	    if(s[i] != ' ') {
		left = i;
		break;
	    }

	for(int i = left + 1; i <= end; i++)
	    if(s[i] == ' ') {
		right = i - 1;
		break;
	    }

	begin = right + 2;
	if(left != -1 && right != -1){
	    int x, y, z;
	    int status = getElement(left, right, x, y, z);
	    //不是等于号
	    if(status){
		e.x += x * where * now;
		e.y += y * where * now;
		e.ans += z * where * (-1) * now;
		now = 1;
	    }else{
		if(s[left] == '='){
		    where = -1;
		}else if (s[left] == '+'){
		    now = 1;
		}else if (s[left] == '-'){
		    now = -1;
		}
	    }
	}
    }

    return e;
}

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

void simple(int& a, int& b){
    int d = gcd(a, b);

    if(d != 0){
	a = a / d;
	b = b / d;
    }

    if(b < 0){
	a = -a;
	b = -b;
    }

    if(a == 0) b = 1;
}

int main(){
    int  n;
    scanf("%d", &n);
    for(int kcase =1; kcase <= n; kcase++){
	if(kcase != 1) printf("\n");

	gets(s);
	while(strlen(s) == 0) gets(s);
	Equation e1 = parse(s);
	gets(s);
	while(strlen(s) == 0) gets(s);
	Equation e2 = parse(s);

	int a = e1.x;
	int b = e1.y;
	int c = e2.x;
	int d = e2.y;
	int e = e1.ans;
	int f = e2.ans;
	int ans[4];

	int A = a * d - b * c;
	if(A == 0){
	    int ok1 = 0, ok2 = 0;
	    //若x 有解
	    if(a != 0 && b == 0 || c != 0 && d == 0){ 
		if(c * e == a * f){
		    ok1 = 1;
		    if(a == 0){
			a = c;
			e = f;
		    }
		    ans[1] = a, ans[0] = e;
		    simple(ans[0], ans[1]);
		}
	    };

	    //若y 有解
	    if(a == 0 && b != 0 || c == 0 && d != 0){ 
		if(d * e == b * f){
		    ok2 = 1;
		    if(b == 0){
			b = d;
			e = f;
		    }

		    ans[3] = b, ans[2] = e;
		    simple(ans[2], ans[3]);
		}
	    };

	    if(ok1 + ok2 == 1){
		if(ok1){
		    if(ans[1] == 1) printf("%d\n", ans[0]);
		    else printf("%d/%d\n", ans[0], ans[1]);
		    printf("don't know\n");
		}else{
		    printf("don't know\n");
		    if(ans[3] == 1) printf("%d\n", ans[2]);
		    else printf("%d/%d\n", ans[2], ans[3]);
		}
	    }else{
		printf("don't know\n");
		printf("don't know\n");
	    }
	}else{
	    ans[0] = d * e - b * f;
	    ans[1] = A;

	    ans[2] = -1 * c * e + a * f;
	    ans[3] = A;

	    simple(ans[0], ans[1]);
	    simple(ans[2], ans[3]);

	    if(ans[1] == 1) printf("%d\n", ans[0]);
	    else printf("%d/%d\n", ans[0], ans[1]);

	    if(ans[3] == 1) printf("%d\n", ans[2]);
	    else printf("%d/%d\n", ans[2], ans[3]);
	}
    }
    return 0;
}
