#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define _F first
#define _S second
#define MAX_N 100001
#define LOG_TWO_N 17
#define MAX_R 200005
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> 	vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
vvii adjList; //adjacency list to store MST
viii edges;
int N,R,Q, idx;
int H[MAX_N], E[MAX_N<<1], L[MAX_N<<1], A[MAX_N];
map<ii,int> id;
bitset<MAX_N> vis;
unordered_map<int,int> inMst;
class UnionFind{
	private:
		vi p, rank;
		int numSets;
	public:
		UnionFind(int N){
			rank.assign(N,0);
			p.assign(N,0);
			numSets = N;
			for(int i=0;i<N;i++){
				p[i] = i;
			}
		}
		int getNumSets(){
			return numSets;
		}
		bool isSameSet(int i, int j){
			return findSet(i) == findSet(j);
		}
		int findSet(int i){
			return (p[i] == i) ? i : (p[i]=findSet(p[i]));
		}
		
		void unionSet(int i, int j){
			if(!isSameSet(i,j)){
				int x = findSet(i), y = findSet(j);
				numSets--;
				if(rank[x]>rank[y]) p[y]=x;
				else{
					p[x] = y;
					if(rank[x] == rank[y]) rank[y]++;
				}
			}
		}
};

void dfs(int cur, int depth, int cost){
	vis[cur] = true;
	H[cur] = idx;
	A[idx] = cost;
	E[idx] = cur;	
	L[idx++] = depth;
	for(int i=0;i<adjList[cur].size();i++){
		ii x = adjList[cur][i];
		if(vis[x._F]) continue;
		dfs(x._F,depth+1,x._S);
		E[idx] = cur;
		A[idx] = cost;
		L[idx++] = depth;
	}
}

class RMQ { // Range Maximum Query
	private:
		int SpT[MAX_N][LOG_TWO_N];
	public:
		RMQ(int n) {
			for (int i = 0; i < n; i++) {
				SpT[i][0] = i;
			}
			for (int j = 1; (1<<j) <= n; j++)
				for (int i = 0; i + (1<<j) - 1 < n; i++)
					if (A[SpT[i][j-1]] >= A[SpT[i+(1<<(j-1))][j-1]])
						SpT[i][j] = SpT[i][j-1];
					else
						SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
		}
		int query(int i, int j) {
			if(i>j) swap(i,j);
			int k = (int)floor(log((double)j-i+1) / log(2.0)); // 2^k <= (j-i+1)
			if (A[SpT[i][k]] >= A[SpT[j-(1<<k)+1][k]])
				return SpT[i][k];
			else 
				return SpT[j-(1<<k)+1][k];
		}
};

RMQ *rmq;

void buildRMQ(){
	idx = 0;
	memset(H,-1,sizeof(H));
	dfs(0,0,-1);
	rmq = new RMQ(N);
}

int main(){
	cin>>N>>R;
	UnionFind UF(N);
	adjList.assign(N,vii());
	for(int i=0;i<R;i++){
		int a,b,c;
		cin>>a>>b>>c; a--; b--;
		edges.PB(MP(c,MP(a,b)));
	}
	sort(edges.begin(),edges.end());
	int MST = 0;
	for(int i=0;i<edges.size();i++){
		iii e = edges[i];
		int C = e._F, u = e._S._F, v = e._S._S;
		id[MP(u,v)] = i;
		if(!UF.isSameSet(u,v)){
			MST+=C;
			UF.unionSet(u,v);
			inMst[i] = true;
			adjList[u].PB(MP(v,C));
			adjList[v].PB(MP(u,C));
		}
	}
	buildRMQ();
	cin>>Q;
	cout<<"MST: "<<MST<<'\n';
	for(int i=0;i<Q;i++){
		int a,b;
		cin>>a>>b; a--; b--;
		int x = id[MP(a,b)];
		if(inMst.count(x)>0){
			cout<<MST<<'\n';
		}else{
			cout<<H[a]<<' '<<H[b]<<'\n';
			int y = rmq->query(H[a]+1,H[b]);
			cout<<A[y]<<'\n';
			cout<<"HIGHEST: "<<y;
			cout<<"res: "<<(MST-A[y]+edges[x]._F)<<'\n';			
			
		}
	}
	return 0;
}
