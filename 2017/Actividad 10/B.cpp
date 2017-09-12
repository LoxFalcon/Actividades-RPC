#include<bits/stdc++.h>
#define MAX_N 1001
using namespace std;
int arr[MAX_N]={0};
int rev[MAX_N]={0};
int LIS[MAX_N]={0};
int LIS2[MAX_N]={0};
int N,T;
int maxSuperLIS(){
	for(int i=0;i<N;i++){
		LIS[i] = LIS2[i] = 1;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j] && LIS[i]<LIS[j]+1){
				LIS[i] = LIS[j]+1;
			}				
			if(rev[i]>rev[j] && LIS2[i]<LIS2[j]+1){
				LIS2[i] = LIS2[j]+1;
			}				
		}
	}
	int maxi = -1;
	for(int i=0;i<N;i++){
		maxi = max(maxi,LIS[i]+LIS2[N-i-1]-1);
	}
	return maxi;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>arr[i];
			rev[N-i-1] = arr[i];
		}
		cout<<maxSuperLIS()<<'\n';		
	}
	return 0;
}
