#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> v;
vector<vector<int>> memo;

int diferenca_min(int p1, int p2){ 
	int dif = p1 - p2;
	if(memo[p1][p2]==-1){
		if(dif==0)memo[p1][p2] = 0;
		else if(dif<0)memo[p1][p2] = INT16_MAX;
		else{
			for (int i = 0; i < (signed)v.size(); i++){
				dif=min(diferenca_min(p1 - v[i], p2 + v[i]), dif);
			}
			memo[p1][p2]=dif;  
		}
	}
	return memo[p1][p2];
}

int main(void){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int m,tot=0;
		scanf("%d",&m);
		v = vector<int>(m);
		for(int j=0;j<m;j++){
			scanf("%d",&v[j]);
			tot+=v[j];
		}
		memo = vector<vector<int>>(tot+1,vector<int>(tot+1,-1));
		int r = diferenca_min(tot,0);
		printf("%d\n",r);
	}
	return 0;
}
