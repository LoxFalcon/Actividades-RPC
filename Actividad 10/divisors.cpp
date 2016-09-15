#include<bits/stdc++.h>
#define MAX 500005
using namespace std;

typedef long long int lli;
int primos[MAX],p;

class Num{
	public:
	int fact[20];
	int pot[20], F;
	Num(){
		F=0;
	}
	void add(int b, int e){
		fact[F]=b;
		pot[F]=e;
		F++;
	}
	void imp(){
		if(F==-1){
			cout<<"no valido"; return ;
		}
		for(int i=0;i<F;i++)
			cout<<fact[i]<<"  "<<pot[i]<<", ";
	}
	Num resta(Num a, Num b){
		int i,j;
		Num r=a;
		for(i=0, j=0;i<a.F && j < b.F;){
			if(r.fact[i]==b.fact[j]){
				r.pot[i]-=b.pot[j];
				if(r.pot[i]<0){
					//cout<<"no1";
					r.F=-1; return r;
				}
				i++; j++;
			}else if(r.fact[i]<b.fact[j]){
				i++;
			} else j++;
		}
		if(j<b.F){
			//cout<<"no2";
			r.F=-1; return r;
		}
		return r;
	}
	lli sumDiv(int N){
		lli ans=1;
		for(int i=0;i<F;i++){
			ans*=((lli)pow(fact[i], pot[i]+1) - 1)/(fact[i]-1);
		}
		return ans;
	}
	lli sumaFicticia(int x,int i, int act){
		if(i>=F){
			return act*x;
		}
		lli r=0;
		for(int j=0;j<=pot[i];j++){
			r+=sumaFicticia(x,i+1,act * pow(fact[i], j));
		}
		return r;
	}
};
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

Num factoriza(int n){
	lli ID=0, PF= primos[ID], p;
	Num numero;
	while(PF*PF<=n){
		if(n%PF==0){
			p=0;
			do{
				p++;
				n/=PF;
			}while(n%PF==0);
			numero.add(PF, p);
		}
		PF=primos[++ID];
	}
	if(n!=1)numero.add(n,1);
	return numero;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	criba();
	int t, n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		Num a=factoriza(n);
		Num b=factoriza(k);
		//a.imp();
		//cout<<"sum div "<<a.sumDiv(n);
		//cout<<"\n";
		//b.imp();			
		//cout<<"\n*";
		if(k==1){
			cout<<"0\n";
			continue;
		}
		//cout<<"suma ficitica : "<<resta.sumaFicticia(k, 0,1)<<"\n";
		if(n%k==0){
			Num resta= a.resta(a,b);
			cout<<(a.sumDiv(n) - resta.sumaFicticia(k, 0,1))<<"\n";
		}else cout<<a.sumDiv(n)<<"\n";
//		resta.imp();
	}
	return 0;
}
