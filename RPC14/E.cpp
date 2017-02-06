#include<bits/stdc++.h>
#define MP make_pair
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef vector<int> vi;
viii edges;
class UnionFind{
    private: 
        vi p, rank; 
        int num;
    public:
        UnionFind(int N){
            num= N;
            rank.assign(N,0);
            p.assign(N,0);
            for(int i=0;i<N;i++){
                p[i]=i;
            }
        }
        int findSet(int i){
            return (p[i]==i) ? i : (p[i] = findSet(p[i]));
        }
        bool isSameSet(int i, int j){
            return findSet(i) == findSet(j);
        }
        int numSets(){
            return num;
        }
        void unionSet(int i, int j){
            if(!isSameSet(i,j)){
                num--;
                int x = findSet(i), y = findSet(j);
                if(rank[x]>rank[y]) p[y] = x;
                else{
                    p[x]=y;
                    if(rank[x]==rank[y]) rank[y]++;
                }
            }
        }
};
int N,M,L;
int main(){
    cin>>N>>M>>L;
    int a,b,c;
    int budget = 0;
    UnionFind UF(N);
    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        if(i<L){
            budget+=c;
        }
        edges.push_back(MP(c,MP(a-1,b-1)));
    }
    sort(edges.begin(),edges.end());
    int i=0; int mst=0;
    while(UF.numSets()>1 && i<M){
        c = edges[i].first;
        a = edges[i].second.first;
        b = edges[i].second.second;
        if(!UF.isSameSet(a,b)){
            UF.unionSet(a,b);
            mst+=c;
        }
        i++;
    }
    if(UF.numSets()==1 && mst<=budget){
        cout<<"possible"<<'\n';
    }else cout<<"impossible"<<'\n';
    return 0;
}