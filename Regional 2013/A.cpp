#include <bits/stdc++.h>
#define MAXN 105
using namespace std;
char mapa[MAXN][MAXN];
int hor[MAXN][MAXN];
int ver[MAXN][MAXN];
vector<vector<int> > adjList;
vector<bool> visitados;
vector<int> match;
int aug(int u){
    if(visitados[u]) return 0;
    visitados[u] = 1;
    for(int i=0;i<adjList[u].size();i++){
        int r = adjList[u][i];
        if(match[r]==-1||aug(match[r])){
            match[r] = u;
            return 1;
        }
    }
    return 0;
}
int main(){
    int N;
    while(cin >> N){
        for(int x=0;x<N;x++){
            cin >> mapa[x];
        }
        memset(hor, 0,sizeof hor);
        memset(ver,0, sizeof ver);
        int colorF = 1;
        int colorC;
        for(int f=0;f<N;f++){
            for(int c=0;c<N;c++){
                if(mapa[f][c] != 'X' && !ver[f][c]){
                    for(int z = f; mapa[z][c] != 'X' && z < N; z++){
                        ver[z][c] = colorF;
                    }
                    colorF++;
                }
            }
        }
        colorC = colorF;
        for(int f=0;f<N;f++){
            for(int c=0;c<N;c++){
                if(mapa[f][c] != 'X' && !hor[f][c]){
                    for(int z = c; mapa[f][z] != 'X' && z < N; z++){
                        ver[f][z] = colorC;
                    }
                    colorC++;
                }        
            }
        }
        int MCBM = 0;
        adjList.assign(colorC-1, vector<int>());
        for(int f=0;f<N;f++){
            for(int c=0;c<N;c++){
                if(mapa[f][c] != 'X'){
                    adjList[ver[f][c]-1].push_back(hor[f][c]-1);
                    adjList[hor[f][c]-1].push_back(ver[f][c]-1);
                }
            }
        }
        match.assign(colorC-1, -1);
        for(int i=0;i<colorF-1;i++){
            visitados.assign(colorC-1,false);
            MCBM+=aug(i);
        }
        cout<<MCBM<<'\n';
    }
}