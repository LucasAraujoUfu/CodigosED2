#include <iostream>
#include <stdio.h>
#include <vector>

#define N 'Z'-'@'

using namespace std;

int comp[N];
vector<int> g[N];

void dfs(int x){
	for(int i=0;i<(signed)g[x].size();i++){
		int v = g[x][i];
		if(comp[v]==-1){
			comp[v] = comp[x];
			dfs(v);
		}
	}
}

int main(void){
	int t;
	scanf("%d",&t);
	for(int k=0;k<t;k++){
		char ch;
		scanf(" %c",&ch);
		getchar();
		int n = (int)ch-64;
		for(int i=0;i<n;i++){
			comp[i]=-1;
			g[i].clear();
		}
		string s;
		while(getline(cin,s)){
			if(s=="")break;
			g[s[0]-65].push_back(s[1]-65);
			g[s[1]-65].push_back(s[0]-65);
		}
		int c=0;
		for(int i=0;i<n;i++){
			if(comp[i]==-1){
				comp[i] = ++c;
				dfs(i);
			}
		}
		if(k!=0)printf("\n");
		printf("%d\n",c);
	}
    return 0;
}
