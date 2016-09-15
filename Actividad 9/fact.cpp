#include<bits/stdc++.h>
using namespace std;
long double facts[2502]={0.0};
long double sets[3];
long double error;
void fillFacts(){
	//[0] = [1] = 0.0; Ya que 0! = 1! = 1 y log(1) = 0
	for(int i=2;i<2502;i++){
		facts[i] = logl(i)+facts[i-1];
	}
	error = logl(0.9999);
	//cout<<facts[2501]<<'\n';
	//cout<<"Error: "<<error;
}
bool iguales(long double x, long double y){ //x >= y
	return (x+error)<y;
}
int calcularMayor(){
	long double max1=-1, max2=-1; int sel;	
	for(int i=0;i<3;i++){
	//	cout<<"SETS["<<i<<"] = "<<sets[i]<<'\n';
		if(sets[i]>max1){
			max2 = max1;
			max1 = sets[i];
			sel = i;
		}else if(sets[i]>max2){
			max2 = sets[i];
		}
	}
	return iguales(max1,max2) ? 0 : sel+1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	fillFacts();
	int n,tmp;
	int sizes[3];
	cin>>n;	
	for(int caso=1;caso<=n;caso++){
		sets[0] = sets[1] = sets[2] = 0.0;
		cin>>sizes[0]>>sizes[1]>>sizes[2];
		for(int i=0;i<3;i++){
			for(int j=0;j<sizes[i];j++){
				cin>>tmp;
				sets[i] += facts[tmp];
			}
		}
		int solucion = calcularMayor();
		cout<<"Case #"<<caso<<": ";
		switch(solucion){
			case 0:
				cout<<"TIE\n";
				break;
			case 1:
				cout<<"A\n";
				break;
			case 2:
				cout<<"B\n";
				break;
			case 3:
				cout<<"C\n";
				break;
		}
	}
	return 0;
}
