#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
bool A[26];
int M[26][26];
int T,N,raizN;
void limpia(){
    memset(A,0,sizeof A);
}
bool check(int x,int y){
    limpia();
    for(int i=x;i<x+raizN;i++){
        for(int j=y;j<y+raizN;j++){
            if(A[M[i][j]]) return false;
            A[M[i][j]] = 1;
        }
    }
    return true;
}
int main(){
    cin >> T;
    bool laCago = false;
    while(T--){
        laCago = false;
        cin >> N;
        for(int x=0;x<N;x++){
            limpia();
            for(int y=0;y<N;y++){
                cin >> M[x][y];
                if(A[M[x][y]]) laCago = true;
                A[M[x][y]] = 1;
            }
        }
        if(laCago){
            cout << "no\n"; continue;
        }
        for(int x=0;x<N;x++){
            limpia();
            for(int y=0;y<N;y++){
                if(A[M[y][x]]){
                    laCago = true;
                    break;
                }
                A[M[y][x]] = 1;
            }
            if(laCago) break;
        }
        if(laCago){
            cout << "no\n"; continue;
        }
        raizN = sqrt(N);
        for(int x=0;x<N;x+=raizN){
            for(int y=0;y<N;y+=raizN){
                laCago = !check(x,y);
                if(laCago) break;
            }
            if(laCago) break;
        }
        if(laCago){
            cout << "no\n";
        }else{
            cout << "yes\n";
        }
    }
}
