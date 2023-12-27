#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>

using namespace std;

vector<int> m;

int maxSubSet(vector<int> v){
	m.resize(v.size());
	m[0] = 1;
	int max = 0;
	for(int i=0;i<(signed)v.size();i++){
		for(int j=0;j<i;j++){
			if(v[j]<v[i]){
				m[i] = fmax(m[i],m[j]+1);
			}
		}
		if(max<m[i]){
			max = m[i];
		}
	}
	return max;
}

int main(void){
	int n;
	scanf("%d",&n);
	getchar();
	getchar();
	for(int k=0;k<n;k++){
		vector<int> v;
		int l;
		while(true){
			string st;
			getline(cin,st);
			if(st=="")break;
			stringstream ss;
			ss<<st;
			ss>>l;
			v.push_back(l);
		}

		int max = maxSubSet(v);

		vector<int> seq = {-1};

		for(int i=1;i<(signed)m.size();i++){
			if(m[i-1] == m[i])seq.back() = i;
			if(m[i-1] < m[i]){
				seq.back() = i-1;
				seq.push_back(i);
			}
		}

		cout<<"Acertos: "<<max<<endl;

		for(int i=0;i<max;i++){
			printf("%d\n",v[seq[i]]);
		}
		//if(k!=n-1)cout<<endl;
	}
	return 0;
}
