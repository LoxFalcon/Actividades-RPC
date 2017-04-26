#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
#define endl '\n'
#define MAX 1000010

ll cualMax(ll n){
    ll i=0,bit=1;
    if(n==1){ return 0; }
    while(bit<n){
        bit<<=1;
        i++;
    }
    if(bit!=n){ i--; }
    return i;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in2.txt","r",stdin);
    //cout<<(1LL<<33)<<endl;
    ll t,n;
	cin>>t;
	//cout<<"t:"<<t<<endl;
	while(t--){
		cin>>n;
		ll bitmax=cualMax(n),complete=32,mas=1LL<<31,mod;
		bool esta[32];
		for(int i=0;i<32;i++){ esta[i]=false; }
		//bitmax--;
        //cout<<"bitmax: "<<cualMax(n)<<endl;
        //if(bitmax<31){ cout<<"no\n"; continue; }
		for(int i=0;i<32;i++){
            mod=n%32;
            if(esta[mod]==false){
                esta[mod]=true;
                //if(mod==5)cout<<"aqui"<<endl;
                complete--;
            }
            //cout<<" - "<<mod<<endl;
            if(complete==0){ break; }
            //cout<<n<<" - "<<mod<<endl;

            if(n%2==1){
                n>>=1LL;
                n+=mas;
            }else{
                n>>=1LL;
            }

		}
		//for(int i=0;i<8;i++){ cout<<esta[i]<<" "; }
		//cout<<endl;
		///*
		if(complete==0)
            cout<<"yes\n";
        else
            cout<<"no\n";
        //*/
	}
	return 0;
}
