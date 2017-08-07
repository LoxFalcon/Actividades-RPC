#include<bits/stdc++.h>
using namespace std;
char res[1005]={0};
string a,b;
char shift(char a, char b){
	int key = a-'A';
	//printf("JEJE %c %c %d\n",a,b,key);
	key -= (b-'A');
	//printf("JEJE %c %c %d\n",a,b,key);
	if(key<0){
		key = 26 + key;
	}
	return (char)(key+'A');
}
int main(){
	cin>>a>>b;
	int cont = 0,i;
	for(i=0;i<b.size() && i<a.size();i++, cont++){
		res[i] = shift(a[i],b[i]);
	}
	i = 0;
	while(cont < a.size()){
		res[cont] = shift(a[cont],res[i]);
		//printf("CHAR '%c' %c = %c\n",a[cont],res[i],res[cont]);
		cont++; i++;
	}
	res[cont] = '\0';
	cout<<res<<'\n';
	return 0;
}
