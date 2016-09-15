#include<cstdio>
#include<iostream>
#include<algorithm>
#define LLI long long int
using namespace std;
int n,m;
int values[502];
LLI dp[502][502];
LLI maxValue(int i, int maxItems){
	//cout<<"Ando en i="<<i<<", con maxItems="<<maxItems<<'\n';
	if(maxItems<1) return 0;
	if(dp[i][maxItems]!=-1) return dp[i][maxItems];	
	if(i==1) return dp[i][maxItems] = values[i];	//Ya estoy en el último y aún hay posibilidades de comprar (por la condición anterior)
	//if(maxItems==1) return dp[i][maxItems] = values[i];	
	int half = (i-1) == 1 ? i-1 : (i-1)>>1;
	LLI maxV = max(maxValue(i-1,min(maxItems-1,half))+values[i], maxValue(i-1,min(maxItems,half)));
//	for(int j=i-1;j>0;j--){
//		int half = j == 1 ? j : j>>1;
//		int items = min(maxItems-1,half);
//		maxV = max(maxV, maxValue(j, items)+values[i]); //Si comprar 
//		items = min(maxItems,half);
//		maxV = max(maxV, maxValue(j, min(maxItems, half))); 		   //No comprarlo
//	}
	return dp[i][maxItems] = maxV;
}
void resetDP(){
	int mitad = (m+1)>>1;
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=mitad;j++)
			dp[i][j]=-1;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int caso=1;caso<=n;caso++){
		cin>>m;
		resetDP();
		for(int i=1;i<=m;i++){
			cin>>values[i];
		}	
		int half = m==1 ? m : m>>1;
		LLI sol = maxValue(m,half); //Indexado en 1
		cout<<"Spree #"<<caso<<": "<<sol<<'\n';
	}
	return 0;
}
