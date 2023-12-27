#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<int>> c;
vector<vector<int>> memo;

int minrep = INT32_MAX;

int minWay(){
	for(int i=0;i<(signed)c.size();i++){
		for(int j=0;j<(signed)c[i].size();j++){
			if(i==0&&i==j)memo[i][j]=0;
			else if(i==0)memo[i][j]=memo[i][j-1]+1;
			else if(j==0)memo[i][j]=memo[i-1][j]+1;
			else memo[i][j] = fmin(memo[i][j-1]+1,memo[i-1][j]+1);
		}
	}
	return memo.back().back();
}

int busca(int i,int j){
	if(memo[i][j]==-1){
		if(i==0&&j==0)memo[i][j] = 1;
		else if(i==0&&c[i][j-1]==1)memo[i][j] = busca(i,j-1);
		else if(j==0&&c[i-1][j]==1)memo[i][j] = busca(i-1,j);
		else if(c[i-1][j]==1&&c[i][j-1]==1)memo[i][j] = busca(i-1,j) + busca(i,j-1);
		else if(i!=0&&c[i-1][j]==1)memo[i][j] = busca(i-1,j);
		else if(j!=0&&c[i][j-1]==1)memo[i][j] = busca(i,j-1);
		else memo[i][j] = 0;
	}
	return memo[i][j];
}


int main(void){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int w,n;
		scanf(" %d%d",&w,&n);
		c = vector<vector<int>>(w,vector<int>(n,1));
		memo = vector<vector<int>>(w,vector<int>(n,-1));
		for(int j=0;j<w;j++){
			int l,p;
			scanf("%d",&p);
			string s;
			getline(cin,s);
			stringstream ss;
			ss<<s;
			while(ss>>l){
				c[p-1][l-1] = INT16_MAX;
			}

		}
		printf("%d\n",busca(w-1,n-1));
		if(i!=t-1)cout<<endl;
		//minWay();
		/*
		for(int j=0;j<w;j++){
			for(int l=0;l<n;l++){
				printf("%5d ",c[j][l]);
			}
			printf("\n");
		}*/
	}
	return 0;
}
