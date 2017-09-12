#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<vvi,int> ps;
typedef vector<ps> vps;
#define endl '\n'

int sq[510][510];
int N=0, K=0, V;
vps vec;
bool vis[510][510];

int checar(vvi a, int p, int I, int J){
	int temp;
	int b[2][2];
	for(int i=0; i<4; i++){
		if(
			a[0][0]==sq[I][J] &&
			a[0][1]==sq[I][J+1] &&
			a[1][0]==sq[I+1][J] &&
			a[1][1]==sq[I+1][J+1]
		){
			return p;
		}
		//guardar
		b[0][0]=a[0][0];
		b[0][1]=a[0][1];
		b[1][0]=a[1][0];
		b[1][1]=a[1][1];
		//rotar
		a[0][0]=b[0][1];
		a[0][1]=b[1][1];
		a[1][0]=b[0][0];
		a[1][1]=b[1][0];
		
	}
	return 0;
}

ll pre(vps vec){
	ll res=0;
	for(int i=0; i<N; i+=2){
		for(int j=0; j<N; j+=2){
			int t=0,c=0;
			for(int k=0; k<K; k++){
				c=checar(vec[k].first, vec[k].second, i, j);
				if(c>t){
					t=c;
					if(!vis[i][j]){
						vis[i][j]=true;
						V++;
					}
				}
			}
			//cout<<"I: "<<i<<" J: "<<j<<" t: "<<t<<endl;
			res+=t;
		}
	}
	return res;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("in.txt","r",stdin);
	int cont=0;
	while(cin>>N>>K && N && K){
		//cout<<cont++<<" "<<N<<" "<<K<<endl;
		memset(vis, 0, sizeof(vis));
		V=0;
		vps vec;
		int p;
		vvi a(2, vi());
		a[0].resize(2);
		a[1].resize(2);

		for(int i=0; i<K; i++){
			cin>>a[0][0]>>a[0][1]>>a[1][0]>>a[1][1]>>p;
			vec.push_back(make_pair(a, p));
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				cin>>sq[i][j];	
			}
		}
		/*cout<<"hi"<<endl;
		for(int i=0; i<2; i++){
			for(int j=0; j<2; j++)
				cout<<a[i][j]<<" ";
		}*/
		ll res = pre(vec);
		//cout<<"R: "<<res<<" "<<V<<endl;
		if(V!=N)
			cout<<"-1"<<endl;
		else
			cout<<res<<endl;
		//cout<<"hi"<<endl;
	}
	return 0;
}
