#include<cstdio>
using namespace std;
int x,y,total;
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		total = y = 0;
		scanf("%d",&x);
		y = x;	
		do{
			scanf("%d",&x);
			if(x==0) break;
			if((y*2)<x){ //Se fueron algunos
				total += x-(y*2);
				
			}
			y = x;						
		}while(x);
		printf("%d\n",total);
	}
	return 0;
}
