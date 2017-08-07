#include<bits/stdc++.h>
#define _F first
#define _S second
using namespace std;
typedef vector<int> vec;
typedef vector< vec > vvi;
typedef pair<int,int> ii;
vvi v;
bitset<200010> vis;
int cont[200010]={0};
int pts[200010]={0};
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int c,t,mycon,conleave;
	cin>>c>>t>>mycon>>conleave;
	mycon--; conleave--;
	v.assign(c,vec());
	int a,b;
	for(int i=0;i<t;i++){
		cin>>a>>b; a--; b--;
		cont[a]++;
		cont[b]++;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int> q;
	q.push(conleave);
	cont[conleave]=-1;
	vis[conleave] = true;
	bool band=false;
	while(!q.empty()){
	    int leave=q.front();
		//cout<<"country leave "<<(leave+1)<<endl;
		q.pop();
		if(leave==mycon){
			band=true;
			break;
		}
		for(int i=0; i<v[leave].size();i++){
			int j=v[leave][i];
			pts[j]++;
			if(((cont[j]+1)>>1)<=pts[j] && vis[j]==false){
				q.push(j);
				vis[j] = true;
			}
		}
	}
	if(band){
		cout<<"leave"<<'\n';
	}else{
		cout<<"stay"<<'\n';
	}
	return 0;
}
