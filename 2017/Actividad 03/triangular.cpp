#include<bits/stdc++.h>
#define LLI long long int
#define LD long double
using namespace std;
LLI calcularX(LLI x){
	LLI n = floor((-1 + sqrt((LD)1.0+(x<<2)))/2.0);
	LLI piso = n*(n+1);
	LLI delta = x-piso;
	LLI tam = (n+1)<<1;
	LLI res;
	int signo = 0;
	if(n%2==0) signo = -1;
	else signo = 1;
	LLI mitad = tam>>1;
	LLI diff = abs(mitad-delta);
	return signo*(mitad-diff);		
}

LLI calcularY(LLI x){
	if(x<3) return 0;
	x-=3;
	LLI n = floor((-1.0 + sqrt((LD)1.0+x))/2.0);
	LLI piso = 4*n*(n+1);
	LLI delta = x-piso;
	LLI tam = (n+1)<<3;
	LLI mitad = (tam>>1)-2;
	if(delta>=mitad) return -(n+1);
	else{
		LLI mitadcita = mitad/2-1;
		LLI diff = (n+1)-abs(mitadcita-delta);
		return diff;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("in.txt","r",stdin);
	int T,ni; LLI N;
	cin>>T;
	while(T--){
		cin>>N;
		cout<<calcularX(N-1)<<' '<<calcularY(N)<<'\n';//<<' '<<calcularY(N-1)<<'\n';
	}
	return 0;
}
