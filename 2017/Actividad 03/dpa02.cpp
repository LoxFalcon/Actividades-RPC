#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
#define endl '\n'
#define MAX 1000010

bool criba[MAX];
ll i,j;
vi primos;

void sieve(){
	for(i=2;i<MAX;i++)if(!criba[i]){
		primos.push_back(i);
		//divs[i]=1+i;
		for(j=i*i;j<MAX;j+=i)
			criba[j]=true;		
	}
	/*for(j=0;j<10;j++)
		cout<<primos[j]<<" ";
	cout<<endl;
	cout<<primos.size()<<endl;*/	
}

ll pow(ll n, ll e){
	ll ans=1;
	while(e--){
		ans*=n;
	}
	return ans;
}

int sumDiv(ll n){
	ll j=0, p=primos[j],ans=1, on=n;
	while(p*p<=n && p){
		ll e=0;
		if(n%p==0){
			while(n%p==0){ n/=p; e++; }
			ans*=(pow(p, e+1)-1)/(p-1);
			if((ans-on)>on){ return 1; }
		}
		p=primos[++j];
	}
	if(n!=1) ans*=(pow(n, 2)-1)/(n-1);
	if((ans-on)>on){ return 1; }
	ans-=on;
	//cout<<n<<" sumdiv= "<<ans<<endl;
	if(ans==on){ return 0; }
	else if(ans<on){ return -1; }
	else { return 1; } 
	//return ans;
}

void pre(){
	
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<pow(5,3)<<endl;
	//freopen("in.txt","r",stdin);
	sieve();
	int b;
	ll n,d,t;
	cin>>t;
	while(t--){
		cin>>n;
		b=sumDiv(n);
		if(b==-1)
			cout<<"deficient"<<endl;
		else if (b==1)
			cout<<"abundant"<<endl;
		else
			cout<<"perfect"<<endl;
	}
	return 0;
}
