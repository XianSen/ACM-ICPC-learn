#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXN = 300;
const int MAXM = 150;

char oldFile[MAXM];
char file[MAXN][MAXM];
struct Node{
    int flag;
    int next[2];
};

int n, usage, root1, root2;
Node tree[MAXN * MAXM * 3];

void add(int root, char *start, char *end, int inc){
    while(start != end){
	int now = *start - '0';
	if(tree[root].next[now] == 0){
	    tree[root].next[now] = usage++;
	}
	root = tree[root].next[now];
	start += inc;
    }
    tree[root].flag++;
}

bool find(int root, char * ans, int n){
    if(root == 0) return false;
    if(n <= 0){
	*ans = 0;
	return true;
    }
    *ans = '0';
    if(find(tree[root].next[0], ans + 1, n - tree[root].flag))
	return true;
    *ans = '1';
    return find(tree[root].next[1], ans + 1, n - tree[root].flag);
}

int main(){
    int t;
    scanf("%d", &t);
    getchar();
    getchar();
    while(t--){
	int len = 0;
	n = 0;
	while(true){			
	    gets(file[n]);
	    if(strlen(file[n]) == 0 && n != 0)
	       	break;
	    len += strlen(file[n]);
	    n++;
	}
	len = len * 2 / n;
	
	usage = 1;
	root1 = usage++;
	root2 = usage++;
	memset(tree, 0, sizeof(tree));

	for(int i = 0; i < n; i++)
             add(root1, file[i],file[i] + strlen(file[i]), 1);

	for(int i = 0; i < n; i++)
             add(root2,file[i] + strlen(file[i])-1,file[i] - 1, -1);

	find(root1,file[MAXN-1], n/2);
	find(root2,file[MAXN],n/2);

	oldFile[len] = 0;	
	char *s1 = file[MAXN - 1];
	int n1 = strlen(file[MAXN - 1]);	
	for(int i = 0; i < n1; i++)
	    oldFile[i] = s1[i];

	char *s2 = file[MAXN];
	int n2 = strlen(file[MAXN]);	
	for(int i = 0; i < n2; i++)
	    oldFile[len - i - 1] = s2[i];

	printf("%s\n", oldFile);
	if(t) printf("\n");
    }
    return 0;
}
