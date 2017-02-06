#include<bits/stdc++.h>
#define MAX_E 100000
#define LOG_TWO_N 18
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi> vvi;
vvi adjList;
vvi apariciones;
int prof[2*MAX_E];
int orden[2*MAX_E];
int SpT[2*MAX_E][LOG_TWO_N];
int C,P;
class RMQ{
    public:
        RMQ(int n){
            for(int i=0;i<n;i++){
                SpT[i][0] = i;
            }
            for(int j=1;(1<<j)<=n;j++){
                for(int i=0;i+(1<<j)-1 < n;i++){
                    if(prof[SpT[i][j-1]]<prof[SpT[i+(1<<(j-1))][j-1]])
                        SpT[i][j] = SpT[i][j-1];
                    else
                        SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
                }
            }
        }
        int query(int i, int j){
            int k = (int)floor(log((double)j-i+1) / log(2.0));
            if(prof[SpT[i][k]] <= prof[SpT[j-(1<<k)+1][k]]) return SpT[i][k];
            else return SpT[j-(1<<k)+1][k];
        }
};
int idx=0;
void dfs(int cur, int depth){
    apariciones[cur].push_back(idx);
    prof[idx] = depth;
    orden[idx++] = cur;
    //cout<<adjList[cur].size()<<" tm \n";
    for(int i=0;i<(int)adjList[cur].size();i++){
     //   cout<<"Checando esta madre";
        dfs(adjList[cur][i],depth+1);
        orden[idx] = cur;
        prof[idx++] = depth;
    }
    //cout<<"Saliendo de cur: "<<cur<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int U,V;
    while(cin>>C>>P){
        adjList.assign(C,vi());
	    apariciones.assign(C,vi());
	    for(int i=0;i<P;i++){
	        cin>>U>>V;
	        adjList[U-1].push_back(V-1);
	    }
	    dfs(0,0);
	    int count = C-1;
	    RMQ rmq(C);
	    map<ii,bool> vis; 
	    for(int i=1;i<C;i++){
	        for(int j=1;j<C;j++){
	        	if(i==j) continue;
	        	cout<<i<<" "<<j<<'\n';
	            for(int k=0;k<apariciones[i].size();k++){
	                for(int l=0;l<apariciones[j].size();l++){
	                    if(apariciones[j][l]<apariciones[i][k]) continue;
	                    int q = rmq.query(apariciones[i][k],apariciones[j][l]);
	                    if(orden[q]==0){ 
	                    	int tmp1 = i, tmp2 = j;
	                    	if(tmp2<tmp1) swap(tmp2,tmp1);
	                    	ii con = make_pair(tmp1,tmp2);
	                    	if(!vis.count(con)){
	                    		vis[con] = true;
	                    	}
	                        k = apariciones[i].size();
	                        break;
	                    }
	                        
	                }
	            }
	        }
	    }
    	cout<<count+vis.size()<<'\n';
    }
    return 0;
}