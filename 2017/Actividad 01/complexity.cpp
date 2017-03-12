#include <bits/stdc++.h>
using namespace std;
int frec[26];
set<char> s;
int main(){
    string linea;
    cin >> linea;
    memset(frec, 0, sizeof frec);
    for(int x=0;x<linea.size();x++){
        frec[linea[x] - 'a']++;
        s.insert(linea[x]);
    }
    int com = s.size();
    int i = 0;
    int ac = 0;
    sort(frec, frec+26);
    while(com > 2){
        if(frec[i] > 0){
            com--;
            ac+=frec[i];
        }
        i++;

    }
    cout << ac << "\n";
}
