#include <cstdio>
#include <iostream>
#include <cmath>
typedef long long int lli;

using namespace std;
lli sumaIm(int n){
    n--;
    lli res=n;
    res=res*res+(res<<1)+1;
    return res;
}
double xTestada(int n){
    double sum=sumaIm(n);
    return sum/n;    
}
lli sumaDif(int n){
    lli n1=n-1;
    lli sum1=2*n1*n1 + 3*n1;
    sum1+=(n1*(n1+1)*(2*n1+1)/3) *2+1;//no se si poner +1
    
    lli xt=(lli)xTestada(n);
    lli sum2=sumaIm(n)*2*xt;
    
    lli sum3=xt*xt*n;
//    cout<<"sum xi^2 "<<sum1<<" sum 2 "<<sum2<<" sum 3 " <<sum3<<"\n";
    return sum1-sum2+sum3;
}
int main(){
    int n;
    lli xt, dif;
    double res;
    cin>>n;
    while(n>0){
               dif=sumaDif(n);
               //cout<<dif<<"\n";
               res=(double)dif/(n-1.0);
               res=sqrt(res);
               printf("%.6f\n", res, res);
               cin>>n;
    }

    return 0;
}
