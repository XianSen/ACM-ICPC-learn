#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int maxn = 40000;
typedef struct Record{
    int len;
    double f;
    int name;
    bool operator<(const Record & r) const {
	return (len*r.f - r.len*f < 0);
    }
}Record;

Record record[maxn];

int main(){
    int i, j, n;
    while(scanf("%d", &n) != EOF){
	for(i = 0; i < n; i++)
	    scanf("%d%d%lf", &record[i].name, &record[i].len, &record[i].f);
	sort(record, record+n);
	scanf("%d", &j);
	printf("%d\n", record[j-1].name);
    }
    return 0;
}
