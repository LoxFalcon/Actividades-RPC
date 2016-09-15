#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
typedef long long int lli;
int primos[MAX],p;
void criba(){
	bool crib[MAX];
	lli i,j;
	for(i=0;i<MAX;i++)
		crib[i]=true;
	p=0;
	for(i=2;i<MAX;i++){
		if(crib[i]){
			for(j=i*i;j<MAX;j+=i)
				crib[j]=false;
			primos[p++]=i;
		}
	}
}

lli eulerPhi(lli N){
	//cout<<"holi: "<<N<<'\n';
	lli PF_idx = 0, PF = primos[PF_idx], ans=N;
	//cout<<"holi2: "<<PF<<'\n';
	//cout<<"ope: "<<(PF*PF<=N)<<'\n';
	while(PF*PF <= N){
		//cout<<PF<<", ";
		if(N % PF == 0) {
			ans -= ans / PF;
		}

		while(N % PF == 0) N /= PF;

		PF = primos[++PF_idx];
	}
	if(N!=1) ans-=ans/N;
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	criba();
	//for(int i=0;i<100;i++)
		//cout<<primos[i]<<", ";
	//cout<<"\n";
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		lli res = eulerPhi(n);
		cout<<res<<'\n';
	}
	return 0;
}
