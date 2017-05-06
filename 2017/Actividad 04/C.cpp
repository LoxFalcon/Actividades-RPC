#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct punto{
	ll x;
	ll y;
};

struct res{
	int left;
	int right;
	double leftD;
	double rightD;
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	punto ar[n+2];
	res out[n];
	for(int i=0;i<n+2;i++){
		cin>>ar[i].x;
		cin>>ar[i].y;
	}
	int indR=0;
	for (int i = 1; i <= n; i++) {
            bool x=true;
            int at=i-1,del=i+1;
            while(x){
                if(ar[i].y<ar[at].y){
                    out[indR].left=at;
                    out[indR].leftD=hypot(ar[i].x-ar[at].x, ar[i].y-ar[at].y);
                    x=false;
                }
                at--;
            }
            x=true;
            while(x){
                if(ar[i].y<ar[del].y){
                    out[indR].right=del;
                    out[indR].rightD=hypot(ar[i].x-ar[del].x, ar[i].y-ar[del].y);
                    x=false;
                }
                del++;
            }
            indR++;
        }
        for (int i = 0; i < n; i++) {
            printf("%d %d %.4lf %.4lf\n",out[i].left,out[i].right,out[i].leftD,out[i].rightD);
        }
	return 0;
}
