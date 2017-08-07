#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> p;
typedef vector<p> vp;
typedef vector<vp> vvp;
vi match,vis;
int x;
vvp lista;
int Aug(int l){
	if(vis[l]) return 0;
	vis[l]=1;
	for(int j=0; j<lista[l].size();j++){
		int r=lista[l][j].first;
		int h=lista[l][j].second;
		if(h<=x && (match[r]==-1 || Aug(match[r]))){
			match[r]=l;
			return 1;
		}
	}
	return 0;
}

int dis(int x1, int y1, int x2, int y2){
	return abs(x1-x2)+abs(y1-y2);
}


bool posible(int n){
	int mcbm=0;
	match.assign(n,-1);
	for(int i=0; i<n;i++){
		vis.assign(n,0);
		mcbm+=Aug(i);
	}
	if(mcbm==n) return true;
	return false;
}

int main(){
	int n;
	cin>>n;
	int xs[n],ys[n];
	for(int i=0; i<n;i++){
		cin>>xs[i];
		cin>>ys[i];
	}
	int tx,ty;
	lista.assign(n,vp());
	int ma=0;
	for(int i=0; i<n;i++){
		cin>>tx>>ty;
		for(int j=0; j<n;j++){
			lista[j].push_back(make_pair(i,dis(xs[j],ys[j],tx,ty)));
			ma=max(ma,dis(xs[j],ys[j],tx,ty));
		}
	}
	int inf=0,sup=ma;
	int aux;
	while(inf<=sup){
		x=(inf+sup)/2;
		if(posible(n)){
			aux=x;
			sup=x-1;
		}else{
			inf=x+1;
		}
	}
	cout<<aux<<"\n";
	return 0;
}
