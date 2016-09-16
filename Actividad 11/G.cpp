#include<bits/stdc++.h>
#define MAXN 502
using namespace std;
int N,P;
int blancas[MAXN][MAXN]={0};
int negras[MAXN][MAXN]={0};
void limpiarMatrices(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			blancas[i][j] = negras[i][j] = 0;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x,y,resB,resN;
	while(cin>>N>>P){		
		resB = resN = 0;
		for(int i=0;i<P;i++){
			cin>>x>>y;
			x--; y--;
			negras[x][y]=1;			
		}		
		for(int i=0;i<P;i++){
			cin>>x>>y;
			x--; y--;
			blancas[x][y]=1;
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(i>0) negras[i][j]+=negras[i-1][j];
				if(j>0) negras[i][j]+=negras[i][j-1];
				if(i>0 && j>0) negras[i][j]-=negras[i-1][j-1];
				
				if(i>0) blancas[i][j]+=blancas[i-1][j];
				if(j>0) blancas[i][j]+=blancas[i][j-1];
				if(i>0 && j>0) blancas[i][j]-=blancas[i-1][j-1];
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				int a = i, b = j;
				while(a<N && b<N){
					int sumN = negras[a][b];
					int sumB = blancas[a][b];
					if(i>0){
						sumN -= negras[i-1][b];
						sumB -= blancas[i-1][b];
					}
					if(j>0){
						sumN -= negras[a][j-1];
						sumB -= blancas[a][j-1];
					}
					if(i>0 && j>0){
						sumN+=negras[i-1][j-1];
						sumB+=blancas[i-1][j-1];
					}
					if(sumN==0 && sumB>0){
						resB++;
					}else if(sumN>0 && sumB==0){
						resN++;
					}
					a++;b++;
				}
			}
		}
		cout<<resN<<" "<<resB<<'\n';
		limpiarMatrices();		
	}
	return 0;
}
