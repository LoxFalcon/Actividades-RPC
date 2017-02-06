#include<bits/stdc++.h>
#define MAX_R 501
#define MAX_C 501
#define INF 1000000000
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
int R,C,N;
int data[3][MAX_R][MAX_C]={0};
int orI[5], orJ[5];
vi dist;
int id(int xi, int xj){
    return (xi*C)+xj;
}
int dijkstra(int indOrigen){
    dist.assign(R*C,INF);
    dist[id(orI[indOrigen],orJ[indOrigen])] = 0;
    priority_queue<iii,vector<iii>,greater<iii> > pq; 
    pq.push(iii(0,ii(orI[indOrigen],orJ[indOrigen])));
    while(!pq.empty()){
        iii front = pq.top(); pq.pop();
        int cost = front.first, xi = front.second.first, xj = front.second.second;
        //ii parFicticio = ii(xi,xj);
        int idX = id(xi,xj);
        if(/*dist.count(parFicticio)>0&&*/cost>dist[idX]) continue;
        if(xi==orI[indOrigen+1]&&xj==orJ[indOrigen+1]) return cost;
        int i1 = max(0,xi-data[1][xi][xj]), i2 = min(R-1,xi+data[1][xi][xj]);
        int j1 = max(0,xj-data[2][xi][xj]), j2 = min(C-1,xj+data[2][xi][xj]);
        for(int i=i1;i<=i2;i++){
            for(int j=j1;j<=j2;j++){
                int idNuevo = id(i,j);
                if(dist[idX]+data[0][xi][xj]<dist[idNuevo]){
                    dist[idNuevo] = dist[idX]+data[0][xi][xj];
                    pq.push(iii(dist[idNuevo],ii(i,j)));
                }
            }
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin>>R>>C>>N){
        for(int i=0;i<3;i++){
            for(int j=0;j<R;j++){
                for(int k=0;k<C;k++){
                    cin>>data[i][j][k];
                }
            }
        }
        for(int i=0;i<N;i++){
            cin>>orI[i]>>orJ[i];
            orI[i]--; orJ[i]--;
        }
        //cout<<"Respuestas: ";
        for(int i=0;i<N-1;i++){
            if(i) cout<<' ';
            cout<<dijkstra(i);
        }
        cout<<'\n';
    }
    return 0;
}