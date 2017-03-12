#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
char mapita[502][502]={0};
vii negros;
int M,N,posI,posJ;
int dirI[4] = {0,1,0,-1};
int dirJ[4] = {1,0,-1,0};
bool esValido(int i, int j){
    return i>=0&&i<M&&j>=0&&j<N;
}
int bfs(){
    vector<int> dist;
    dist.assign(M*N,INF);
    dist[0] = 0;
    queue<iii> q;
    q.push(make_pair(0,ii(0,0)));
     while(!q.empty()){
        iii tmp = q.front(); q.pop();
        int d = tmp.first;
        int i = tmp.second.first;
        int j = tmp.second.second;
        int indTmp = i*N+j;
        if(i==M-1 && j==N-1){
            return dist[indTmp];
        }
        //cout<<"IJ"<<tmp.i<<" "<<tmp.j<<"'\n";
        for(int x=0;x<4;x++){
            int a = i+dirI[x]*(mapita[i][j]-'0');
            int b = j+dirJ[x]*(mapita[i][j]-'0');
            if(esValido(a,b)&&dist[a*N+b]==INF){
                dist[a*N+b] = dist[indTmp]+1;
                q.push(make_pair(dist[a*N+b],ii(a,b)));
            }
            }
        }
     return -1;
}
int main(){
    cin>>M>>N;
    for(int x=0;x<M;x++){
        cin>>mapita[x];
    }
    int movs = bfs();
    if(movs==-1){
        cout<<"IMPOSSIBLE\n";
    }else{
        cout<<movs<<'\n';
    }
}
