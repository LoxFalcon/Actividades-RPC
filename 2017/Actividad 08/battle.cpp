#include<bits/stdc++.h>
using namespace std;
string s;
map<char,char> mapita;
bool hayTodos(int i){
	if((i+2) >= s.size()) return false;
	return s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2];
}
int main(){
	mapita['R'] = 'S';
	mapita['B'] = 'K';
	mapita['L'] = 'H';
	ios_base::sync_with_stdio(false);	
	cin.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(hayTodos(i)){
			cout<<'C';
			i+=2;
		}else{
			cout<<mapita[s[i]];
		}
	}
	return 0;
}
