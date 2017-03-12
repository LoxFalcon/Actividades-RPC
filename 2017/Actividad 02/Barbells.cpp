#include<bits/stdc++.h>
#define LLI long long int
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi combis;
map<LLI,int> id;
set<LLI> diff;
set<LLI> res;
int N,M, pesos[15], barras[15];
LLI calcularPeso(int c){
	LLI sum=0; int cont=0;
	while(c){
		if(c&1){
			sum+=((LLI)pesos[cont]);
		}
		cont++;
		c>>=1;
	}
	return sum;
}
/*
string binario(int a){
	string x="";
	while(a){
		x+=((a&1)+'0');
		a>>=1;
	}
	reverse(x.begin(),x.end());
	if(x.empty()) x= "0";
	return x;
}*/
bool compatibles(int a, int b){
	int c = a&b;
	//cout<<"A ("<<binario(a)<<"), B ("<<binario(b)<<") = C ("<<binario(c)<<")\t";
	return c==0;
}
void generarCombinaciones(){
	int tope = (1<<M)-1, inicio=1;	
	diff.insert(0); //ninguna pesa
	while(inicio<=tope){
		LLI tmp = calcularPeso(inicio);
		if(diff.count(tmp)==0){ //Si no está emparejado aún
			if(id.count(tmp)==0){
				int x = combis.size();
				id[tmp] = x;
				combis.push_back(vi());
				combis[x].push_back(inicio);
			}else{
				int x = id[tmp];
				combis[x].push_back(inicio);
				for(int i=0;i<combis[x].size()-1;i++){					
					if(compatibles(combis[x][i],inicio)){ 
						diff.insert(tmp);
						break;
					}
				}
			}
		}
		inicio++;
	}	
}
void resolver(){
	generarCombinaciones();
	set<LLI>::iterator it;
	for(int i=0;i<N;i++){
		LLI act = (LLI)barras[i];
		for (it=diff.begin(); it!=diff.end(); ++it){
			res.insert(act+(*it)*2);
		}    			
	}
	for (it=res.begin(); it!=res.end(); ++it){
		cout<<(*it)<<'\n';
	}    			
}
int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>barras[i];
	}
	for(int i=0;i<M;i++){
		cin>>pesos[i];
	}
	resolver();	
	return 0;
}
