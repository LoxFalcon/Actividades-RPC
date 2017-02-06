#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> compra;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N,G,S,R;
    while(cin >> N >> G){
        compra.clear();
        int puntos = 0;
        while(N--){
            cin >> S >> R;
            if(S > R) puntos+=3;
            else{
                if(S == R) puntos++;
                compra.push_back(R-S);
            }
        }
        sort(compra.begin(),compra.end());
        for(int x=0;x<compra.size();x++){
            if(compra[x] == 0){
                if(G > 0){
                    G--;
                    puntos+=2;
                }
            }
            if(compra[x] > 0 && G >= compra[x]+1){
                    G-=compra[x]+1;
                    puntos+=3;
            }else{
                if(compra[x] > 0 && G == compra[x]){
                        G = 0;
                        puntos++;
                        break;
                }
            }
        }
        cout << puntos << "\n";
    }
}
