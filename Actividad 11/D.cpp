#include <bits/stdc++.h>
#define MAX 33000
using namespace std;
typedef long long int lli;
vector<int> prim;

int fact[20], pot[20], fp;
lli A,B,C,D;
void criba(){
    bitset<MAX+10> bs;
    bs.set();
    bs[0]=bs[1]=0;
    for(lli i=2;i<=MAX;i++){
        if(bs[i]){
            for(lli j=i*i;j<=MAX;j+=i)
                bs[j]=0;
            prim.push_back((int)i);
        }
    }
}

void factor(lli n){
    lli i=0, pr, p;
    fp=0;
    pr=prim[i];
    while(pr*pr<=n){
        if(n%pr==0){
            p=0;
            do{
                n/=pr;
                p++;
            }while(n%pr==0);
            fact[fp]=pr;
            pot[fp]=p;
            fp++;
        }
        pr=prim[++i];
    }
    if(n!=1){
        fact[fp]=n;
        pot[fp]=1;
        fp++;
    }
}

lli minN;
void comb(int i, lli act){
    if(i==fp){
        if(D%act==0)return ;
        if(act%B==0){
            return ;
        }
        minN= min(minN, act);
        return ;
    }
    lli P=act;
    for(int c=0;c<=pot[i];c++){
        if(P%B==0){
            break;
        }
        comb(i+1, P);
        P*=fact[i];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    lli i,j;
    lli uno=1;
    criba();
    while(cin>>A>>B>>C>>D){
        if(C%A !=0){
            cout<<"-1\n";
            continue ;
        }
        factor(C/A);
        j=minN=uno<<32;
        //cout<<j<<"*\n";
        comb(0,A);
        
        /*cout<<(C/A)<<"\n";
        for(i=0;i<fp;i++){
            cout<<fact[i]<<" "<<pot[i]<<", ";
        }
        cout<<"\n";*/

        if(minN==j)cout<<"-1\n";
        else cout<<minN<<"\n";
    }
    return 0;
}