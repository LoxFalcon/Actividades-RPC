#include<bits/stdc++.h>
using namespace std;
int R, C, iA, jA, iB, jB;
char mapita[105][105];
bool esValido(int i, int j){
	return i>=0 && i<R && j>=0 && j<C;
}
int main(){
	cin>>R>>C;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>mapita[i][j];
			if(mapita[i][j]=='A'){
				iA = i;
				jA = j;
			}else if(mapita[i][j] == 'B'){
				iB = i;
				jB = j;
			}
		}
	}
	return 0;
}
