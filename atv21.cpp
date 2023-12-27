#include <stdio.h>
#include <iostream>
#include <math.h>
#include <set>
#include <map>

using namespace std;

int main(void){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==0)break;
		map<set<int>,int> M;
		int max=0;
		for(int i=0;i<n;i++){
			int l;
			set<int> S;
			for(int j=0;j<5;j++){
				scanf("%d",&l);
				S.insert(l);
			}
			M[S]++;
			max = fmax(max,M[S]);
			S.clear();
		}
		int tot=0;
		for(pair<set<int>,int> p: M){
			if(p.second==max)tot+=max;
		}
		printf("%d\n",tot);
	}
	return 0;
}
