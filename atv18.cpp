#include <stdio.h>
#include <iostream>

using namespace std;

int mono(vector<int> v){
	if(v.size()==1)return 1;
	else{
		vector<int> aux1;
		vector<int> aux2;
		for(int i=0;i<v.size();i++){
			if(i<v.size()/2)aux1.push_back(v[i]);
			else aux2.push_back(v[i]);
		}
		int r1 = mono(aux1);
		int r2 = mono(aux2);
		if(r1==0||r2==0)return 0;
		else{
			map<int,int> M;
			for(int i=0;i<)
		}
	}
}

int main(void){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		vector<int> v(t);
		for(int j=0;j<t;j++){
			scanf("%d",&v[j]);
		}
	}
}
