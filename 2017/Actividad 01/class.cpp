#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
vector<pair<string, string> > vp;

int main(){
    int T;
    cin >> T;
    string nombre,apellido;
    for(int x=0;x<T;x++){
        cin >> nombre >> apellido;
        vp.push_back(make_pair(apellido,nombre));
    }
    sort(vp.begin(),vp.end());
    for(int x=0;x<T;x++){
        cout << vp[x].second << " " << vp[x].first << "\n";
    }
}
