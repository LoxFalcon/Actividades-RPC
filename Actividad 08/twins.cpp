#include<cstdio>
using namespace std;
int set[10]={0};
int main(){
	int e,n;
	scanf("%d",&n);
	while(n--){
		e=0;
		for(int i=0;i<10;i++){
			scanf("%d",&set[i]);
			if(set[i]==18){
				e+=1;
			}else if(set[i]==17){
				e+=2;
			}
		}
		for(int i=0;i<10;i++){
			if(i>0) putchar(' ');
			printf("%d",set[i]);
		}
		putchar('\n');
		switch(e){
			case 0:
				printf("none\n");
				break;
			case 1:
				printf("mack\n");
				break;
			case 2:
				printf("zack\n");
				break;
			case 3:
				printf("both\n");
				break;
		}
	}
	return 0;
}
