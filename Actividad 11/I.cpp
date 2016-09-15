#include <bits/stdc++.h>
#define MAXN 50005
using namespace std;
int A[MAXN], B[MAXN], C[MAXN];

int main(){
    int N;
    cin >> N;
    for(int x=0;x<N;x++) cin >> A[x];
    int cont = 1,contH = 1;
    for(int x=0,y=N-1;x<N && y >= 0;x++, y--){
        if(A[x] < cont) cont = A[x];
        B[x] = cont++;
        if(A[y] < contH) contH = A[y];
        C[y] = contH++;
    }
    int mini;
    int maxi = -1;
    for(int x=0;x<N;x++){
        mini = min(B[x], C[x]);
        maxi = max(maxi, mini);
    }
    cout << maxi << "\n";
}