#include<bits/stdc++.h>
#define MP make_pair
#define F first
#define S second
#define LSOne(S) (S&(-S))
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
class FenwickTree{
	private:
		vi ft;
	public:
		FenwickTree(int N){
			ft.assign(N+1,0);
		}
		int rsq(int b){
			int sum=0;
			for(;b;b-=LSOne(b)) sum+=ft[b];
			return sum;
		}
		int rsq(int a, int b){
			return rsq(b)-(a==1 ? 0 : rsq(a-1));
		}
		void adjust(int k, int v){
			
			for(;k<(int)ft.size();k+=LSOne(k)){
				ft[k]+=v;
			}
		}
};
struct Operacion
{
	int tipo; //operacion (0 o 1), 0 = añadir, 1 = consulta
	int l,r,val;
	//Cuando Operacion 1:
	//l = inicio del intervalo
	//r = fin del intervalo
	//val = valor a buscar
	//Cuando Operacion 0:
	//l = índice en el que agregar al BIT
	//val = valor de ordenamiento
};
bool compara(Operacion a, Operacion b){
	if(a.val == b.val){
		return a.tipo < b.tipo;
	}
	return a.val < b.val;
}
vii edges;
vector<Operacion> ops;
int main(){
	int T,a,b,N,M;
	cin>>T;
	while(T--){
		ops.clear();
		edges.clear();
		cin>>N>>M;
		for(int i=0;i<M;i++){
			cin>>a>>b;
			edges.push_back(MP(b,a)); //Invertir el intervalo para ordenar por fin
		}
		sort(edges.begin(),edges.end());// Ordenamos por el fin de los intervalos
		for(int i=0;i<M;i++){
			
			//printf("Edge[%d]=(%d,%d)\n",i,edges[i].S,edges[i].F);
			Operacion q,add;
			add.tipo = 0;
			add.l = i;
			add.val = edges[i].S; //Agregamos al FT el inicio de edges[i]
			ops.push_back(add);
			ii busq = MP(edges[i].S,edges[i].F);
			vii::iterator low = upper_bound(edges.begin(),edges.end(),busq);
			if(low == edges.end() || (*low).F >= edges[i].F) continue; //no hay ningún intervalo que termine entre el inicio y el fin de este intervalo
			//printf("HABEMUS consulta porque low %d %d",(*low).S,(*low).F);
			q.tipo = 1;						
			q.l = low-edges.begin();
			q.r = i-1; //aquí podría ser i-1
			q.val = edges[i].S;
			ops.push_back(q);
		}
		sort(ops.begin(),ops.end(),compara);
		int sum=0;
		FenwickTree FT(M);
		for(int i=0;i<ops.size();i++){
			if(ops[i].tipo){
			//	printf("La consulta (%d,%d) hay %d\n",ops[i].l+1,ops[i].r+1,FT.rsq(ops[i].l+1,ops[i].r+1));
				sum+=FT.rsq(ops[i].l+1,ops[i].r+1);
			}else{
				FT.adjust(ops[i].l+1,1);
			}
		}
		cout<<sum<<'\n';
	}	
	
	return 0;
}
