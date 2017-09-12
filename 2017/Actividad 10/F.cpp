#include<bits/stdc++.h>
using namespace std;
int R,C;
bool isOutside;
char mapa[35][35]={0};
int dirI[4] = {0,1,0,-1};
int dirJ[4] = {1,0,-1,0};
bool isValid(int i, int j){
	return i>=0 && i<R && j>=0 && j<C;
}
int floodFill(int i, int j){
	if(!isValid(i,j)){
		isOutside = true;
		return 0;
	}
	if(mapa[i][j] != '0') return 0;
	mapa[i][j] = '2';
	int res = 1;
	for(int x=0;x<4;x++){
		int a = i+dirI[x], b=j+dirJ[x];
		res+=floodFill(a,b);
	}
	return res;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>R>>C;
		for(int i=0;i<R;i++){
			cin>>mapa[i];
		}
		int cells = 0;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				if(mapa[i][j]=='0'){
					isOutside = false;
					int res = floodFill(i,j);
					if(isOutside){
						cells += res;
					}
				}
			}
		}
		cout<<cells<<'\n';
	}
	return 0;
}
