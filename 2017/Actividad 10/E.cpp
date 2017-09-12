#include<bits/stdc++.h>
using namespace std;
set<int> s;
vector<int> sols;
void generarTodo(){
	for(int i=1;i<=512;i++){
		s.insert(i*i);
	}
	for(int i=1;i<=512;i++){
		for(int j=i;j<=512;j++){
			int res = i*i + j*j;
			if(s.count(res)>0){
				//cout<<i<<", "<<j<<" : "<<sqrt(res)<<'\n';
				sols.push_back(sqrt(res));
			}
		}
	}
	sort(sols.begin(),sols.end());
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	generarTodo();
	int N;
	while(cin>>N, N>0){
		vector<int>::iterator it = upper_bound(sols.begin(),sols.end(),N);
		cout<<(it-sols.begin())<<'\n';
	}
	return 0;
}
