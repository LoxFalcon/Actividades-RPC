#include<bits/stdc++.h>
#define MAX_N 51
#define MAX_M 51
#define INF 1000000000
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,ii> pii;
char mapa[MAX_N][MAX_M]={0};
int dist[MAX_N][MAX_M]={0};
int dirI[4] = {-1,0,1,0};
int dirJ[4] = {0,1,0,-1};
char dirs[] = "URDL";
string cmd;
int N,M;
void fillMatrix(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			dist[i][j] = INF;
		}
	}
}
bool esValido(int i, int j){
	return i>=0&&i<N&&j>=0&&j<M&&mapa[i][j]!='#';
}
int dijkstra(int sI, int sJ, int eI, int eJ){
	fillMatrix();
	dist[sI][sJ] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(make_pair(ii(0,0),ii(sI,sJ)));
	while(!pq.empty()){
		pii front = pq.top(); pq.pop();
		int d = front.first.first;
		int index = front.first.second;
		int i = front.second.first;
		int j = front.second.second;
		//printf("I AM IN (%d,%d) cost %d, index %d\n",i,j,d,index);
		if(i==eI && j==eJ) return d;
		if(d>dist[i][j]) continue;
		for(int x=0;x<4;x++){
			int a = i+dirI[x], b=j+dirJ[x], c=0; 
			if(esValido(a,b)){
				int c,delta; // c = cost in distance, can only be 0 or 1
						//delta = is the index delta, if we use a command then it increases
				if(index<cmd.size()&&dirs[x]==cmd[index]){
					c = 0; //doesn't cost us anything
					delta = 1; //the command index increases..
				}else{
					c = 1; //if it's not in the command... it costs 1
					delta = 0; //and the index doesn't increase					
				}
				pq.push(make_pair(ii(d+c,index+delta),ii(a,b)));
			}else{
				if(index<cmd.size()&&dirs[x]==cmd[index]){ //if its a command but it's not valid...
					pq.push(make_pair(ii(d,index+1),ii(i,j))); //we can still ignore it and not increase distance
					//we don't move because we ignore it
				}
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int rI,rJ,eI,eJ;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>mapa[i][j];
			if(mapa[i][j]=='R'){
				rI = i;
				rJ = j;
			}else if(mapa[i][j]=='E'){
				eI = i;
				eJ = j;
			}
		}
	}
	cin>>cmd;
	//cout<<"CMD: \""<<cmd<<"\" : "<<(cmd.size())<<'\n';
	cout<<dijkstra(rI,rJ,eI,eJ)<<'\n';
	return 0;
}
