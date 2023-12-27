#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){
	while(true){
		int n;
		int t=0,d=0;
		scanf("%d",&n);
		if(n==-1)break;
		int v;
		for(int i=0;i<n;i++){
			scanf("%d",&v);
			d+=v;
			if(d%100==0){
				t++;
				d=0;
			}
		}
		printf("%d\n",t);
	}
	return 0;
}
