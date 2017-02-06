#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
int N;
vvi adjList;
vi run;
vb vis;
map<string,int> names;
bool dfs(int u){
    vis[u] = true;
    for(int i=0;i<(int)adjList[u].size();i++){
        int v = adjList[u][i];
        if(run[v]==-1){
            run[v] = run[u];
            bool hijo = dfs(v);
            if(!hijo) return false;
        }else if(run[v]==run[u] && vis[v]){
            return false;
        }
    }
    vis[u] = false;
    return true;
}
int main(){
    int ind1,ind2;
    string a,b; char c;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a>>c>>b;
        if(names.count(a)==0){
            int x = names.size();
            names[a] = x;
            adjList.push_back(vi());
        }
        if(names.count(b)==0){
            int x = names.size();
            names[b] = x;
            adjList.push_back(vi());
        }
        ind1 = names[a];
        ind2 = names[b];
        if(c=='<'){
            adjList[ind2].push_back(ind1);
        }else{
            adjList[ind1].push_back(ind2);        
        }
    }
    bool possible=true;
    int ctd = names.size();
    run.assign(ctd,-1);
    vis.assign(ctd,false);
    int count = 0;
    for(int i=0;i<names.size();i++){
        if(run[i]==-1){
            run[i] = count++;
            if(!dfs(i)){
                possible = false;
                break;
            }
        }
    }    
    if(possible) cout<<"possible"<<'\n';
    else cout<<"impossible"<<'\n';
    return 0;
}