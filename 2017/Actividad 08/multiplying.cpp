#include<bits/stdc++.h>
#define LL long long int
using namespace std;
vector<int> coef;
void generateCoeficients(LL B, LL N){
	int s = min(B-1,N);
	for(int i=s;i>=2;i--){
		while(N%i == 0){
			coef.push_back(i);
			N/=i;
		}
	}
}
int main(){
	LL B,N;
	cin>>B>>N;
	generateCoeficients(B,N);
	for(int i=0;i<coef.size();i++){
		cout<<coef[i]<<'\n';
	}
	return 0;
}
