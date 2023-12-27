#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct no{
	char val;
	int pos;
	struct no *esq;
	struct no *dir;
};

void insere(char c, int pos, no *pai){
	if(pos>pai->pos){
		if(pai->dir==NULL){
			pai->dir = (no*) malloc(sizeof(no));
			pai->dir->val=c;
			pai->dir->esq=NULL;
			pai->dir->dir=NULL;
			pai->dir->pos=pos;
		}
		else insere(c,pos,pai->dir);
	}
	else{
		if(pai->esq==NULL){
			pai->esq = (no*) malloc(sizeof(no));
			pai->esq->val=c;
			pai->esq->esq=NULL;
			pai->esq->dir=NULL;
			pai->esq->pos=pos;
		}
		else insere(c,pos,pai->esq);
	}
}

void imprimePos(no *pai){
	if(pai->esq!=NULL)imprimePos(pai->esq);
	if(pai->dir!=NULL)imprimePos(pai->dir);
	printf("%c",pai->val);
}

int main(void){
	string pre, in;
	while(cin>>pre>>in){
		no pai;
		pai.val=pre[0];
		pai.pos = in.find(pre[0]);
		pai.esq = NULL;
		pai.dir = NULL;
		for(int i=1;i<(signed)pre.size();i++){
			insere(pre[i],in.find(pre[i]),&pai);
		}
		imprimePos(&pai);
		printf("\n");
	}
	return 0;
}
