#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string linea;
    while(cin >> linea){
        int s;
        ll res = 0;
        for(int x=0;x<linea.length();x++){
            if(linea[x] >= '0' && linea[x] <= '9'){
                ll C[3];
                s = 0;
                C[0] = 1, C[1] = 0, C[2] = 0;
                while(linea[x] >= '0' && linea[x] <= '9'){
                    s = (s * 10 + linea[x] - '0')%3;
                    res+=C[s]; C[s]++;
                    x++;
                }
                x--;
            }
        }
        cout << res << "\n";
    }
}