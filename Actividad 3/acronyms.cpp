#include<iostream>
using namespace std;
string A,B;
int main(){
    string linea1,linea2;
    while(getline(cin,linea1)){
        A = ""; B = "";
        getline(cin,linea2);
        A = linea1[0];
        for(int x=1;x<linea1.length();x++){
             if(linea1[x-1] == ' '){
                  A+=linea1[x];
             }
        }
        B = linea2[0];
        for(int x=1;x<linea2.length();x++){
             if(linea2[x-1] == ' '){
                  B+= linea2[x];
             }
        }        
        bool band = 1;
        if(A.length() != B.length()){ cout << "no\n"; continue;}
        for(int x=0;x<A.length();x++) if(A[x] != B[x]) band = 0;
        if(band) cout << "yes\n";
        else cout << "no\n";
    }
}
