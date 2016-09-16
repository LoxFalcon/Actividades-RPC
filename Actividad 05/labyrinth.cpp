#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#define MP make_pair
#define _F first
#define _S second
using namespace std;
char mapa[105][105][105]={0};
typedef pair<int,int> ii;
typedef pair<ii,ii> iiii;
int L,W,H; //Filas,Columnas,Pisos
int sI,sJ,sK; //S(i,j,k)
int dirI[4] = {0,1,0,-1}; //N,E,S,W,U,D
int dirJ[4] = {-1,0,1,0};
int dirK[2] = {1,-1};
bool esValido(int i, int j, int k){
    return k>=0 && k<H && j >=0 && j < L && i >= 0 && i <W;
}

iiii front;
int bfs(){
    queue<iiii> q; //(depth,i,j,k)
    q.push(MP(MP(0,sI),MP(sJ,sK)));
    while(!q.empty()){
        front = q.front(); q.pop();
        int a = front._F._S, b = front._S._F, c = front._S._S, depth = front._F._F;
        for(int i=0;i<4;i++){
            int x = a+dirI[i], y = b+dirJ[i];
            if(esValido(x,y,c)){
                if(mapa[c][y][x] == '.' || mapa[c][y][x] == '-'){
                    q.push(MP(MP(depth+1,x),MP(y,c)));
                    if(mapa[c][y][x]=='.') mapa[c][y][x] = '*';
                    else if(mapa[c][y][x]=='-') mapa[c][y][x] = '_';
                }else if(mapa[c][y][x] == 'E'){
                    return depth+1;
                }
            }
        }
        if(mapa[c][b][a]=='_'){
            for(int i=0;i<2;i++){
                int z = c+dirK[i];
                if(esValido(a,b,z) && mapa[z][b][a]=='-'){
                    q.push(MP(MP(depth+1,a),MP(b,z)));
                    mapa[z][b][a] = '_';
                }
            }
            mapa[c][b][a] = '*'; //se marca el elevador de donde baja/sube para no regresar
        }
    }
    return -1;
}
void printMap(){
    for(int k=0;k<H;k++){
        printf("Piso #%d:\n",k+1);
        for(int j=0;j<L;j++){
            for(int i=0;i<W;i++){
                putchar(mapa[k][j][i]);
            }
            putchar('\n');
        }
    }
}
int main(){
    char tmp;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>L>>W>>H && L>0){
        for(int k=0; k<H; k++){
            for(int j=0;j<L; j++){
                for(int i=0;i<W;i++){
                    cin>>mapa[k][j][i];
                    if(mapa[k][j][i]=='S'){
                        sI = i;
                        sJ = j;
                        sK = k;
                    }
                }
            }
        }
       // printMap();
        cout<<bfs()<<'\n';
       // printMap();
    }
    /*while(scanf("%d%d%d",&L,&W,&H) && L>0){
        fflush(stdin);
        for(int k = 0;k<H;k++){ //Pisos
            for(int j = 0; j < L ; j++){ //Filas
                int i=0;
                while((tmp=getchar())!='\n'){ //Columnnas
                    //printf("char! mapa[%d][%d][%d] = \'%c\'\n",k,j,i,tmp);
                    if(tmp=='S'){
                        sI = i;
                        sJ = j;
                        sK = k;
                    }
                    mapa[k][j][i++] = tmp;
                }
            }
            while(getchar()!='\n'){} //Línea vacía
        }
        //printMap();
        printf("%d\n",bfs());
        //printMap();
    }*/
    return 0;
}
