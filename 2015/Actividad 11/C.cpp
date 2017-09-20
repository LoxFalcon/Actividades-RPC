#include<bits/stdc++.h>
#define MP make_pair
#define _F first
#define _S second
#define MAX_V 21021 //1001*21
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
int N,M;
char mapa[21][1001]={0};
int dirI[4] = {0,1,0,-1};
int dirJ[4] = {1,0,-1,0};
vi match,vis;
ii getCoords(int id){
	int i = id/M;
	int j = id%M;
	return MP(i,j);	
}
int getID(int i, int j){
	return i*M+j;
}
bool isValid(int i, int j){
	return i>=0 && i<N && j >= 0 && j<M && mapa[i][j]!='#';
}
bool aug(int l){
	if(vis[l]) return false;
	vis[l] = true;
	for(int x=0;x<4;x++){
		ii coord = getCoords(l);
		int a = coord._F+dirI[x], b = coord._S+dirJ[x];
		if(isValid(a,b)){
			int id = getID(a,b);
			if(match[id] == -1 || aug(match[id])){
				match[id] = l;
				return true;
			}	
		}
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int caso = 1;
	while(cin>>N>>M, N>0){
		int valid = 0;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cin>>mapa[i][j];
				if(mapa[i][j]=='.'){
					valid++;
				}
			}
		}
		int MCBM = 0;
		match.assign(N*M,-1);
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				int id = getID(i,j);
				if(mapa[i][j]=='#') continue;	
				vis.assign(N*M,0);
				MCBM += aug(getID(i,j)) ? 1 : 0;
			}
		}
		int rest = valid-MCBM;
		int sol = rest/2 + rest%2;
		
		/*for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cout<<match[getID(i,j)]<<' ';
			}
				
			cout<<'\n';
		}*/
		cout<<"Case #"<<(caso++)<<": "<<sol<<'\n';
	}	
	
	return 0;
}
