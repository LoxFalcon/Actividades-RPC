#include<bits/stdc++.h>
#define MAX_N 200002
using namespace std;
int arr[MAX_N]={0};
int pos[MAX_N]={0};
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N;
	while(cin>>N && N > 0){
		for(int i=1;i<=N;i++){
			cin>>arr[i];
			pos[arr[i]] = i;
		}
		int swaps=0;
		for(int i=1;i<=N;i++){
			if(arr[i]!=i){
				int j = pos[i];
				swap(pos[i],pos[arr[i]]);
				swap(arr[i],arr[j]);
				swaps++;
			}
		}
		cout<<swaps<<'\n';
	}
	return 0;
}
