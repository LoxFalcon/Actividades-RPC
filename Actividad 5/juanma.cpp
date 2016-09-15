#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int lli;
lli M[201][6] = {0};
void init(){
	for(int x=0;x<201;x++){
		for(int y=0;y<=x;y++){
			if(y == 6) break;
			if(x == y || y == 0) M[x][y] = 1;
			else M[x][y] = M[x-1][y-1] + M[x-1][y];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	init();
	int N,T;
	lli res;
	cin >> T;
	while(T--){
		cin >> N;
		if(N == 1) cout << "1\n";
		else if(N == 2) cout << "2\n";
		else if(N == 3) cout << "4\n";
		else{
			res = N*(N-1)/2;
			--N;
			//cout << M[N][3] << " " << M[N][4] << "\n";
			res+=(M[N][3] + M[N][4]);
			cout << res + 1 << "\n";
		}
	}
}
