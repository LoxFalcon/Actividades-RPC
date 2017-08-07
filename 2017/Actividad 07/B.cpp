#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
#define endl '\n'

struct Equipo{
	string uno;
	string dos;
	string antes;
};

void gana(Equipo &a){
	string t;
	t=a.uno;
	a.uno=a.dos;
	a.dos=t;
}

void pierde(Equipo &a, queue<string> &q){
	string f=q.front();
	q.push(a.dos);
	a.dos=a.uno;
	a.antes=a.dos;
	a.uno=f;
	q.pop();
}

int main(){
	//freopen("in.txt", "r", stdin);
	int n;
	string s;
	queue<string> q;
	char c;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>s;
		q.push(s);
	}
	Equipo white, black;
	white.antes = q.front();
	white.uno = q.front(); q.pop();
	black.antes = q.front();
	black.uno = q.front(); q.pop();
	white.dos = q.front(); q.pop();
	black.dos = q.front(); q.pop();
	int rw=0, rb=0, r=0, rMax=-1;
	char prev='O';
	vector<pair<int, Equipo> > ve;
	while(cin>>c){
		if(c=='W'){
			if(prev!='W') r=0;
			r++;
			if(r>=rMax){
				rMax=r;
				ve.push_back(make_pair(r, white) );
			}
			gana(white);
			pierde(black, q);
		}else{
			if(prev!='B') r=0;
			r++;
			if(r>=rMax){
				rMax=r;
				ve.push_back(make_pair(r, black) );
			}
			gana(black);
			pierde(white, q);
		}
		prev=c;
	}
	//cout<<"Rmax "<<rMax<<endl;
	for(int i=0; i<(int)ve.size(); i++){
		if(ve[i].first==rMax){
			if(ve[i].second.uno == ve[i].second.antes ){
				//cout<<"puntaje"<<ve[i].first<<" - ";
				cout<<ve[i].second.uno<<" "<<ve[i].second.dos<<endl;
			}else{
				//cout<<"puntaje"<<ve[i].first<<" - ";
				cout<<ve[i].second.dos<<" "<<ve[i].second.uno<<endl;
			}
		}
	}
	return 0;
}
