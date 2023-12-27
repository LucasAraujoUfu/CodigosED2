#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

struct barco{
	int i;
	int u;
	
	bool operator < (barco b) const{
		return i<b.i || (i==b.i && u<b.u);
	}

};

int main(void){
	multiset<barco> v;
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int n,ia,ua;
		v.clear();
		scanf("%d",&n);
		printf("Caso #%d:\n",i+1);
		for(int j=0;j<n;j++){
			scanf("%d%d",&ia,&ua);
			barco aux;
			aux.i = ia;
			aux.u = ua;
			multiset<barco>::iterator it;
			it = v.lower_bound(aux);
			if(it==v.begin()||(--it)->u>ua){
				v.insert(aux);
				it = v.upper_bound(aux);
				while(it!=v.end()&&it->u>=ua){
					v.erase(it++);
				}
			}
			printf("%lu\n",v.size());
		}
		if(i<N-1)cout<<endl;
	}
	return 0;
}
