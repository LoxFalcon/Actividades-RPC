#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
#define endl '\n'
#define MAX 1000010

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    ll t,n;
	cin>>t;
	//cout<<"t:"<<t<<endl;
	while(t--){
		cin>>n;
		cout<<(n*(n+2))<<endl;
	}
	return 0;
}
