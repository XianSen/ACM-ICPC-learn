#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int AVE_LEN = 10;
const int MAX_LEN = 200;
const int MAXN = 130000;

char s1[MAX_LEN];
char s2[MAX_LEN];

struct Node{
    Node(){
	flag = 0;
	father = 0;
	memset(next, 0, sizeof(next));
    }
    int flag;
    int father;
    int next[26];
};

int wordCount = 1;
int used, root1, root2;

Node tree[MAXN * AVE_LEN * 2];

void init(){
    root1 = 0;
    root2 = 1;
    used = 2;
}

void insert(int root, char s[]){
    while((*s) != 0){
	int c = (*s++) - 'a';		
	if(tree[root].next[c] == 0){
	    tree[root].next[c] = used;
	    tree[used].father = root;
	    used++;
	}
	root = tree[root].next[c];
    }
    tree[root].flag = wordCount;
}

void insert(char s[]){
    int len = strlen(s);
    for(int i = 0; i < len; i++)
	s2[i] = s[len - i - 1];
    s2[len] = 0;
    insert(root1, s);
    insert(root2, s2);
}

int getWord(){
    char c = getchar();
    while(!isalpha(c) && c != EOF) 
	c = getchar();

    char *ss = s1;
    if(c == EOF) return 0;
    while(isalpha(c)){
	(*ss) = c;
	ss++;
	c = getchar();
    }

    (*ss) = 0;
    insert(s1);
    if(c == EOF) return 0;
    return 1;
}

int find(int root, char *s){
    while((*s) != 0){
	int c = (*s++) - 'a';		
	if(tree[root].next[c] == 0){
	    tree[root].next[c] = used;
	    tree[used].father = root;
	    used++;
	}
	root = tree[root].next[c];
    }
    return root;
}

void check(int root){
    int len = strlen(s1);
    for(int i = 0; i < len; i++)
	s2[i] = s1[len - i - 1];
    char * s = s2;
    int r1 = root;
    int r2 = root2;

    int can = false;

    for(int i = 0; i < len; i++){
	r1 = tree[r1].father;
	r2 = tree[r2].next[(*s++) - 'a'];

	if(tree[r1].flag != 0 &&tree[r2].flag != 0){
	    can = true;
	    break;
	}
    }
    if(can) printf("%s\n", s1);
}

void travel(int root, char* s){
    if(tree[root].flag != 0){
	*(s) = 0;
	check(root);
    }
    for(int i = 0; i < 26; i++)
	if(tree[root].next[i] != 0){
	    (*s) = (i + 'a');
	    travel(tree[root].next[i], s+1);
	}
}

int main(){
    init();
    while(getWord()) 
	wordCount++;
    travel(root1, s1);    
    return 0;
}
