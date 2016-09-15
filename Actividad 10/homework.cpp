#include<bits/stdc++.h>
using namespace std;
int S;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&S);
		long double res = sqrt(.25+(S<<1))-.5;
		if((int)res==res){
			printf("%d\n",((int)res)-1);
		}else{
			printf("No solution\n");		
		}
	}
	return 0;
}
