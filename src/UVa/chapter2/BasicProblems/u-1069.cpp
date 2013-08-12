#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef long long LL;

class Expression{
    public:
	LL c;
	LL e;
	LL get_value(LL x, LL mod){
	    LL value = 1;
	    x = x % mod;
	    for(LL i = 1; i <= e; i++)
		value = ((value % mod) * (x % mod)) % mod;
	    value = ((c % mod) * (value % mod)) % mod;
	    return value;
	}

	bool not_found(char *s, LL st, LL en, char c){
	    for(LL i = st; i <= en; i++)
		if(s[i] == c)
		    return false;
	    return true;
	}

	//s[st .. en] 提取出数字
	static LL get_num(char *s, LL st, LL en){
	    LL value = 0;
	    for(LL i = st; i <= en; i++)
		if(s[i] >= '0' && s[i] <= '9'){
		    value = value * 10 + s[i] - '0';
		}else if(s[i] == ' '){
		    continue;
		}else {
		    break;
		}
	    return value;
	}

	LL get_expression(char *s, LL st, LL en){
	    //prLLf("%d %d\n", st, en);
	    if(s[st] == '-' || s[st] == '+'){
		get_expression(s, st + 1, en);
		if(s[st] == '-')
		    c = -c;
	    }else{
		if(not_found(s, st, en, 'n')){
		    e = 0;
		    c = get_num(s, st, en);
		}else if(not_found(s, st, en, '^')){
		    e = 1;
		    if(st == en){
			c = 1;
		    }else{
			c = get_num(s, st, en);
		    }
		}else if(s[st] >= '0' && s[st] <= '9'){
		    c = get_num(s, st, en);
		    for(LL i = st; i <= en; i++)
			if(s[i] == '^'){
			    e = get_num(s, i + 1, en);
			    break;
			}
		}else{
		    c = 1;
		    for(LL i = st; i <= en; i++)
			if(s[i] == '^'){
			    e = get_num(s, i + 1, en);
			    break;
			}
		}
	    }
	}

	LL print(){
	   // printf("%lldn^%lld\n", c, e);
	}
};

//(2n^5 - 3n^4 - n^3 + n ^ 2 - 2n + 3n -n + n - c + c -1 + 1)
bool process(char *s){
    LL n = strlen(s);
    LL st = 0, en = n - 1;
    bool done = false;

    Expression exp;
    vector<Expression> vi;

    while(st != en && !done){
	LL i;
	LL left;
	LL right;
	for(i = st; i <= en; i++)
	    if(s[i] == '('){
		left = i + 1;
		break;
	    }else if (s[i] == ')'){
		done = true;
		break;
	    }else if (s[i] == '-'){
		left = i;
		break;
	    }else if (s[i] == '+'){
		left = i;
		break;
	    }

	if(done) break;

	right = left;
	for(i = left + 1; i <= en; i++)
	    if(s[i] == '('){
		right = i - 1;
		break;
	    }else if (s[i] == ')'){
		right = i - 1;
		done = true;
		break;
	    }else if (s[i] == '-'){
		right = i - 1;
		break;
	    }else if (s[i] == '+'){
		right = i - 1;
		break;
	    }

	st = right + 1;
	exp.get_expression(s, left, right);
	vi.push_back(exp);	
    }

    LL value = 0;
    for(LL i = 0; i < n; i++){
	if(s[i] == '/'){
	    value = Expression::get_num(s, i + 1, en);
	    break;
	}
    }

    int d = 0;
    LL size = vi.size();
    for(int j = 0; j < size; j++)
	if(vi[j].e > d) d = vi[j].e;

    d = d + 1;

    for(LL i = 1; i <= d ; i++){
	LL sum = 0;
	for(LL j = 0; j < size; j++){
	    LL now = vi[j].get_value(i, value);
	    sum = (sum + now) % value;
	 }
	if(sum != 0) return false;
    }

    return true;
}

char s[3000000];

int main(){
    int kcase = 0;
    while(scanf("%s", s) != EOF){
	if(s[0] == '.') break;
	if(process(s)){
	    printf("Case %d: Always an integer\n", ++ kcase);
	}else{
	    printf("Case %d: Not always an integer\n", ++ kcase);
	}
    }
    return 0;
}
