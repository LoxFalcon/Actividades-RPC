#include<bits/stdc++.h>
#define MAX_N 100002
#define MOD 1000000007
#define LLI long long int
using namespace std;
LLI fact[MAX_N]={0};
void generate(){
	fact[0] = 1;
	for(int i=1;i<MAX_N;i++){
		fact[i] = (i*fact[i-1]) % MOD;
	}
}
int main(){
	generate();
	int T,N;
	cin>>T;
	while(T--){
		cin>>N;
		cout<<fact[N]-1<<'\n';
	}
	return 0;
}
