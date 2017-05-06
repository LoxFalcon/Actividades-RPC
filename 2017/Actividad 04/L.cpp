#include<bits/stdc++.h>
using namespace std;
#define MAX 32632
#define endl '\n'
typedef long long ll;


bool criba[MAX];
ll i,j;
vector<int> primos;

void sieve(){
	for(i=2;i<MAX;i++)if(!criba[i]){
		primos.push_back(i);
		for(j=i*i; j<MAX; j+=i)
			criba[j]=true;		
	}
	/*for(i=0;i<10;i++)if(!criba[i]){
		cout<<primos[i]<<" ";
	}
	cout<<endl;*/
}

ll modPow(ll n, ll k){
	ll ans=1, i=1, t=n;
	while(i<=k){
		if(k&i){
			ans=(ans*t);
		}
		t=t*t;
		i<<=1;
	}
	return ans;
}

ll sumDiv(ll n){
	ll j=0, p=primos[0], ans=1;
	while(p*p<=n && p){
		ll e=0;
		while(n%p==0){
			n/=p; e++;
		}	
		ans*=(modPow(p, e+1)-1)/(p-1);
		p=primos[++j];
	}
	if(n!=1) ans*=(modPow(n, 2)-1)/(n-1);
	return ans;
}
/*
ll sumDiv2(ll n){
	ll j=0,p=primos[0], ans=n,jt;
	while(p*p<=n){
		if(__gcd(n, j)){
			ans+=j;
			jt=j+j;
			while(jt<=){
				ans+=jt;
				jt*=j;
			}	
		}
		j+=2;
	}
	return ans;
}
*/
ll EulerPhi(ll n){
	ll j=0, p=primos[0], ans=n;
	while(p*p<=n && p){
		if(n%p==0) ans-=ans/p;
		while(n%p==0){
			n/=p;
		}	
		p=primos[++j];
	}
	if(n!=1) ans-=ans/n;
	return ans;
}

int main(){
	//freopen("in.txt","r",stdin);
	sieve();
	//cout<<"b - "<<modPow(2, 5)<<endl;
	int t;
	ll n,summ,cop,sum,res;
	double r;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		cop=EulerPhi(n);
		//sum=sumDiv2(n);
		//res=n*(n+1)/2;
		//cout<<"N: "<<n<<endl;
		//cout<<"res: "<<res<<" sum: "<<sum<<endl;
		//res-=sum;
		//cout<<"res: "<<res<<" sum: "<<sum<<endl;
		r=(double)cop/(double)2;
		
		printf("%lld %.4f\n",cop,r);
	}
	return 0;
}
