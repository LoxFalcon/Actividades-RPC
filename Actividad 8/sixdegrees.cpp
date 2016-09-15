#include<cstdio>
#include<map>
#include<iostream>
#include<vector>
#include<bitset>
#include<queue>
#include<algorithm>
#define MAX 3001
#define INF 1000000000
#define _F first
#define _S second
#define MP make_pair
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<int> vi;
typedef vector<ii> 	 vii;
typedef vector<vii> vvii;
typedef vector<iii>  viii;
vvii adjList;
int minDisp,ctdTotal, totalDisp;
map<string,int> indexes;
short **memo;
bitset<MAX> bits;
int n;
void clearMatrix(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			memo[i][j] = 0;
		}
	}
}
void initMatrix(){	
	memo = new short*[MAX];
	for(int i=0;i<MAX;i++){
		memo[i] = new short[MAX]();
	}
}
void bfs(int s){
	vi dist(totalDisp,INF); dist[s] = 0;
	queue<int> q; 
	q.push(s);
	while(!q.empty()){
		int u = q.front(); q.pop();
		int size = adjList[u].size();
		for(int i=0;i<size;i++){
			ii v = adjList[u][i];
			if(dist[v._F]==INF){
				dist[v._F] = dist[u] + v._S;
				//cout<<"De s:"<<s<<" a v:"<<v._F<<" hay \t"<<dist[v._F]<<'\n';
				if(dist[v._F]>6){
					if(!bits[v._F]){
						bits[v._F] = true;
						ctdTotal++;
					}
					if(!bits[s]){
						bits[s] = true;
						ctdTotal++;
					}
				}
				/*if(dist[v._F]>1){
					adjList[s].push_back(MP(v._F,dist[v._F]));
					adjList[v._F].push_back(MP(s,dist[v._F]));
				}*/
				q.push(v._F);
			}
		}
	}
}
bool posible(){
//	cout<<"no mames";
	for(int i=0;i<totalDisp;i++){
//		cout<<"no mames";
		if(!bits[i]) 
			bfs(i);
		if(ctdTotal>minDisp) return false;
	}
	//cout<<"Total: "<<ctdTotal<<" minimo: "<<minDisp<<'\n';
	return true;
}
int main(){
	//initMatrix();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cout<<"que pedo";
	int t;
	string a,b;
	cin>>t;
	while(t--){
		cin>>n;
		//clearMatrix();
		for(int i=0;i<n;i++){
			cin>>a>>b;
		//	cout<<"Leemos a \""<<a<<"\" y b: \""<<b<<'\n';
			if(indexes.count(a)==0){ //No está registrado
				adjList.push_back(vii());
				int size = indexes.size();
				indexes[a] = size; // string a, index = size
			}
			if(indexes.count(b)==0){ //No está registrado
				adjList.push_back(vii());
				int size = indexes.size();
				indexes[b] = size; // string a, index = size
			}
			adjList[indexes[a]].push_back(MP(indexes[b],1));
			adjList[indexes[b]].push_back(MP(indexes[a],1));
		}
	//	cout<<"holi";
		totalDisp = indexes.size();
		minDisp = (double)totalDisp*0.05;
		ctdTotal = 0;
	//	cout<<"adios";
		if(posible()){
			cout<<"YES"<<'\n';
		}else{
			cout<<"NO"<<'\n';
		}		
		indexes.clear();
		adjList.clear();
		bits.reset();
	}
	return 0;
}
