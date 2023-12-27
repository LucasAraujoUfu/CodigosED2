#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n;
	string s;
	scanf("%d",&n);
	cin.ignore();
	cin.ignore();
	for(int i=0;i<n;i++){
		if(i!=0)cout<<endl;
		int t=0;
		map<string,int> M;
		while(getline(cin,s)){
			if(s=="")break;
			M[s]++;
			t++;
		}
		for(map<string,int>::iterator it=M.begin(); it!=M.end(); ++it){
			cout<<it->first<<" ";
			printf("%.4lf\n",((double)it->second/t)*100);
		}
	}
	return 0;
}
