#include<bits/stdc++.h>
#define MAX_N 100003
#define LSOne(x) (x&(-x))
using namespace std;
typedef vector<int> vi;
int camaras[MAX_N]  = {0};
class FenwickTree{
private:
	vi ft;
public:
	FenwickTree(int n){ ft.assign(n+1,0); }	
	int rsq(int b){
		int sum=0; 
		for(; b; b-=LSOne(b) )
			sum+=ft[b];
		return sum;
	}
	
	int rsq(int a, int b){
		return rsq(b)-(a==1 ? 0 : rsq(a-1) );
	}
	
	void adjust(int k, int v){
		for(;k<(int)ft.size(); k+=LSOne(k)) ft[k]+=v;
	}
		
};

int main(){
	int N,K,R,tmp;
	cin>>N>>K>>R;
	FenwickTree FT(N);
	for(int i=0;i<K;i++){
		cin>>tmp;
		if(camaras[tmp] == 0){
			camaras[tmp] = 1;
			FT.adjust(tmp,1);	
		}
	}
	int tope = N-R+1;
	int cont=0;
	for(int i=1;i<=tope;i++){
		int cam = FT.rsq(i,i+R-1);
		if(cam==1){
			cont++;
			if(camaras[i+R-1]==1){
				camaras[i+R-2] = 1;
				FT.adjust(i+R-2,1);
			}else{
				camaras[i+R-1] = 1;
				FT.adjust(i+R-1,1);
			}
		}else if(cam==0){
			cont+=2;
			camaras[i+R-2] = 1;
			FT.adjust(i+R-2,1);
			camaras[i+R-1] = 1;
			FT.adjust(i+R-1,1);
		}
	}
	cout<<cont<<'\n';
	return 0;
}
