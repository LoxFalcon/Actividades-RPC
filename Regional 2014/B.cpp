#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int A, B,i,j, ady;
    long long int costo;
    string line;
    //int pre[5005], pr;

    while(cin>>A>>B){
        cin>>line;
        i=0;
        j=line.length()-1;
        costo=0;
        while(i<j){
            while(line[i]=='B' &&i<j)i++;
            while(line[j]=='W' &&i<j)j--;
            ady= (j-i)*(A-B);
            //cout<<i<<" "<<j<<"\n";
            if(A<=ady){
                costo+=A;
            }else{
                costo+=ady;
            }
            //line[i]='B';
            i++; j--;
            //line[j]='W';
        }
        cout<<costo<<"\n";
    }
    return 0;
}