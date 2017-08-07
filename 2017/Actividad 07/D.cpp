#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> vii;
typedef vector<vii> vi;
typedef vector<int> vis;

int main(){
	int n,m;
	cin>>n>>m;
	map<string,int> ma;
	string target,t2;
	int cont=0,cos;
	ma["English"]=cont++;
	for(int i=0; i<n;i++){
		cin>>target;
		ma[target]=cont++;
	}
	vi v(n+1,vii());
	for(int i=0; i<m;i++){
		cin>>target>>t2>>cos;
		v[ma[target]].push_back(make_pair(ma[t2],make_pair(1,cos)));
		v[ma[t2]].push_back(make_pair(ma[target],make_pair(1,cos)));
	}
	queue<iii> q;
	vis d(n+1,-1);
	vis co(n+1,1e9);
	vis salt(n+1,1e9);
	q.push(make_pair(0,make_pair(0,0)));
	while(!q.empty()){
		iii u=q.front();q.pop();
		if(co[u.first]>u.second.second && u.second.first<=salt[u.first]){
			co[u.first]=u.second.second;
			salt[u.first]=u.second.first;
		}
		d[u.first]=0;
		for(int i=0;i<(int)v[u.first].size();i++){
			iii l=v[u.first][i];
			if(d[l.first]==-1){
				q.push(make_pair(l.first,make_pair(u.second.first+1,l.second.second)));
			}
		}
	}
	int cost=0; int contt=0;
	for(int i=0; i<n+1;i++){
		cost+=co[i];
		//cout<<co[i]<<" ";
		if(co[i]==1e9){
			contt++;
		}
	}
	if(contt==0){
		cout<<cost<<endl;
	}else{
		cout<<"Impossible"<<endl;
	}
	return 0;
}

/*
	for(int k=0;k<v;k++){
		for(int i=0;i<v;i++){
			for(int j=0; j<v;j++){
				if(jump[i][j]>jump[i][k]+jump[k][j]){
					jump[i][j]=jump[i][k]+jump[k][j];
				}
			}
		}
	}
	int cost=0;
	for(int i=0; i<v;i++){
		if(jump[0][i]==1){
			cost+=cos[0][i];
		}else{
			int aux=jum[0][i];
			for(int j=0;j<)
		}
	}
*/
