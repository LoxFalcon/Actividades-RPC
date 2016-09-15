#include<iostream>
#include<algorithm>
using namespace std;
int weights[100005]={0};
int t,m,w;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>m>>w;
		for(int i=0;i<m;i++) cin>>weights[i];
		sort(weights,weights+m);
		int ctd= 0,sum=0;
		for(int i=0;i<m;i++){
			sum+=weights[i];
			if(sum>w){
				break;
			}
			ctd++;
		}
		cout<<ctd<<'\n';
	}
	return 0;
}
