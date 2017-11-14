#include<bits/stdc++.h>
#define MAX_N 1001
#define MAX_MOD 1001
#define NOT -2
using namespace std;
typedef pair<int,int> ii;
int nextMod[MAX_N][MAX_MOD]={0};
int memo[MAX_N][MAX_MOD]={0};
string S;
int MOD,N;
int createNum2(int i, int mod){	
	if(memo[i][mod]!=-1) return memo[i][mod];
	if(i==N){
		if(mod==0) return 0;
		else return NOT;
	}
	int ini = 0, end = 9;
	if(S[i]!='?'){
		ini = end = (S[i]-'0');
	}else if(i == 0){
		ini = 1;
	}
	while(ini<=end){
		int r = (((mod*10)%MOD)+(ini%MOD))%MOD;
		if(createNum2(i+1,r)!=NOT){
			nextMod[i][mod] = r;
			return memo[i][mod] = ini;
		}
		ini++;
	}
	return memo[i][mod] = NOT;
}
void resetTable(){
	memset(memo,-1,sizeof memo);
	memset(nextMod,-1,sizeof nextMod);
}
void printNum(){
	int i=0, j=0;
	while(memo[i][j]!=-1){
		cout<<memo[i][j];
		j = nextMod[i][j];
		i++;
	}
	cout<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>S>>MOD;
	N = S.size();
	resetTable();
	//int digi = createNum2(0,0);
	if(createNum2(0,0)!=NOT){
		printNum();
	}else{
		cout<<"*\n";
	}
	return 0;
}
