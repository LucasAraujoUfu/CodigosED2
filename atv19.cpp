#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	string s;
	int ct=1;
	while(cin>>s){
		if(s=="fim")break;
		vector<vector<char>> stk;
		for(int i=0;i<(signed)s.size();i++){
			if(stk.size()==0){
				vector<char> v;
				stk.push_back(v);
			}
			if(stk[0].size()==0){
				stk[0].push_back(s[i]);
			}
			else{
				bool f=0;
				for(int j=0;j<(signed)stk.size();j++){
					if(stk[j].back()>=s[i]){
						stk[j].push_back(s[i]);
						f = 1;
						break;
					}
				}
				if(!f){
					vector<char> v;
					v.push_back(s[i]);
					stk.push_back(v);
				}
			}
		}
		cout<<"Caso "<<ct<<": "<<stk.size()<<endl;
		ct++;
	}
	return 0;
}
