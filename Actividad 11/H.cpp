#include <iostream>
using namespace std;
string A;
int main(){
    cin >> A;
    string vocales;
    for(int x=0;x<A.size();x++){
        if(A[x] == 'a' || A[x] == 'e' || A[x] == 'i' || A[x] == 'o' || A[x] == 'u'){
            vocales.push_back(A[x]);
        }
    }
    int i,j;
    for(i=0,j=vocales.size()-1; i<j;i++,j--){
        if(vocales[i] != vocales[j]) break;
    }
    if(i < j) cout << "N\n";
    else cout << "S\n";
}