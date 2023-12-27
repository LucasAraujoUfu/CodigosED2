#include <bits/stdc++.h>
 
#define N 100005
 
using namespace std;
 
typedef pair<int,int> pii;
 
vector<int> caminho;
vector<int> g[N];

void acha_caminho(int v){
	for(int i=0;i<g[v].size();i++){
		auto vz = g[v][i];
		
		if(g[v][i].second == false)continue;
 
		g[v][i].second = false;
		g[i][v].second = false;
		
		//vis.insert({v,vz});
		
		acha_caminho(vz);
	}
	caminho.push_back(v);
}
 
 
int main(void){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back({b,true});
		g[b].push_back({a,true});
	}
	acha_caminho(1);
	if(caminho.size()-1!=m)printf("IMPOSSIBLE\n");
	else{
		for(int i:caminho){
			printf("%d ",i);
		}
	}
	printf("\n");
	return 0;
}
