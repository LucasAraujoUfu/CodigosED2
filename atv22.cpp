#include <iostream>
#include <stdio.h>
#include <math.h>
#include <set>


using namespace std;

int busca(int *v,int n){
	int best=0, sum=0;
	set<int> S;
	for(int i=0;i<n;i++){
		if(S.find(v[i])==S.end()){
			S.insert(v[i]);
			sum++;
		}
		else{
			best = fmax(best, sum);
			S.clear();
			sum=1;
			S.insert(v[i]);
		}
	}
	best = fmax(best, sum);
	return best;
}


int main(void){
	int n;
	scanf("%d",&n);
	for(int k=0;k<n;k++){
		int t;
		scanf("%d",&t);
		int v[t];
		for(int i=0;i<t;i++){
			scanf("%d",&v[i]);
		}
		printf("%d\n",busca(v,t));
	}
	return 0;
}
