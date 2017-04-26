#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define mod 1000000007

ll d,x,y;
ll t,a,n,n1,n2,areaTotal, supDer, uCol,c,nP,infIzq;
ll res;
ll modInverso[20];

void extendedEuclid(ll a, ll b){
    if(b==0){ d=a; x=1; y=0; return; }
    extendedEuclid(b, a%b);
    ll x1=y;
    ll y1=x-(a/b)*y;
    x=x1;
    y=y1;
}

void pre(){
    for(ll i=2; i<=12; i++){
        extendedEuclid(i, mod);
        x=(x+mod)%mod;
        modInverso[i]=x;
    }
}

ll sumI(ll a) {
    return ( ((a*(a+1)%mod)%mod) *modInverso[2])%mod;
}

ll sumI2(ll a){
    ull res=(a*(a+1)%mod)%mod;
    res= (res* (( ((2*a)%mod)+1 )%mod) )%mod;
    res = (res *modInverso[6])%mod;
    return res;
}

ll escaleraPar(ll a){
    if(a==2){ return 5; }
    a=a%mod;
    //AREA TOTAL - AREA PARTE INF. IZQ. - AREA PARTE INF. IZQ.+ ULTIMA COLUMNA DE ESCALERA
    n=((mod+a-2)%mod*modInverso[2])%mod; nP=(n+1)%mod;
    //AREA TOTAL
    n1=sumI(a);
    n2=sumI(nP);
    areaTotal=sumI(n1);
    //AREA PARTE SUP. DER.
    supDer=sumI(n2);
    supDer=(supDer*2)%mod;
    //AREA PARTE INF. IZQ.
    c=(((2+sumI(n)%mod)%mod)+n)%mod; //c=((2+sumI(n)%mod)+2*n)%mod;
    infIzq= ( ((c+mod-1)%mod) * sumI(n) )%mod;
    infIzq = (infIzq + ( ((n+1)%mod *sumI2(n))%mod) )%mod;
    //ULTIMA COLUMNA
    uCol = (sumI2(nP)*modInverso[2])%mod;
    uCol = ( uCol + (sumI(nP)*modInverso[2])%mod)%mod;

    //cout<<"n: "<<n<<" c: "<<c<<" nP: "<<nP<<" - AREA TOTAL "<<areaTotal<< " - AREA PARTE INF. IZQ. "<<infIzq;
    //cout<<" - AREA PARTE SUP. DER. "<<supDer<<" - U. COL. "<<uCol<<endl;
    //cout<<"sumI2: "<<sumI2(nP)<<endl;

    //RESPUESTA
    res=( ((areaTotal-supDer+mod)%mod- infIzq+mod)%mod+uCol )%mod;
    return res;
}

ll escaleraImpar(ll a){
    if(a==1){ return 1; }
    a=a%mod;
    //AREA TOTAL - AREA PARTE INF. IZQ. - AREA PARTE SUP. DER.
    n=((mod+a-1)%mod*modInverso[2])%mod;
    //AREA TOTAL
    n1=sumI(a);
    n2=sumI(n);
    areaTotal=sumI(n1);
    //AREA PARTE SUP. DER.
    supDer=sumI(n2);
    supDer=(supDer*2)%mod;
    //AREA PARTE INF. IZQ.
    c=((1+sumI(n)%mod))%mod; //c=((1+sumI(n)%mod)+n)%mod;
    infIzq=( ((c+mod-1)%mod) *sumI(n)%mod)%mod; //infIzq=( ((c-(n+1)+mod)%mod) *sumI(n)%mod)%mod;
    infIzq = (infIzq + (((n+1)%mod*sumI2(n))%mod))%mod;

    //cout<<"n: "<<n<<" c: "<<c<<" - AREA TOTAL "<<areaTotal<< " - AREA PARTE INF. IZQ. "<<infIzq<<" - AREA PARTE SUP. DER. "<<supDer<<endl;

    //RESPUESTA
    res=( ( (areaTotal-supDer+mod)%mod ) - infIzq+mod)%mod;
    return res;
}

void prueba(){
    //t=100000000000;
    t=10000000;
    for(ll i=1;i<=t;i++){
        //cin>>a;
        a=i;
        //cout<<"Case #"<<i<<": ";
        if(a%2==0){
            if(escaleraPar(a) < 0){
                cout<<"WA "<<a<<endl;
            }
        }else{
            //cout<<escaleraImpar(a)<<endl;
            if(escaleraImpar(a) < 0){
                cout<<"WA "<<a<<endl;
            }
        }

    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in","r",stdin);
    //freopen("out2","w",stdout);
    pre();
    //prueba();
    cin>>t;
    for(ll i=1;i<=t;i++){
        cin>>a;
        cout<<"Case #"<<i<<": ";
        if(a%2==0)
            cout<<escaleraPar(a)<<endl;
        else
            cout<<escaleraImpar(a)<<endl;
    }//*/
    return 0;
}

/*
500000004
WA 6054
WA 6056
WA 6064
WA 6070
WA 6072
WA 6078
WA 6080
WA 6086
WA 6088
WA 6096
WA 6102
WA 6104
WA 6110
*/
