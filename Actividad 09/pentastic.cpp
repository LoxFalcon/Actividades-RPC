#include<cstdio>
#define INF 1000000000
using namespace std;
int pentas[5];
bool valid(){
	for(int i=0;i<5;i++)
		if(pentas[i] < 0) return true;
	return false;
}
void solve(){
	while(valid()){
		int index=-1, min=INF;
		for(int i=0;i<5;i++){
			if(pentas[i]<min){
				index = i;
				min = pentas[i];
			}
		}
		int izq = (index == 0 ? 4 : index-1);
		int der = (index == 4 ? 0 : index+1);
		pentas[izq] += pentas[index];
		pentas[der] += pentas[index];
		pentas[index] = -pentas[index];
	}
	
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<5;j++){
			scanf("%d",&pentas[j]);
		}		
		solve();
		printf("Pentagon #%d:\n",i);
		for(int j=0;j<5;j++){
			if(j) putchar(' ');
			printf("%d",pentas[j]);
		}
		putchar('\n');
	}
	return 0;
}
