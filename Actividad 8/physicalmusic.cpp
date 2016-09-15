#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
set<int> cdSingle;
int main(){
	int t,n,tmp;
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>tmp;
			if(i<tmp){
				cdSingle.insert(tmp);
			}
		}
		cout<<cdSingle.size()<<'\n';
		for(set<int>::iterator it=cdSingle.begin();it!=cdSingle.end();it++){
			cout<<*it<<'\n';
		}
		cdSingle.clear();
	}
	return 0;
}
