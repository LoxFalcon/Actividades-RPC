#include<bits/stdc++.h>
#define MAX_N 1005
using namespace std;
string s;
int LIS[MAX_N],F;
bool menorQue(char a, char b){
	int delta = (a-'a'+F)%26;
	return delta <= ((int)b-'a');
}
int maxSolve(){
	int maxPuto = 1;
	for(int i=0;i<s.size();i++) LIS[i] = 1;
	for(int i=1;i<s.size();i++){
		for(int j=0;j<i;j++){
			
			if(menorQue(s[j],s[i]) && LIS[i]<LIS[j]+1){
				LIS[i] = LIS[j] + 1;
			}
		}
	}
	for(int i=0;i<s.size();i++) maxPuto=max(maxPuto,LIS[i]);
	return maxPuto;
	
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>s>>F;
		cout<<maxSolve()<<'\n';
	}
	return 0;
}
