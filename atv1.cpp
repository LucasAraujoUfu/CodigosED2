#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(void){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a=0,r=0,rb=1;
		scanf("%d%d",&a,&r);
		int m = (int)fmax((29*r),a);
		int n = (int)fmin((29*r),a);
		cout<<m<<" "<<n<<endl;
		int rp = m/n;
		int p =  m%n;
		printf("%d %d\n",rb+1,p+1);
	}
	return 0;
}

