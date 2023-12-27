#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

vector<vector<int>> memo;
vector<vector<int>> m;

int minFuel(int alt, int dist){
	//if(dist == (signed)m[0].size())return 0;
	if(memo[alt][dist]==-1){
		if(alt == 0)memo[alt][dist] = fmin(60 - m[alt][dist-1] + minFuel(alt+1,dist-1),
											30 - m[alt][dist-1] + minFuel(alt,dist-1));
		else if(alt == 9)memo[alt][dist] = fmin(20 - m[alt][dist-1] + minFuel(alt-1,dist-1),
											30 - m[alt][dist-1] + minFuel(alt,dist-1));
		else memo[alt][dist] = fmin(20 - m[alt][dist-1] + minFuel(alt-1,dist-1),
											fmin(30 - m[alt][dist-1] + minFuel(alt,dist-1),
											60 - m[alt][dist-1] + minFuel(alt+1,dist-1)));
	}
	return memo[alt][dist];
}

int main(void){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		memo = vector<vector<int>>(10,vector<int>((x/100)+1,-1));
		m = vector<vector<int>>(10,vector<int>((x/100),-1));
		for(int i=9;i>=0;i--){
			memo[i][0]=INT16_MAX;
			for(int j=(x/100)-1;j>=0;j--){
				cin>>m[i][j];
			}
		}
		memo[0][0]=0;
		cout<<minFuel(0,x/100)<<endl<<endl;
		/*
		for(int i=0;i<10;i++){
			for(int j=0;j<=(x/100);j++){
				cout<<memo[i][j]<<" ";
			}
			cout<<endl;
		}*/
		
	}

	return 0;
}
