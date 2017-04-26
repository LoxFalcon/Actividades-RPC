#include<bits/stdc++.h>
#define MAX_N 51
#define INF 1000000000
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,ii> pii;
typedef pair<ii,int> iii;
char mapa[MAX_N][MAX_N]={0};
int dist[MAX_N][MAX_N][MAX_N]={0};
int dirI[4] = {-1,0,1,0};
int dirJ[4] = {0,1,0,-1};
char dirs[] = "URDL";
map<char,int> cmdID;
string cmd;
int N,M;
void fillMatrix(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<=cmd.size();k++){
				dist[i][j][k] = INF;	
			}			
		}
	}
	cmdID['U'] = 0;
	cmdID['R'] = 1;
	cmdID['D'] = 2;
	cmdID['L'] = 3;
}
bool esValido(int i, int j){
	return i>=0&&i<N&&j>=0&&j<M&&mapa[i][j]!='#';
}
void print(){
	for(int k=0;k<=cmd.size();k++){
		cout<<"=========== K "<<k<< " ===============\n";
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++)
				cout<<dist[i][j][k]<<' ';
			cout<<'\n';
		}
		cout<<"======================================\n";
	}
}
int bfs(int sI, int sJ, int eI, int eJ){
	fillMatrix();
	//print();
	dist[sI][sJ][0] = 0;
	iii s = make_pair(make_pair(sI,sJ),0);
	queue<iii> q; q.push(s);
	while(!q.empty()){
		iii u = q.front(); q.pop();
		int i = u.first.first;
		int j = u.first.second;
		int k = u.second; //commands used
		//printf("ESTAMOS (%d,%d,%d)\n",i,j,k);
		for(int x=0;x<4;x++){
			int a = i+dirI[x], b=j+dirJ[x], c=0; 
			if(esValido(a,b)){
				int c,delta; // c = cost in distance, can only be 0 or 1
						//delta = is the index delta, if we use a command then it increases
				if(k<cmd.size()&&dirs[x]==cmd[k]){
					c = 0; //doesn't cost us anything
					delta = 1; //the command index increases..
				}else{
					c = 1; //if it's not in the command... it costs 1
					delta = 0; //and the index doesn't increase					
				}
				//printf("VIENDO (%d,%d,%d) = %d\n",a,b,k+delta,dist[a][b][k+delta]);
				if(dist[a][b][k+delta]==INF){					
					dist[a][b][k+delta] = dist[i][j][k]+c;
				//	printf("PUSHEANDO (%d,%d,%d) = %d\n",a,b,k+delta,dist[a][b][k+delta]);
					q.push(make_pair(ii(a,b),k+delta));	
				}				
				
			}else{
				if(k<cmd.size()&&dirs[x]==cmd[k]&&dist[i][j][k+1]==INF){ //if its a command but it's not valid...
					//printf("FICTICIO (%d,%d,%d)\n",i,j,k+1);
					dist[i][j][k+1] = dist[i][j][k];
					q.push(make_pair(ii(i,j),k+1)); //we can still ignore it and not increase distance
					//we don't move because we ignore it
				}
			}
		}
	}
	//print();
	int res = INF;
	for(int i=0;i<=cmd.size();i++){
		res = min(dist[eI][eJ][i],res);
	}
	return res;
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
	cout<<bfs(rI,rJ,eI,eJ)<<'\n';
	return 0;
}
