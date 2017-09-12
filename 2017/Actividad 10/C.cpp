#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
	int n,b,t,r,l,c,i;
	while(cin>>n>>b){
		c  = (1<<n)-b;
		l = (int)log2(c);
		//l--;
		
		i = 1<<(l-1);
		//cout<<"C: "<<c<<" l: "<<l<<" I: "<<i<<endl;
		cout<<"Instructions: ";
		if(c!=1)while(i){
			t=i&c;
			if(t==0)
				cout<<'L';
			else
				cout<<'R';
			i>>=1;
		}
		
		cout<<endl;
	}
	return 0;
}
