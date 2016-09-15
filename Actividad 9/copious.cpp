#include <iostream>
#include <string>
#include<stdio.h>
#include<cstring>
using namespace std;
//string dic[101];
char dic[101][22];
int sizes[101];
char tmp[22];
int n,m,tSize;
int cantidadPalabras(){
    /*int t = strlen(tmp);*/ int cont=0;
	/*cout<<"Tamaño: "<<t<<" y "<<tSize<<'\n';
	for(int z = 0;z<t;z++){
		cout<<tmp[z]<<" ";
	}
	cout<<'\n';*/
    for(int i=0;i<n;i++){
        if(tSize==sizes[i]){
            bool match = true;
            for(int j=0;j<tSize;j++){
                if(tmp[j]!='-'&&tmp[j]!=dic[i][j]){
                    match = false;
                    break;
                }
            }
            if(match){ printf("%s\n",dic[i]); cont++;}
        }
    }
    return cont;
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int caso=1;
    //while(scanf("%d",&n)){
	scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",dic[i]);
            sizes[i] = strlen(dic[i]);
        }
	scanf("%d",&m);
        for(int i=0;i<m;i++){
	    scanf("%s",tmp);
	    tSize = strlen(tmp);
	    printf("Word #%d: %s\n",caso++,tmp);
            int res = cantidadPalabras();
	    printf("Total number of candidate words = %d\n",res);
        }
    
    return 0;
}
