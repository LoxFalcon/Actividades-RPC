#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000002
#define MAX2 1000000002
#define endl '\n'
typedef long long ll;

ll arr[] = {2, 3, 5, 7, 37, 73, 313, 347, 353, 373, 383, 743, 797, 3467, 7643, 34673, 37643, 76367, 79397, 7693967, 799636997 };

int main(){
	//freopen("in.txt","r",stdin);
	int t,a,b,c;
	scanf("%d",&t);
	//cout<<arr[20]<<endl;
	while(t--){
		c=0;
		scanf("%d%d",&a,&b);
		
		for(int i=0; i<21 ;i++){
			if(arr[i]>=a && arr[i]<=b){
				c++;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}


