#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int select(vector<int> v){
	int c=0;
	for(int i=0;i<(signed)v.size()-1;i++){
		for(int j=i+1;j<(signed)v.size();j++){
			if(v[j]<v[i]){
				swap(v[j],v[i]);
				c++;
			}
		}
	}
	return c;
}

int main(void){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int m;
		scanf("%d",&m);
		vector<int> v(m);
		for(int j=0;j<m;j++){
			scanf("%d",&v[j]);
		}
		printf("A quantidade ajeitamentos deve ser %d.\n",select(v));
	}
	return 0;
}
