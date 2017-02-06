#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
vvii adjList;
vi amigo;
int N,F,maxPath=-1,mst;
int dfs(int u, int depth){
    if(amigo[u]) maxPath = max(maxPath,depth);
    int amigs = amigo[u];
    for(int i=0;i<adjList[u].size();i++){
        int tmp = dfs(adjList[u][i].first,depth+adjList[u][i].second);
        if(tmp>0){
            mst+=adjList[u][i].second;
            amigs+=tmp;
        }        
    }
    return amigs;
}

int main(){
    int A,B,C;
    while(cin>>N>>F){
        adjList.assign(N,vii());
        amigo.assign(N,false);
        for(int i=1;i<N;i++){
            cin>>A>>B>>C;
            adjList[A-1].push_back(ii(B-1,C));
        }
        for(int i=0;i<F;i++){
            cin>>A;
            amigo[A-1]=true;
        }
        mst = 0; maxPath=-1;
        dfs(0,0);
        cout<<(mst-maxPath)<<'\n';
    }
    return 0;
}