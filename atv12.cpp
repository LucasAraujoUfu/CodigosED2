#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

typedef struct{
    int peso;
    int preco;
}produto;

vector<vector<int>> memo;

int maxKnap(vector<produto> p,int n,int tam){
	if(tam<=0)return 0;
	else if(memo[n-1][tam-1]==-1){
		if(n==1){
			if(tam-p[0].peso>=0)memo[n-1][tam-1] = p[0].preco;
			else memo[n-1][tam-1] = 0;
		}
		else{
			memo[n-1][tam-1] = fmax(maxKnap(p,n-1,tam),p[n-1].preco+maxKnap(p,n-1,tam-p[n-1].peso));
		}
	}
	return memo[n-1][tam-1];
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<produto> p(n);
        for(int j=0;j<n;j++){
            cin>>p[j].preco>>p[j].peso;
        }
        int g;
        cin>>g;
        int f[g]={0};
        for(int j=0;j<g;j++){
            cin>>f[j];
        }
        int tot=0;
        for(int j=0;j<g;j++){
            memo = vector<vector<int>>(p.size()+1,vector<int>(f[j]+1,-1));
            memo[0][0]=0;
            tot+=maxKnap(p,p.size(),f[j]);
            for(int k=0;k<p.size();k++){
				for(int l=0;l<f[j];l++)printf("%d ",memo[k][l]);
				cout<<endl;
			}
        }
        cout<<tot<<endl;
    }
    return 0;
}
