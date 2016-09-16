#include <iostream>
using namespace std;
int p(int n){return n*n; }
int main() {
	cout.precision(15);
	int x1,x2,y1,y2;
	while(cin >> x1 >> y1 >> x2 >> y2){
		cout <<(double)((p(x1-x2) + p(y1-y2))/ 6.0)<< "\n";
	}
	return 0;
}