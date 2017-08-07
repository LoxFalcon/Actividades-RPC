#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	string S;
	cin>>T;
	while(T--){
		cin>>S;
		int l = S.size()-1;
		int res = 66;
		switch(S[l]){
			case '0':
				if(l == 0){
					res = 1;
				}else{
					res = 76;
				}
				break;
			case '5':
				res = 76;
				break;
			case '1':
				if(l>0){
					res = 16;
				}
				break;
			case '6':
				res = 16;
				break;
			case '2':
			case '7':
				res = 56;
				break;
			case '3':
			case '8':
				res = 96;
				break;
			case '4':
			case '9':
				res = 36;
				break;
		}
		cout<<res<<'\n';
	}
	return 0;
}
