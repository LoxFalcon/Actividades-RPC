#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
map<char,int> mapita;
char str[100005]={0};
int tam;
char swp(char x){
    switch(x){
        case '2':
            return '5';
        case '5':
            return '2';
        case '6':
            return '9';
        case '9':
            return '6';
        default:
            return x;
    }
}
int res(int x){
    char tmp[10]={0};
    sprintf(tmp,"%d",x);
    int len = strlen(tmp);
    for(int i=0;i<len;i++){
            tmp[i] = swp(tmp[i]);
    }
    sscanf(tmp,"%d",&x);
    return x;
}
int main(){
    while(scanf("%s",str)==1){
        tam = strlen(str);
        mapita.clear();
        int cont=1;
        for(int i=0;i<tam;i++){
            if(!mapita.count(str[i])){
                mapita[str[i]] = cont;
                cont++;
            }
            printf("%d",res(mapita[str[i]]));
        }
        putchar('\n');
    }

    return 0;
}
