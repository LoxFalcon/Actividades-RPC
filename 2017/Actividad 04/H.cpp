#include<bits/stdc++.h>
#define LLI long long int
using namespace std;
vector<LLI> pots2;
void generar(){
	pots2.assign(51,1);
	for(int i=1;i<51;i++){
		pots2[i] = pots2[i-1]<<1;
	}
}

int main(){
	generar();
	LLI x;
	while(cin>>x && x>0){
		vector<LLI>::iterator it = lower_bound(pots2.begin(),pots2.end(),x);
		if(*it != x) it--;
		cout<<(1+2*(x-(*it)))<<'\n';
	}
	return 0;
}
