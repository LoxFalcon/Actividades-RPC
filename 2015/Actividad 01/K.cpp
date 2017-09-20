#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N,al,bob,tmp,ind;
	string str;
	while(cin>>N>>ind && N>0){
		for(int i=0;i<N;i++){
			cin>>tmp>>str;
		}
		int v = N-1;
		al = bob = v / 3;
		al += (v%3 >= 1) ? 1 : 0;
		bob += (v%3 == 2) ? 1 : 0;
		//cout<<al<<" "<<bob<<'\n';
		if(ind>bob && ind <= N-al){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}	
	}
	
	return 0;
}
