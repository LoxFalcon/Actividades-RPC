#include<bits/stdc++.h>
#define MAX_S 1001
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi adjList;
int N,K;
map<char,int> mapID;
int prefix[MAX_S][4]={0};
int suffix[MAX_S][4]={0};
int maxSol[MAX_S]={0};
void generate(){
	mapID['A'] = 0;
	mapID['C'] = 1;
	mapID['G'] = 2;
	mapID['T'] = 3;
}
bool validStrings(int i, int j){
	for(int x=0;x<4;x++){
		if(suffix[i][x] != prefix[j][x]) return false;
	}
	return true;
}
int longestPath(int u){
//	cout<<"ESTE "<<u<<'\n';
	if(maxSol[u]!=-1) return maxSol[u];
//	cout<<"CICLO\n";
	int maxi = 0;
	for(int x=0;x<adjList[u].size();x++){
		//cout<<"\t jeje\n";
		maxi = max(maxi,longestPath(adjList[u][x]));
	}
	return (maxSol[u] = maxi+1);	
}
int main(){
	string patron;
	generate();
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		memset(maxSol, -1, sizeof(maxSol));
		memset(prefix, 0, sizeof(prefix));
		memset(suffix, 0, sizeof(suffix));
		//cout<<"Hasta aquí bien\n";
		cin>>N>>K;
		adjList.assign(N+1,vi());
		cin>>patron;
		for(int i=0;i<patron.size();i++){
			suffix[0][mapID[patron[i]]]++;
		}
		for(int i=1;i<=N;i++){
			cin>>patron;
			//cout<<"CON ESTE STRING \""<<patron<<"\"\n";
			for(int x=0;x<patron.size();x++){
				//cout<<"CHECANDO "<<x<<'\n';
				int id = mapID[patron[x]];
				if(x<K){
					prefix[i][id]++;
				}
				if(x >= patron.size()-K){
					suffix[i][id]++;
				}
			}
			for(int j=0;j<i;j++){
				if(validStrings(j,i)){
					//cout<<"UNIENDO a "<<j<<" "<<i<<'\n';
					adjList[j].push_back(i);
				}
			}
		}
		cout<<longestPath(0)-1<<'\n';
		
	}
	return 0;
}
