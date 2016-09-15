#include<cstdio>
using namespace std;
int medallas[6];
int ganaPrimer(){
	return (medallas[0]+medallas[1]+medallas[2]) > (medallas[3]+medallas[4]+medallas[5]) ? 1 : 0;
}
int ganaSegundo(){
	if(medallas[0]==medallas[3]){
		if(medallas[1]==medallas[4]){
			if(medallas[2]>medallas[5]){
				return 2;
			}
		}else if(medallas[1]>medallas[4]){
			return 2;
		}
	}else if(medallas[0]>medallas[3]){
		return 2;
	}
	return 0;
}
int main(){
	int n;
	scanf("%d",&n);	
	while(n--){
		for(int i=0;i<6;i++){
			scanf("%d",&medallas[i]);
			if(i>0) putchar(' ');
			printf("%d",medallas[i]);
		} 
		putchar('\n');
		int res = ganaPrimer() + ganaSegundo();
		switch(res){
			case 0:
				printf("none\n");
				break;
			case 1:
				printf("count\n");
				break;
			case 2:
				printf("color\n");
				break;
			case 3:
				printf("both\n");
				break;
		}		
	}
	return 0;
}
