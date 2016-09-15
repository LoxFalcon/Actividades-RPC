#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		bool valido=true;
		int ant=0,x;
		for(int i=0;i<5;i++){
			cin>>x;
			if(i>0){
				if(ant+1!=x){
					valido=false;
				}
			}
			ant = x;
		}
		if(valido){
			cout<<"Y\n";
		}else{
			cout<<"N\n";
		}
	}
	return 0;
}
