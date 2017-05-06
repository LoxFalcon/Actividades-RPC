#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 3000010

int maxi[MAX];
int mini[MAX];
int N,v1,v2;

void sum(int a, int b){
    a+=N; b+=N;
    //int s=0;
    int s1,s2,s3,s4,st1,st2,dif;
    v1=1<<30, v2=-1;
    while(a<=b){
        s1=s2=1<<30;
        s3=s4=-1;
        if(a%2==1){ s1 = mini[a]; s3 = maxi[a++]; }
        if(b%2==0){ s2 = mini[b]; s4 = maxi[b--]; }
        st1=s1<s2 ? s1 : s2;
        st2=s3>s4 ? s3 : s4;
        v1=st1<v1 ? st1 : v1;
        v2=st2>v2 ? st2 : v2;
        a/=2; b/=2;
    }
    //cout<<"v1: "<<v1<<" v2: "<<v2<<endl;
    //return s;
}

void add(int k, int x){
    k+=N;
    maxi[k]=x;
    mini[k]=x;
    for(k/=2; k>=1; k/=2){
        maxi[k]=maxi[2*k]>maxi[2*k+1] ? maxi[2*k] : maxi[2*k+1];
        mini[k]=mini[2*k]<mini[2*k+1] ? mini[2*k] : mini[2*k+1];
    }
}

void reset(){
    for(int i=0; i<MAX; i++){
        maxi[i]=-1;
        mini[i]=1<<30;
    }
}

int pot2(int n){
    int i=1;
    while(i<n){
        i<<=1;
    }
    return i;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("K.in","r",stdin);
    int n,w,k,x,a,b,dif;

    while(cin>>n>>w>>k && (n||w||k)){
        reset();
        N=pot2(n);
        for(int i=0; i<n; i++){
            cin>>x;
            add(i, x);

        }
        int t=w;
        bool band=true;
        //cout<<"n: "<<n<<" N: "<<N<<" w: "<<w<<endl;
        while(t<n && band){
            a=t-w, b=t-1;
            sum(a,b);
            //cout<<"t: "<<t<<" a: "<<a<<" b: "<<b<<" band: "<<band<<" ";
            //cout<<"("<<a<<","<<b<<") arr[t]: "<<maxi[t+N]<<" - v1: "<<v1<<" v2: "<<v2<<" ";
            dif=abs(maxi[t+N]-v1);
            //cout<<"dif1: "<<dif<<" ";
            if(dif>k) band=false;
            dif=abs(maxi[t+N]-v2);
            //cout<<"dif2: "<<dif<<endl;
            if(dif>k) band=false;
            //cout<<"v1: "<<v1<<" v2: "<<v2<<endl;
            t++;
        }
        if(band)
            cout<<"Yes.\n";
        else
            cout<<"No.\n";
    }
    return 0;
}

