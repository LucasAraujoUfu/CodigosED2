#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> bit = {50,25,10,5,1};

int troco(int n, int m){
	int memo[n+1][m] = {0};
	for(int i=0;i<m;i++)memo[0][i] = 1;
	for(int valor=1;valor<n+1;valor++){
		for(int moeda=0;moeda<m;moeda++){
			int com_i=0;
			if(valor-bit[moeda]>=0){
				com_i=memo[valor-bit[moeda]][moeda];
			}
			int sem_i=0;
			if(moeda>=1){
				sem_i=memo[valor][moeda-1];
			}
			memo[valor][moeda]=com_i+sem_i;
		}
	}
	return memo[n][m-1];
}

int main(void){
	int n;
	while(scanf("%d",&n)!=EOF)printf("%d\n",troco(n,bit.size()));
	return 0;
}
