#include<bits/stdc++.h>
#define MP make_pair
#define _F first
#define _S second
#define PB push_back
using namespace std;
typedef pair<int,int> ii;
string s1, s2;
int N,M;
map<char,ii> coord;
int calc [16][16];
vector<string> dp[16][16];
void createAdj(){
	coord['q'] = MP(0,0);	coord['w'] = MP(0,1);
	coord['e'] = MP(0,2);	coord['r'] = MP(0,3);
	coord['t'] = MP(0,4);	coord['y'] = MP(0,5);
	coord['u'] = MP(0,6);	coord['i'] = MP(0,7);
	coord['o'] = MP(0,8);	coord['p'] = MP(0,9);
	
	coord['a'] = MP(1,0);	coord['s'] = MP(1,1);
	coord['d'] = MP(1,2);	coord['f'] = MP(1,3);
	coord['g'] = MP(1,4);	coord['h'] = MP(1,5);
	coord['j'] = MP(1,6);	coord['k'] = MP(1,7);
	coord['l'] = MP(1,8);
	
	coord['z'] = MP(2,0);	coord['x'] = MP(2,1);
	coord['c'] = MP(2,2);	coord['v'] = MP(2,3);
	coord['b'] = MP(2,4);	coord['n'] = MP(2,5);
	coord['m'] = MP(2,6);
}
void resetDp(){
	memset(calc,0,sizeof calc);
	for(int i=0;i<=N;i++){
		for(int j=0;j<=M;j++){
			dp[i][j].clear();
		}
	}
}
bool isAdj(char a, char b){
	ii u = coord[a], v = coord[b];
	int dx = abs(u._F-v._F);
	int dy = abs(u._S-v._S);
	return dx < 2 && dy < 2 && a != b;
}
bool func(int i, int j){
	if(calc[i][j] == 1){
		return true;
	}else if(calc[i][j] == -1){
		return false;
	}	
	if(i>= N && j>= M){ //ya se acabaron los strings
		dp[i][j].PB("");
		calc[i][j] = 1; //sí es posible
		return true;
	}	
	if(i>=N){ //se acabó el string y aún el usuario introdujo cosas
		calc[i][j] = -1;//no es posible...
		return false;
	}
	bool pos=false;	
	int a = i+1, b = j;
	if(func(a,b)){
		calc[i][j] = 1;
		pos = true;
		for(int x=0; x<dp[a][b].size(); x++){
			dp[i][j].PB('f'+dp[a][b][x]);
		}
	}	
	if(s1[i] == s2[j]){
		a = i+1; b = j+1;
		if(func(a,b)){
			pos = true;
			for(int x=0; x<dp[a][b].size(); x++){
				dp[i][j].PB('o'+dp[a][b][x]);
			}
		}
		
		if(j+1<M && isAdj(s2[j],s2[j+1])){
			a = i+1; b = j+2;
			if(func(a,b)){
				pos = true;
				for(int x=0;x<dp[a][b].size();x++){
					dp[i][j].PB('r'+dp[a][b][x]);
				}
			}
		}
	}
	if(isAdj(s1[i],s2[j])){
		a = i+1; b = j+1;
		if(func(a,b)){
			pos = true;
			for(int x=0;x<dp[a][b].size();x++){
				dp[i][j].PB('w'+dp[a][b][x]);
			}
		}
	}
	if(j+1<M && s2[j+1]==s1[i] && isAdj(s2[j],s2[j+1])){
		int a = i+1, b = j+2;
		if(func(a,b)){
			pos = true;
			for(int x=0;x<dp[a][b].size();x++){
				dp[i][j].PB('l'+dp[a][b][x]);
			}
		}
	}
	if(pos){
		calc[i][j] = 1;
	}else{
		calc[i][j] = -1;
	}
	return pos;	
}
void printAll(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<"PARA "<<i<<" "<<j<<'\n';
			for(int x=0;x<dp[i][j].size();x++){
				cout<<'\t'<<dp[i][j][x]<<'\n';
			}
		}
	}
}
int main(){
	createAdj();
	ios_base::sync_with_stdio(false); cin.tie(0);
	int TC;
	cin>>TC;
	cin.ignore();
	while(TC--){
		string line;
		getline(cin,s1);
		N = s1.length();
		getline(cin,s2);
		M = s2.length();
		resetDp();
		func(0,0);
		cout<<s1<<' '<<s2<<":\n";
		sort(dp[0][0].begin(),dp[0][0].end());
		for(int x=0;x<dp[0][0].size();x++){
			cout<<dp[0][0][x]<<'\n';
		}
		cout<<'\n';
	}
}
