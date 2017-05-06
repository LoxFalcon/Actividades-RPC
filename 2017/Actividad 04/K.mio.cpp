#include<bits/stdc++.h>
#define MAX_N 1000001 
#define MAX_LOG_N 20 
#define MP make_pair
#define F first
#define S second
using namespace std;
typedef pair<int,int> ii;
int A[1000001]={0};
int N,W,K;
int **STMin, **STMax;
class RMQStructure{
	public:
		RMQStructure(){
			for(int i=0;i<N;i++){
				STMin[i][0] = STMax[i][0] = i;
			}
			for(int j=1;(1<<j) <= N; j++){ //O(log N)
				for(int i=0;(i+(1<<j)-1)<N;i++){ //O(N)
					int minPrimer = STMin[i][j-1]; 
					int minSegund = STMin[i+(1<<(j-1))][j-1];					
					if(A[minPrimer] < A[minSegund]){
						STMin[i][j] = minPrimer;
					}else{
						STMin[i][j] = minSegund;
					}
					
					int maxPrimer = STMax[i][j-1]; 
					int maxSegund = STMax[i+(1<<(j-1))][j-1]; 
					if(A[maxPrimer] > A[maxSegund]){
						STMax[i][j] = maxPrimer;
					}else{
						STMax[i][j] = maxSegund;
					}
				}
			}
		}
		ii rmq(int a, int b){
			int k = (int)floor(log((double)b-a+1)/log(2.0));
			int minPrimer = STMin[a][k];
			int minSegund = STMin[b-(1<<k)+1][k];
			int mini=-1,maxi=-1;
			if(A[minPrimer]<A[minSegund]){
				mini = minPrimer;
			}else{
				mini = minSegund;
			}
			
			int maxPrimer = STMax[a][k];
			int maxSegund = STMax[b-(1<<k)+1][k];
			if(A[maxPrimer] > A[maxSegund]){
				maxi = maxPrimer;
			}else{
				maxi = maxSegund;
			}
			return MP(mini,maxi);
		}
};

void prepareStructures(){ //Solo se hace una vez para reducir el tiempo (espero...)
	STMin = new int*[MAX_N];
	STMax = new int*[MAX_N];
	for(int i=0;i<MAX_N;i++){
		STMin[i] = new int[MAX_LOG_N];
		STMax[i] = new int[MAX_LOG_N];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	prepareStructures();
	while(cin>>N>>W>>K && N>0){
		for(int i=0;i<N;i++){
			cin>>A[i];
		}
		RMQStructure RMQ;
		bool band = true;
		for(int i=W;i<N && band;i++){ //No se comprueba el 1
			int low = i-W;
			int high = i-1;
			
			ii res = RMQ.rmq(low,high);
			//printf("Comprobando A[%d] = %d, from (%d,%d) lowest %d, highest %d\n",i,A[i],low,high,A[mini],A[maxi]);
			if(abs(A[i]-A[res.F])>K || abs(A[i]-A[res.S])>K){
				band = false;
			}
		}
		if(band) cout<<"Yes.\n";
		else cout<<"No.\n";
	}
	return 0;
}
