#include<bits/stdc++.h>
#define MAX_N 100005
#define LLI long long int
using namespace std;
int arr[MAX_N];
int T,N,K;
LLI sum,sumT,r;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("in.txt","r",stdin);
	cin>>T;
	while(T--){
		sum=sumT=0;
		cin>>N>>K;
		bool band = false;
		for(int i=0;i<N;i++){
			cin>>arr[i];
			sum+=arr[i];
			
		}
		cout<<"Yes.\n";
	}
	
	return 0;
}
/*
2
1 5
1
3 11
1 5 10
*/
