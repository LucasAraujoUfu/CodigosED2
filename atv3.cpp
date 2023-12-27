#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct{
	string nm;
	int ano;
	int temp;
} plt;

int main(void){
	int n;
	while(true){
		scanf("%d",&n);
		if(n==0)break;
		plt p[n];
		int tp,pos;
		for(int i=0;i<n;i++){
			cin>>p[i].nm;
			scanf(" %d %d",&p[i].ano, &p[i].temp);
			int tt =  p[i].ano - p[i].temp;
			if(i==0){
				tp = tt;
				pos = 0;
			}
			else if(tt<tp){
				pos = i;
				tp = tt;
			}
		}
		cout<<p[pos].nm<<endl;
	}
	return 0;
}
