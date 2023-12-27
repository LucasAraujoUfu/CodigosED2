#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>

using namespace std;

struct letra{
	char c;
	int freq;
};

int ord(letra a, letra b){
	if(a.freq>b.freq)return true;
	else if(a.freq<b.freq)return false;
	else{
		if(a.c<b.c)return true;
		else if(a.c>b.c)return false;
	}
	return false;
}

void ordena(letra vet[], int n){
	for(int i=0;i<n-1;i++){
		int menor = i;
		for(int j=i+1;j<n;j++){
			if(ord(vet[j],vet[menor])){
				menor = j;
			}
		}
		if(menor != i){
			swap(vet[i],vet[menor]);
		}
	}
}

int main(void){
	int n;
	scanf("%d",&n);
	cin.ignore();
	letra l[26];
	for(int j=0;j<26;j++){
		l[j].c = 65+j;
		l[j].freq = 0;
	}
	for(int i=0;i<n;i++){
		string s;
		getline(cin,s);
		for(int j=0;j<(signed)s.size();j++){
			char c = toupper(s[j]);
			if(c>=65&&c<=90)l[c-65].freq++;
		}
	}
	//sort(l,l+26,ord);
	ordena(l,26);
	for(int j=0;j<26;j++){
		if(l[j].freq==0)break;
		printf("%c %d\n",l[j].c,l[j].freq);
	}
	return 0;
}
