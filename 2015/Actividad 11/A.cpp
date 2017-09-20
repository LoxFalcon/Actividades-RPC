#include<bits/stdc++.h>
#define LLI long long int
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	LLI v1,d1,v2,d2;
	int caso=1;
	while(cin>>v1>>d1>>v2>>d2, v1 > 0){
		LLI m1 = d1*v2, m2 = d2*v1;
		cout<<"Case #"<<(caso++)<<": ";
		if(m1<m2){
			cout<<"You owe me a beer!\n";
		}else{
			cout<<"No beer for the captain.\n";
		}
		LLI den = (v1*v2)<<1;
		LLI div = __gcd(m1+m2,den);
		cout<<"Avg. arrival time: "<<((m1+m2)/div);
		if(div != den){
			cout<<'/'<<(den/div);	
		}
		cout<<'\n';
		
	}
	return 0;
}
