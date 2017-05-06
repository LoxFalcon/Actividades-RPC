#include<bits/stdc++.h>
#define MOD 1000000007
#define LLI long long int
#define ULLI unsigned long long int
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
set<ULLI> sets;
vvii adjList;
int N,D;
struct Punto{
	int x,y;
}puntos[12];
double dist(int x1, int y1, int x2, int y2){
	double x = (x2-x1) * (x2-x1);
	double y = (y2-y1) * (y2-y1);
	return sqrt((double)x+y);
}
int countBits(int x){
	int sum = 0;
	while(x){
		if(x&1) sum++;
		x>>=1;
	}
	return sum;
}
LLI backtrack(int index, int bands, vi edges, int tabs=0){
	cout<<"INDEX"<<index<<","<<countBits(bands)<<'\n';
	if(countBits(bands)==N){
		for(int i=0;i<tabs;i++) putchar('\t');
		printf("Baia baia %d\n",index);
		if(sets.count(edges)) return 0;
		sets.insert(edges);
		return 1;
	}
	LLI sum = 0;
	for(int i=0;i<tabs;i++) putchar('\t');
	printf("Visitando %d\n",index);
	for(int i=0;i<adjList[index].size();i++){
	//	cout<<(bands&(1<<adjList[index][i]))<<'\n';
		ii par = adjList[index][i];
		if((bands&(1<<par.first)) == 0){
	//		cout<<"haciendo backtrack\n";
			vi tmp = edges;
			tmp.push_back(par.second);
			sort(tmp.begin(),tmp.end());
			sum = (sum+backtrack(par.first,bands|(1<<par.first),tmp),tabs+1)%MOD;
		}
	}
	return sum;
}
int main(){
	int x,y;
	while(cin>>N>>D && N){
		adjList.assign(N,vii());
		sets.clear();
		int edgeIndex = 0;
		for(int i=0;i<N;i++){
			cin>>x>>y;
			puntos[i].x = x;
			puntos[i].y = y;
			for(int j=0;j<i;j++){
				double d = dist(puntos[i].x,puntos[i].y,puntos[j].x,puntos[j].y);
				if(d<=D){
					printf("Creando n arista %d %d, %.2f %d\n",i,j,d,D);
					adjList[i].push_back(make_pair(j,edgeIndex));
					adjList[j].push_back(make_pair(i,edgeIndex++));
				}
			}
		}
		LLI res = 0;
		for(int i=0;i<N;i++){
			res += backtrack(i,1<<i,vi());	
		}
		cout<<res<<'\n';
	}
	return 0;
}
