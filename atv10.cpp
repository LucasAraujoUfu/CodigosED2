#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int maxSum(int *a,int n){
	int best = 0, sum = 0;
	for(int i=0;i<n;i++){
		sum = max(a[i],sum+a[i]);
		best = max(best,sum);
	}
	return best;
}

int main(void){
	int n;
	while(cin>>n){
		if(n==0)break;
		int v[n];
		for(int i=0;i<n;i++)scanf("%d",v+i);
		int r = maxSum(v,n);
		if(r>0)printf("Maior sequência ganhadora é %d.\n",r);
		else printf("Sequência perdedora.\n");
	}
	return 0;
}
