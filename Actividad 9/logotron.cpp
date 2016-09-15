#include<bits/stdc++.h>
int matAdy[16][16]={0};
//En matAdy[i][i] estará el "color" con el que se pintó
int n,m;
using namespace std;
typedef vector<int> vi;
bitset<16> visited;
class UnionFind {
	private:
		  vi p, rank, setSize;
		  int numSets;
	public:
	  
	  UnionFind(int N) {
	    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
	    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
	  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	  void unionSet(int i, int j) { 
	    if (!isSameSet(i, j)) { numSets--; 
	    int x = findSet(i), y = findSet(j);
	    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
	    else                   { p[x] = y; setSize[y] += setSize[x];
	                             if (rank[x] == rank[y]) rank[y]++; } } }
	  int numDisjointSets() { return numSets; }
	  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
UnionFind *UF;
void wrongFlood(int u){
	//if(visited[u]) return;
	//visited[u] = true;
	matAdy[u][u] = -1;
	for(int i=0;i<n;i++){
		if(i!=u&&matAdy[u][i]!=0&&!visited[i]){
			visited[i] = true;
			wrongFlood(i);
		}
			
	}
}
int valid(int u, int color){
	matAdy[u][u] = color;
	visited[u] = true;
	int res=1;
	for(int i=0;i<n;i++){	
		if(i!=u&&matAdy[u][i]!=0){ //hay arista			
			if(visited[i]){ //Visitado
				if(matAdy[i][i]==-1 || (UF->isSameSet(u,i)&&((color==1&&matAdy[i][i]!=matAdy[u][i]) || //No fue visitado previamente y ten�a -1, o ya fue "pintado" y no cuadra :'v
				   						(color==2&&matAdy[i][i]==matAdy[u][i])))){
					res = false;
				}else{
					if(!UF->isSameSet(u,i)){
						res = 0;
					}
					//UF->unionSet(u,i);
					//res = 0;
				}
			}else{ //No visitado
				int newColor;
				if(color==1){
					newColor=matAdy[u][i];
				}else{
					newColor = (matAdy[u][i]==1) ? 2 : 1; //Se invierte
				}
				UF->unionSet(u,i);
				res = valid(i,newColor);				
			}
			if(!res){
				wrongFlood(u);
				return res;
			}			
		}
	}
	return true;	
}
void clearMat(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			matAdy[i][j] = 0; //0 = no hay conexión
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,x,y; char type;
	cin>>t;
	for(int caso=1;caso<=t;caso++){
		cin>>n>>m;
		clearMat();
		for(int i=0;i<m;i++){
			cin>>x>>y>>type;
			if(type=='T'){
				matAdy[x-1][y-1] = 1; //Tautobot
			}else{ 
				matAdy[x-1][y-1] = 2; //Contradicticon
			}
		}
		visited.reset();
		UF = new UnionFind(n);
		//int ways=0;
		bool res;
		for(int i=0;i<n;i++){
			res = valid(i,1);
			if(!res)	break;	
		}
		int ctd = UF->numDisjointSets();
		int ways = res ? (1<<ctd) : 0;
		cout<<"Case #"<<caso<<": "<<ways<<'\n';
	}
	return 0;
}
