#include<bits/stdc++.h>
#define LLI long long int
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T,n;
	LLI a,b;
	cin>>T;
	while(T--){
		cin>>n>>a>>b;
		int lowPot = 0;
		while((a&1) == 0 && (b&1) == 0){
			lowPot++;
			a>>=1;
			b>>=1;
		}
		cout<<(n-lowPot)<<'\n';
	}
	return 0;
}
