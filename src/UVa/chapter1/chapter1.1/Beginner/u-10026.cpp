#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using std::sort;

const int maxn = 2100;

struct Job{
    int num;
    int time;
    int fine;
    bool operator<(const Job & job) const{
	if(time*job.fine < job.time*fine)
	    return true;
	if(time*job.fine > job.time*fine)
	    return false;
	return num < job.num;
    }
};

int n;
Job job[maxn];

int main(){
    int cas, ok = 0;
    scanf("%d", &cas);
    while(cas--){
	if(ok != 0){
	    printf("\n");
	}
	ok = 1;
	scanf("%d", &n);
	for(int i = 0; i < n;i++){
	    job[i].num  = i + 1;
	    scanf("%d%d", &job[i].time, &job[i].fine);
	}

	sort(job, job+n);

	for(int i = 0; i < n; i++)
	    if(i == n - 1)
		printf("%d\n", job[i].num);
	    else
		printf("%d ", job[i].num);
    }
    return 0;
}
