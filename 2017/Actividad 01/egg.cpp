#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, F;
	cin >> N >> F;
	string t;
	int p;
	int maxSafe = 1, minBroken = F;
	while(N--){
		cin >> p >> t;
		if(t[0] == 'S'){
			maxSafe = max(maxSafe, p);
		}else{
			minBroken = min(minBroken, p);
		}
	}
	cout << maxSafe + 1 << " " << minBroken - 1 << "\n";

}
