#include<bits/stdc++.h>
using namespace std;
int N;
struct Point{
    int x,y;
};
Point points[50000];

int main(){
    while(cin>>N){
        for(int i=0;i<N;i++){
            cin>>points[i].x>>points[i].y;
        }
        for(int i=0;i<N;i++){
            cout<<"Punto "<<(i+1)<<": ";
            for(int j=0;j<N;j++){
                if(i==j) continue;
                if(j) cout<<' ';
                cout<<hypot(points[i].x-points[j].x, points[i].y-points[j].y);
            }
            cout<<'\n';
        }
    }
    return 0;
}