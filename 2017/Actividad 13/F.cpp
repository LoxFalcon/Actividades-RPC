#include<bits/stdc++.h>
#define MP make_pair
#define MAX_N 5001
using namespace std;
typedef pair<int,int> ii;
int **hm;
int arr[MAX_N]={0};
int longPalin(int l, int r){
	if(hm[l][r]!=-1) return hm[l][r];
	if(l==r){
		return hm[l][r] = 1; 
	}
	if(l+1==r){
		if(arr[l]==arr[r]){
			return hm[l][r] = 2;
		}else{
			return hm[l][r] = 1;
		}
	}
	
	if(arr[l]==arr[r]){
		return hm[l][r] = longPalin(l+1,r-1)+2;
	}else{
		return hm[l][r] = max(longPalin(l+1,r),longPalin(l,r-1));
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	hm = new int*[MAX_N];
	for(int i=0;i<MAX_N;i++){
		hm[i] = new int[MAX_N];
	}
	int N;
	while(cin>>N){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				hm[i][j] = -1;
			}
			cin>>arr[i];
		}
		int ret = longPalin(0,N-1);
		cout<<(ret>>1)<<'\n';
	}
	return 0;
}
