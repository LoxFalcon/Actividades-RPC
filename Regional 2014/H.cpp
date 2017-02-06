#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B,i,j, ady, costo;
    string line;
    //int pre[5005], pr;

    while(cin>>A>>B){
        cin>>line;
        /*pr=0;
        for(i=0;i<line.length();i++){
            pre[0]=pr;
            if(line[i]=='B')pr++;
            cout<<pre[0]<<" ";
        }*/
        i=0;
        j=line.length()-1;
        costo=0;
        while(i<j){
            while(line[i]=='B')i++;
            while(line[j]=='W')j--;
            ady= (j-i)*B;
            if(A<=ady){
                costo+=A;
            }else{
                costo+=ady;
            }
        }
        cout<<costo<<"\n";
    }
    return 0;
}