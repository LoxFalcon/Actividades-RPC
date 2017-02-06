#include <bits/stdc++.h>
#define MAXN 10000000000000000LL
using namespace std;
typedef long long ll;
ll unos[59];
ll powsito(int e){
    /*ll r = 1;
    /*for(int x=1;x<=e;x++){
        r*=2;
    }*/
    return ((ll)1)<<e;
}
void init(){
    ll pot = 1;
    ll ant = 0;
    ll act = 0;
    unos[0] = 1;
    for(int x=1;x<58;x++){
        act = (ant * 2 + pot);
        unos[x] = act + 1;
        ant = act;
        pot*=2;
    }
}
string n;
ll F(ll A){
    n.clear();
    while(A != 0){
        n.push_back((A%2) + '0');
        A/=2;
    }
    
    //reverse(n.begin(),n.end());
    int i = n.size();
    ll res = 0;
    ll c = 0;
    --i;
    do{
        if(n[i] == '1'){
            //cout << i << " " << c << " " << powsito(i) << " " << unos[i] << "\n"; 
            res+= (c* powsito(i) + unos[i]);
            c++;
        }
        
        --i;
    }while(i >= 0);
    return res;
}


int main(){
    init();
    ll A,B;
    while(cin >> A >> B){
        cout << F(B) - F(A-1) << "\n";
    }
}