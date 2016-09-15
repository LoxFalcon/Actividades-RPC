#include<cstdio>
#include<algorithm>
#include<cmath>
#define LLI long long int
#define INF 1000000000
using namespace std;
LLI x,y,d,R,S,Q,newS,newR;
void extendedEuclid(LLI a, LLI b){
	if(b == 0) {
		x = 1; 
		y = 0; 
		d = a; 
		return;
	}
	extendedEuclid(b, a%b);
	LLI x1 = y;
	LLI y1 = x - (a/b) * y;
	x = x1;
	y = y1;
}
LLI gcd(LLI a, LLI b){
	return b == 0 ? a: gcd(b, a%b);
}
LLI probarSoluciones(long double n, LLI xg, LLI yg){
	int a = n;
	LLI minA = INF, minB = INF; int res = INF;
	for(;;a--){		
		
		LLI solX = xg + newS * a;
		LLI solY = yg - newR * a;
		//printf("n = %d, x = %lld, y = %lld\n",a,solX,solY);
		if(solX>0 && solY>0){
			return a;
		}
	}
	return res;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld",&R,&S,&Q);
		
		LLI gtd = abs(gcd(R,S));
		//printf("GTD = %lld\n",gtd);
		newR = R / gtd, newS = S/gtd;
	//	printf("%lld %lld\n",newR,newS);
		extendedEuclid(newR,newS);
	//	extendedEuclid(R,S);
		LLI g = (long double)Q / gcd(R,S);
		LLI xg = x * g;
		LLI yg = y * g;
		long double n1 = ceil(-xg / (long double)newS);
		n1 += 3.0;
		LLI n = probarSoluciones(n1, xg, yg);
		LLI solX = xg + newS * n;
		LLI solY = yg - newR * n;
		//printf(" n1 %Lf\n",n1);
		//printf("n = %lld\n xg = %lld, yg = %lld\n",n,xg,yg);
		//printf("(X,Y) = (%lld,%lld)\n",solX,solY);
		//printf("x %lld y %lld\n",x,y);
		//printf(" gcd(R,S) = %lld, Q/gcd(R,S) = %lld\n",gcd(R,S),g);
		printf("%lld %lld\n",solX,solY);
	}
	return 0;
}

