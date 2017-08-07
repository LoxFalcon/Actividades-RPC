#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
int last[6000] ={0};
int times[6000]={0};
int trie[6000][4] = {0};
int nodeCount = 1;
map<char,int> id;
string str;
int charsSaved = -1;
void insertar(int x){
	int nodoActual = 1; int len = 1;
	for(;x < str.size(); x++, len++){
		int  y = id[str[x]];
		if(trie[nodoActual][y] == 0){
			trie[nodoActual][y] = ++nodeCount;
		}
		nodoActual = trie[nodoActual][y];
		if(last[nodoActual]<x){
			times[nodoActual]++;
			int used = (times[nodoActual]*len)-(times[nodoActual]+len);
			last[nodoActual] = x+len-1;
			charsSaved = max(used,charsSaved);	
		}
		
	}
}

int main(){
	memset(last, -1, sizeof last);
	id['N'] = 0;
	id['S'] = 1;
	id['E'] = 2;
	id['W'] = 3;
	cin>>str;
	for(int i=0;i<str.size();i++){
		insertar(i);
	}
	if(charsSaved == -1){
		charsSaved = 0;
	}
	/*cout<<charsSaved<<'\n';
	cout<<str.size()<<'\n';*/
	int res = ((int)str.size()) - charsSaved;
	cout<<abs(res)<<'\n';
	return 0;
}
