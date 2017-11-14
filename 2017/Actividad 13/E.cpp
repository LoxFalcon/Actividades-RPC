#include<bits/stdc++.h>
#define MAX_M 105
using namespace std;

char mapa[MAX_M][MAX_M]={0};
int M,N;
void clearMatrix(){
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			mapa[i][j] = '.';
		}
	}
}
bool isValid(int X, int Y){
	return X>=0 && X<M && Y>=0 && Y<M;
}
void pintar(char c, int x, int y){
	if(isValid(x,y)){
		mapa[M-y-1][x] = c;
	}
}
void dibujarArbol(int S, int X, int Y){
	if(X < -2 || X > M || Y < -10 || Y >= M ) return; //el árbol no está dentro del viewport
	if(S==0){
		pintar('_',X-1,Y);
		pintar('o',X,Y);
		pintar('_',X+1,Y);
	}else{
		pintar('_',X-1,Y);
		pintar('|',X,Y);
		pintar('_',X+1,Y);
		for(int i=0;i<S;i++){
			Y++;
			pintar('/',X-1,Y);
			pintar('|',X,Y);
			pintar('\\',X+1,Y);
		}
		Y++;
		pintar('^',X,Y);
	}	
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int S,X,Y;
	while(cin>>M>>N){
		clearMatrix();
		for(int i=0;i<N;i++){
			cin>>S>>X>>Y;
			dibujarArbol(S,X,Y);
		}
		
		for(int i=-1;i<=M;i++){
			for(int j=-1;j<=M;j++){
				if(!isValid(i,j)){
					cout<<'*';
				}else{
					cout<<mapa[i][j];
				}
			}
			cout<<'\n';
		}
		cout<<'\n';
	}	
	return 0;
}
