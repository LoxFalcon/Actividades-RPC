#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int it = 255;
string r,cad;

bool esAn(int c, string ini, string fin){
	int ci=0, j=0,k=0,t;
	j=k=ci=0;
	r=cad="";
	int i=128;
	stack<char> pila;
	while(i){
		t=i&c;
		//cout<<"T: "<<t<<endl;
		if(t){ //I
			//cout<<"I";
			ci++;
			cad+='i';
			pila.push(ini[j++]);
		}else{    //O
			//cout<<"O";
			if(pila.empty())
				return false;
			r+=pila.top();
			if(pila.top() != fin[k++])
				return false;
			cad+='o';
			pila.pop();
		}
		i>>=1;
		if(ci>4)
			return false;
	}
	if(r==fin)
		return true;
	else
		return false;
	
}

void simular(string ini, string fin){
	int ci=0, j=0,i2=255,k=0;
	while(i2>=128){
		bool band = esAn(i2, ini, fin);
		if(band){
			for(int i=0; i<7; i++)
				cout<<cad[i]<<" ";
			cout<<cad[7]<<endl;
		}
		i2--;
	}
	
}

int main(){
	//freopen("in.txt","r",stdin);
	int n,b,t,r,l,c,i;
	string ini, fin;
	//bool band = esAn(240, "adam", "mada");
	//cout<<band<<" "<<cad<<endl;
	cin>>n;
	while(n--){
		cin>>ini>>fin;
		cout<<"Output for "<<ini<<" "<<fin<<endl<<"["<<endl;;
		simular(ini, fin);
		cout<<"]"<<endl;
	}
	return 0;
}
