#include <iostream>
using namespace std;
int main(){
    int A,B,C;
    cin >> A >> B >> C;
    bool band = false;
    int R = A - B;
    if(R == 0) band = true;
    if(B-A == 0) band = true;
    if(B-C == 0) band = true;
    if(C-B == 0) band = true;
    if(C - A == 0) band = true;
    if(A-C == 0) band = true;
    if(A - (B+C) == 0) band = true;
    if(B - (C+A) == 0) band = true;
    if(C - (A+B) == 0) band = true;
    if(band)
        cout << "S\n";
    else cout << "N\n";

}