#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

long long int memo[10000] = {1};

long long int len(long long int n){
	if(n>10000){
		if(n%2==0)return 1 + len(n/2);
		else return 1 + len(n*3+1);
	}
	else if(memo[n-1]==0){
		if(n%2==0)memo[n-1] = 1 + len(n/2);
		else memo[n-1] = 1 + len(n*3+1);
	}
	return memo[n-1];
}

int main(void){
	int i,j;
	while(cin>>i>>j){
		long long int max=0, temp;
		for(int k = fmin(i,j);k<=fmax(i,j);k++){
			temp = len(k);
			if(max<temp)max=temp;
		}
		printf("%d %d %lld\n",i,j,max);
	}
	return 0;
}
