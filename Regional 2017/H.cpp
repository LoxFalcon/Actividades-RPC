#include<bits/stdc++.h>
using namespace std;

int main(){
	int A[3],B[3];
	for(int i=0;i<3;i++){
		cin>>A[i];
	}
	for(int i=0;i<3;i++){
		cin>>B[i];
	}
	int sum=0;
	for(int i=0;i<3;i++){
		sum+=max(B[i]-A[i],0);
	}
	cout<<sum<<'\n';
	return 0;
}
