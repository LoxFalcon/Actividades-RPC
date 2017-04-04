#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
#define endl '\n'
#define MAX 1000

bool criba[MAX];
ll i,j;
vi primos;

void sieve(){
	for(i=2;i<MAX;i++)if(!criba[i]){
		primos.push_back(i);
		for(j=i*i;j<MAX;j+=i)
			criba[i]=true;		
	}
	
}

ll sumDiv(ll n){
	ll j=0, p=primos[j],ans=1;
	while(p*p<=n && p){
		ll e=0;
		while(n%p==0){ n/=p; e++; }
		ans*=((ll)pow((double)p, e+1.0)-1)/(p-1);
		p=primos[++j];
	}
	if(n!=1) ans*=((ll)pow((double)n, 2.0)-1)/(n-1);
	return ans;
}

int main(){
	//freopen("in.txt","r",stdin);
	sieve();
	int t;
	ll n,d;
	cin>>t;
	//cout<<"t:"<<t<<endl;
	while(t--){
		cin>>n;
		d=sumDiv(n);
		d-=n;
		//cout<<"d>: "<<d<<endl;
		if(d<n)
			cout<<"deficient"<<endl;
		else if (d>n)
			cout<<"abundant"<<endl;
		else
			cout<<"perfect"<<endl;
	}
	return 0;
}
