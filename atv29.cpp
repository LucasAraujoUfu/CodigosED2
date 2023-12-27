#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>


using namespace std;

int main(void){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(m==0&&n==0)break;
		//vector<int> g[n+2];
		set<int> lista;
		int grauE[n+2];
		int grauS[n+2];
		for(int i=1;i<=n;i++){
			grauE[i]=0;
			grauS[i]=0;
		}
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			//g[a].push_back(b);
			grauS[a]++;
			grauE[b]++;
		}
		
		for(int i=1;i<=n;i++){
			if(grauE[i]==0)lista.insert(i);
		}
		for(int i : lista){
			printf("%d ",i);
		}printf("\n");
		
		lista.clear();
		
		for(int i=1;i<=n;i++){
			if(grauS[i]==0)lista.insert(i);
		}
		for(int i : lista){
			printf("%d ",i);
		}printf("\n");
		
		/*
		while(!lista.empty()){
			int atual = *lista.lower_bound();
			lista.erase(atual);
			for(int i=0;i<g[atual].size();i++){
				int v = g[atual][i];
				grau[v]--;
				if(grau[v]==0)lista.insert(v);
			}
		}*/
	}
	return 0;
}
