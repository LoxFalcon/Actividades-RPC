#include<cstdio>
#include<vector>
#include<iostream>
#include<bitset>
#include<utility>
using namespace std;
typedef bitset<10> b10;
typedef pair<b10, int> parMunioz;
typedef vector<int> vi;
int nums [100005];
int n;
class SegmentTree{
      private: vector<parMunioz> st; vi A;
      int left(int p){ return p<<1;} 
      int right(int p) { return (p<<1)+1;}      
      parMunioz build(int p, int L, int R){
            if(L==R){
                  st[p].first[nums[L]] = true;
                  st[p].second = 1;
                  return st[p];
            }else{
                  parMunioz ray, manuel;
                ray =  build(left(p), L,(L+R)/2);
                manuel =  build(right(p), (L+R)/2+1,R);
                int c = 0;
                for(int i=0;i<10;i++){
                        st[p].first[i] = ray.first[i] || manuel.first[i];
                        if(st[p].first[i]) c++;                        
                }
                st[p].second = c;
                return st[p];
      } }
      
      parMunioz rmq(int p, int L, int R, int i, int j){
          if(i > R || j < L) return make_pair(b10(),-1);
          if(L >= i && R <= j) return st[p];
          
          parMunioz p1 = rmq(left(p),L,(L+R)/2, i,j);
          parMunioz p2 = rmq(right(p),(L+R)/2+1,R,i,j);
          
          if(p1.second == -1) return p2;
          if(p2.second == -1) return p1;
          int c = 0;
          parMunioz parNuevo;
          for(int i=0;i<10;i++){
               parNuevo.first[i] = p1.first[i] || p2.first[i];
               if(parNuevo.first[i]) c++; 
          }
                parNuevo.second = c;
          return parNuevo;
      }
      public:
             SegmentTree(){
                               st.assign(4*n,parMunioz());
                               build(1,0,n-1);
             }
             parMunioz rmq(int i,int j){
                       return rmq(1,0,n-1,i,j);
             }
};
int main(){
    int q,x,y;
    while(scanf("%d",&n)==1){
                          //n=100;
                          for(int i=0;i<n;i++){
                           scanf("%d",&nums[i]);
                           //       nums[i] = i%10;
                          }
                          SegmentTree st;
                          //printf("HOLA");
                          scanf("%d",&q);
                          while(q--){
                                     
                                     scanf("%d%d",&x,&y);
                                     //x = 1, y = q;
                                     printf("%d\n",st.rmq(x-1,y-1).second);
                          }
    }
    return 0;
}
