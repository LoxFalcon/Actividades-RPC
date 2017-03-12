#include<bits/stdc++.h>
using namespace std;
int mapita[2][101][101]={0};
int dirI[9] = {0,0,1,1,1,0,-1,-1,-1};
int dirJ[9] = {0,1,1,0,-1,-1,-1,0,1};
int W,H,B;
typedef pair<int,int> ii;
int promedio(int i, int j, int idMatrix){
    int sum=0;
    for(int x=0;x<9;x++){
        int a = i+dirI[x], b=j+dirJ[x];
        if(a<0) a=H-1;
        if(a>=H) a=0;
        if(b<0) b=W-1;
        if(b>=W) b=0;
        sum+=mapita[idMatrix][a][b];
    }
    return sum;
}
int blurOne(int sour,int dest){
    set<int> distinct;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            mapita[dest][i][j] = promedio(i,j,sour);
            distinct.insert(mapita[dest][i][j]);
        }
    }
    return distinct.size();
}
int blur(){
    int source=0,maxi=-1;
    for(int i=0;i<B;i++){
        maxi = blurOne(source,1-source);
        source = 1-source;
    }
    return maxi;
}
int main(){
    cin>>W>>H>>B;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>mapita[0][i][j];
        }
    }
    cout<<blur()<<'\n';
    return 0;
}
