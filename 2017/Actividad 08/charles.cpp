#include<bits/stdc++.h>
#define MP make_pair
#define _F first
#define _S second
#define LLI long long int
#define INF 1000000000000000000
using namespace std;
typedef pair<long long int,long long int> ii;
typedef vector<LLI> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
vvii adjList;
int N,M; long long int x,X,sp;
void dijkstra(){
	vi dist(N,INF); dist[0]=0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(MP(0,0));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if(d>dist[u]) continue;
		for(int i=0;i<adjList[u].size();i++){
			ii v = adjList[u][i];
			if(dist[u]+v.second < dist[v.first]){
				dist[v.first] = dist[u]+v.second;
				pq.push(MP(dist[v.first],v.first));
			}
		}
	}
	sp = dist[N-1];
}
bool posible(){
	vi dist(N,INF); dist[0]=0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(MP(0,0));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if(d>dist[u]) continue;
		for(int i=0;i<adjList[u].size();i++){
			ii v = adjList[u][i];
			if(v.second <= x && dist[u]+v.second < dist[v.first]){
				dist[v.first] = dist[u]+v.second;
				pq.push(MP(dist[v.first],v.first));
			}
		}
	}
	return dist[N-1] <= sp;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a,b,t,ma=-1;
	cin>>N>>M>>X;
	adjList.assign(N,vii());
	for(int i=0;i<M;i++){
		cin>>a>>b>>t;
		a--; b--;
		ma = max(t,ma);
		adjList[a].push_back(MP(b,t));
		adjList[b].push_back(MP(a,t));
	}
	dijkstra();
	sp = (sp*(1+(X/100.0)));
	
	long long int inf=0,sup=ma,aux;
	while(inf<=sup){
		x = (inf+sup)>>1;
		if(posible()){
			aux=x;
			sup=x-1;
		}else{
			inf=x+1;
		}	
	}
	cout<<aux<<'\n';
	return 0;
}
