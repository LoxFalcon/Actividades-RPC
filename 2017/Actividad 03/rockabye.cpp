#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,pair<string,int> > par;

int main(){
	//freopen("in.	txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T,N,K,nin;
	string str;
	cin>>T;
	while(T--){
		priority_queue<par, vector<par>, greater<par> > pq;
		cin>>N>>K;
		for(int i=0;i<N;i++){
			cin>>str>>nin;
			pq.push(make_pair(make_pair(nin,i),make_pair(str,nin))); //((take,id),(name,period))
		}
		for(int i=0;i<K;i++){
			par tmp = pq.top(); pq.pop();
			cout<<tmp.first.first<<' '<<tmp.second.first<<'\n';
			tmp.first.first += tmp.second.second;
			pq.push(tmp);
		}
	}
	return 0;
}
