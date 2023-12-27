#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cont(string s){
	int c = 0;
	for(int i = 0;i<(signed)s.size()-1;i++){
		for(int j = i+1;j<(signed)s.size();j++){
			if(s[j]<s[i]){
				c++;
			}
		}
	}
	return c;
}

void ordena(vector<pair<int,int>>& vet){
	for(int i=0;i<(signed)vet.size()-1;i++){
		int menor = i;
		for(int j=i+1;j<(signed)vet.size();j++){
			if(vet[j]<vet[menor]){
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
	for(int i=0;i<n;i++){
		int m,k;
		scanf("%d%d",&m,&k);
		string s[k];
		for(int j=0;j<k;j++)cin>>s[j];
		vector<pair<int,int>> p(k);
		for(int j=0;j<k;j++){
			p[j].first = cont(s[j]);
			p[j].second = j;
		}
		ordena(p);
		for(int j=0;j<k;j++){
			cout<<s[p[j].second]<<endl;
		}
		if(i<n-1)printf("\n");
	}
	return 0;
}
