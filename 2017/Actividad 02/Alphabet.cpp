#include<bits/stdc++.h>
using namespace std;
string in;
int lis[100];
int LIS(){
	for(int i=0;i<in.size();i++){
		lis[i]=1;
	}
	int maxi = -1;
	for(int i=0;i<in.size();i++){
		for(int j=0;j<i;j++){
			if(in[i]>in[j] && lis[i]<lis[j]+1){
				lis[i] = lis[j]+1;
				maxi = max(maxi,lis[i]);
			}
		}
	}
	return max(maxi,1);
}
int main(){
	cin>>in;
	int res = LIS();
	cout<<(26-res)<<'\n';
	return 0;
}
