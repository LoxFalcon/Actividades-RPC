#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
double M[501];
double total;
long double por[501];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T,A,B;
    double pene;
    cin >> T;
    while(T--){
        total = 0;
        cin >> A >> B;
        for(int i=0;i<A;i++){
            M[i] = 0;
        }
        for(int x=0;x<B;x++){
            for(int y=0;y<A;y++){
                cin >> por[y];
            }
            cin >> pene;
            for(int y=0;y<A;y++){
                M[y]+= (por[y]*pene);
            }
            total+=pene;
        }
        int iMax1 = 0,iMax2 = 1;
        bool band = 0;
        for(int x=0;x<A;x++){
            por[x] = M[x];
            if(por[x] >= total* 50.1){
                band = 1;
                iMax1 = x;
                break;
            }
            if(M[x] > M[iMax1]){
                iMax2 = iMax1;
                iMax1 = x;
            }else if(M[x] > M[iMax2]){
                iMax2 = x;
            }
        }
        cout.precision(0);
        cout << fixed;
        if(band)
            cout << iMax1+1 << " " << M[iMax1]/100 << "\n";
        else{
            if(M[iMax1] == M[iMax2] && iMax1 > iMax2) swap(iMax1,iMax2);
            if(M[iMax1] < M[iMax2]) swap(iMax1,iMax2);
            cout << iMax1+1 << " " << M[iMax1]/100 << "\n";
            cout << iMax2+1 << " " << M[iMax2]/100 << "\n";
        }
        if(T) cout << "\n";
    }
}
