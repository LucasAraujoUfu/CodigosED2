#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		if(i==0)printf("K");
		else printf("k");
	}
	printf("!\n");
	return 0;
}
