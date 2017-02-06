#include<bits/stdc++.h>
using namespace std;
int first[5];
int main(){
    int tmp;
    while(cin>>first[0]){
        bool comp = true;
        for(int i=1;i<5;i++){
            cin>>first[i];
        }
        for(int i=0;i<5;i++){
            cin>>tmp;
            if(tmp==first[i]) comp=false;
        }
        if(comp) cout<<"Y\n";
        else cout<<"N\n";
    }
    
    return 0;
}