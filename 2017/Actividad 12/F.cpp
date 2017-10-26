#include<bits/stdc++.h>
#define MAX_N 55
#define INF 1000000000
using namespace std;

int mat[MAX_N][MAX_N]={0};
int   p[MAX_N][MAX_N]={0};
int V,T;

void clearMatrix(){
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			mat[i][j] = INF;
			p[i][j] = i;
		}
		mat[i][i] = 0;
	}
}

void floydWarshall(){
	for(int k=0;k<V;k++){
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if(mat[i][k]+mat[k][j]<mat[i][j]){
					mat[i][j] = mat[i][k]+mat[k][j];
					p[i][j] = p[k][j];
				}
			}
		}
	}
}

void printPath(int i, int j){
	if(i!=j){
		printPath(i,p[i][j]);
		cout<<' '<<j;
	}else{
		cout<<j;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	string linea;
	int N;
	cin>>N;	
	for(int caso=1;caso<=N;caso++){
		cin.ignore();
		getline(cin,linea);	
		istringstream iss0(linea);
		iss0>>V>>T;
		clearMatrix();
		for(int i=0;i<V;i++){
			getline(cin,linea);
			istringstream iss1(linea);
			int u,v,t;
			iss1>>u;
			while(iss1>>v>>t){
				mat[u][v] = min(t,mat[u][v]);
			}
		}
		if(T>0){
			for(int i=0;i<T;i++){
				int a,b;
				cin>>a>>b;
				mat[a][b] = 0;
				mat[b][a] = 0;
			}
		}
		int S,E;
		cin>>S>>E;
		floydWarshall();
		cout<<"Case #"<<caso<<": ";
		if(mat[S][E]==INF){
			cout<<"Path does not exist\n";
		}else{
			cout<<mat[S][E]<<'\n';
			printPath(S,E); cout<<'\n';
		}
	}
	return 0;
}
