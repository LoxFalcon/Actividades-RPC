#include<bits/stdc++.h>
#define LLI long long int
using namespace std;
int nums[9];
LLI dp[8][101];
LLI ways(int i, int n){
	//printf("I %d, n %d\n",i,n);
	if(n==0) return 1;
	if(n<0 || i>7) return 0;
	if(dp[i][n]!=-1) return dp[i][n];
	int tops = n/nums[i];
	dp[i][n] = 0;//(n%nums[i]==0) ? 1 : 0;
	for(int z = 0; z<=tops;z++){
		dp[i][n] += ways(i+1,n-(nums[i]*z));
	} 
	//printf("Solutions [%d][%d] =  %lld\n",i,n,dp[i][n]); 
	return dp[i][n];
}
void resetDP(){
	for(int i=0;i<8;i++){
		for(int j=0;j<101;j++)
			dp[i][j]=-1;
	}
}
int main(){
	int n;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<9;j++){
			cin>>nums[j];
		}
		resetDP();
		LLI sol = ways(0,nums[8]);
		cout<<"Equation #"<<i<<": "<<sol<<'\n';
	}
	return 0;
}
