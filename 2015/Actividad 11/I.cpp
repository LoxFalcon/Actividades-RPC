#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define LLI long long int
#define _F first
#define _S second
using namespace std;
/*
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
int N = 2, M = 2,K;
ii size;
bitset<9> vis;
map<ii,LLI> sols;
map<ii,set<int> > valid;
vvii adjList;
void createEdges(){
	adjList.assign(9,vii());
	adjList[0].PB(MP(1,-1)); adjList[0].PB(MP(3,-1)); adjList[0].PB(MP(4,-1)); adjList[0].PB(MP(7,-1)); adjList[0].PB(MP(5,-1)); adjList[0].PB(MP(2,1));  adjList[0].PB(MP(6,3));  adjList[0].PB(MP(8,4));
	adjList[1].PB(MP(0,-1)); adjList[1].PB(MP(2,-1)); adjList[1].PB(MP(3,-1)); adjList[1].PB(MP(4,-1)); adjList[1].PB(MP(5,-1)); adjList[1].PB(MP(6,-1)); adjList[1].PB(MP(8,-1)); adjList[1].PB(MP(7,4));
	adjList[2].PB(MP(1,-1)); adjList[2].PB(MP(3,-1)); adjList[2].PB(MP(4,-1)); adjList[2].PB(MP(7,-1)); adjList[2].PB(MP(5,-1)); adjList[2].PB(MP(0,1));  adjList[2].PB(MP(6,4));  adjList[2].PB(MP(8,5));
	adjList[3].PB(MP(0,-1)); adjList[3].PB(MP(1,-1)); adjList[3].PB(MP(2,-1)); adjList[3].PB(MP(4,-1)); adjList[3].PB(MP(6,-1)); adjList[3].PB(MP(7,-1)); adjList[3].PB(MP(8,-1)); adjList[3].PB(MP(5,4));
	adjList[4].PB(MP(0,-1)); adjList[4].PB(MP(1,-1)); adjList[4].PB(MP(2,-1)); adjList[4].PB(MP(3,-1)); adjList[4].PB(MP(5,-1)); adjList[4].PB(MP(6,-1)); adjList[4].PB(MP(7,-1)); adjList[4].PB(MP(8,-1));
	adjList[5].PB(MP(0,-1)); adjList[5].PB(MP(1,-1)); adjList[5].PB(MP(2,-1)); adjList[5].PB(MP(4,-1)); adjList[5].PB(MP(6,-1)); adjList[5].PB(MP(7,-1)); adjList[5].PB(MP(8,-1)); adjList[5].PB(MP(3,4));	
	adjList[6].PB(MP(1,-1)); adjList[6].PB(MP(3,-1)); adjList[6].PB(MP(4,-1)); adjList[6].PB(MP(7,-1)); adjList[6].PB(MP(5,-1)); adjList[6].PB(MP(0,3));  adjList[6].PB(MP(2,4));  adjList[6].PB(MP(8,7));
	adjList[7].PB(MP(0,-1)); adjList[7].PB(MP(2,-1)); adjList[7].PB(MP(3,-1)); adjList[7].PB(MP(4,-1)); adjList[7].PB(MP(5,-1)); adjList[7].PB(MP(6,-1)); adjList[7].PB(MP(8,-1)); adjList[7].PB(MP(1,4));
	adjList[8].PB(MP(1,-1)); adjList[8].PB(MP(3,-1)); adjList[8].PB(MP(4,-1)); adjList[8].PB(MP(7,-1)); adjList[8].PB(MP(5,-1)); adjList[8].PB(MP(0,4));  adjList[8].PB(MP(6,7));  adjList[8].PB(MP(2,5));
	ii size = MP(1,1);
	valid[size].insert(0);
	size = MP(1,2);
	valid[size].insert(0); valid[size].insert(1);
	size = MP(1,3);
	valid[size].insert(0); valid[size].insert(1); valid[size].insert(2);
	size = MP(2,2);
	valid[size].insert(0); valid[size].insert(1); valid[size].insert(3); valid[size].insert(4);
	size = MP(2,3);
	valid[size].insert(0); valid[size].insert(1); valid[size].insert(2); valid[size].insert(3); valid[size].insert(4); valid[size].insert(5);
	size = MP(3,3);
	valid[size].insert(0); valid[size].insert(1); valid[size].insert(2); valid[size].insert(3); valid[size].insert(4); valid[size].insert(5); valid[size].insert(6); valid[size].insert(7); valid[size].insert(8);
}
LLI backtrack(int id,int count){
	if(count==K) 
		return 1;
	LLI res = 0;
	vis[id] = true;
	for(int i=0;i<adjList[id].size();i++){
		ii x = adjList[id][i];		
		if(valid[size].count(x._F) == 0 || vis[x._F] || (x._S != -1 && !vis[x._S])){
			continue;
		}
		char jeje = id+'0';
		res+=backtrack(x._F,count+1);
	}
	vis[id] = false;
	return res;
}
LLI procesar(){
	LLI sum = 0;
	
	for(set<int>::iterator it = valid[size].begin();it != valid[size].end();it++){
		int x = *it;
		for(int j=1;j<=N*M;j++){
			K = j;
			sum += backtrack(x,1);
		}
	}
	return sum;
}
int main(){
	createEdges();
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			N = i, M = j;
			if(N>M) swap(N,M);
			if(sols.count(MP(N,M))>0) continue;
			size = MP(N,M);
			LLI res = procesar();
			sols[MP(N,M)] = res;
		}
	}
	
	for(map<ii,LLI>::iterator it = sols.begin(); it!=sols.end();it++){
		ii u = it->first;
		LLI res = it->second;
		cout<<u._F<<" "<<u._S<<" = "<<res<<'\n';
	}
	
	return 0;
}*/

int sol[3][3]={{1,4,11},{4,64,1392},{11,1392,389497}};

int main(){
	int N,M,caso=1;
	
	while(cin>>N>>M, N>0){
		N--; M--;
		cout<<"Case #"<<(caso++)<<": "<<sol[N][M]<<'\n';
	}
	return 0;
}
