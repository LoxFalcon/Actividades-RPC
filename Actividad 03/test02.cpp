#include <iostream>
#include <vector>
#define MAX 3000000
using namespace std;
typedef long long int lli;
vector<lli> sumatorias;
lli A[MAX+1] = {0};
void init(){
    lli N = 1;
    lli sum = N*(N+1) / 2;
    while(sum < MAX){
        sumatorias.push_back(sum);
        N++;
        sum = N*(N+1) / 2;
    }
    for(int x=0;x<sumatorias.size();x++){
        int y = x;
        while(sumatorias[x] + sumatorias[y] < MAX+1){
            A[sumatorias[x] + sumatorias[y]] = 2;
            y++;
        }
    }
    for(int x=0;x<sumatorias.size();x++){
        A[sumatorias[x]] = 1;
    }
}
int main(){
    init();
    int N;
    while(cin >> N){
        cout << ((A[N] == 0) ? 3 : A[N]) << "\n";
    }
}
