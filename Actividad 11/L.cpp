#include <bits/stdc++.h>
using namespace std;
int H,L;
int mapa[205][205];
set<int> colores;
int dx[4] = {1,0,-1,0}; //D,AB, I, ARR
int dy[4] = {0,1,0,-1}; 
bool valido(int i, int j){
    return i>=0 && i<H && j>=0 && j<L;
}
int dfs(int i, int j, int color){
    if(!valido(i,j)) return 0;
    if(mapa[i][j]!=color) return 0;
    mapa[i][j] = -1;
    int sum=1;
    for(int x=0;x<4;x++){
        sum+=dfs(i+dx[x],j+dy[x],color);
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>H>>L;
    for(int i=0;i<H;i++){
        for(int j=0;j<L;j++){
            cin>>mapa[i][j];
        }
    }
    int size = 1000000000; //INF
    int cont = 0;
    
    for(int i=0;i<H;i++){
        for(int j=0;j<L;j++){
            if(mapa[i][j]!=-1){
                size = min(size,dfs(i,j,mapa[i][j]));
                cont++;
            }                
        }
    }
    cout<<size<<'\n';
}