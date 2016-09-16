#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int mapa[100][100];
int dp[100][100];
int r,c;
bool isValid(int i, int j){
	return i>=0 && i<r && j>=0 && j<c;
}
int calculateSolution(int i, int j){
	//cout<<"Analizando i"<<i<<" y j "<<j<<'\n';
	if(!isValid(i,j)){
		return -1;
	}
//cout<<"asi es\n";
	if(dp[i][j]!=-1) return dp[i][j];
	return dp[i][j] = mapa[i][j] + max(calculateSolution(i-1,j), max(calculateSolution(i,j-1),0)	);
}
void resetMatrix(){
	for(int i=0;i<r;i++){
	for(int j=0;j<c;j++){
		dp[i][j] = -1;
	}
	}
}
int main(){
	int n;
	//scanf("%d",&n);
cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		char aux;
		//scanf("%d%d",&r,&c);
		cin>>r>>c;
		resetMatrix();
		//printf("char \"%c\"\n",aux);
		for(int j=0;j<r;j++){
			for(int k=0;k<c;k++){
				if((j==0&&k==0)||(j==r-1 && k==c-1)){
					//scanf("%c",&aux);
					cin>>aux;
					mapa[j][k] = 0;						
				}else{
//					scanf("%d",&mapa[j][k]);		
					cin>>mapa[j][k];
				}
			}
		}
		int sol = calculateSolution(r-1,c-1);
		/*for(int j=0;j<r;j++){
		for(int k=0;k<c;k++){
			cout<<dp[j][k]<<" ";
		}
cout<<'\n';
		}*/
//		printf("%d\n",sol);
		cout<<"Game Board #"<<i<<": "<<sol<<'\n';
	}
	return 0;
}

