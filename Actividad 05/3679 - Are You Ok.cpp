#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#define eps 1e-6
#define PI atan(-1)
#define MAXV 505
#define INF 10000000
using namespace std;
typedef long long ll;
class Point{
public:
    double x,y;
    Point(double a = 0, double b = 0):
    	x(a), y(b) {}
    Point operator-(const Point &a) const{
        return Point(x - a.x, y - a.y);
    }
    bool operator==(const Point &a) const {
    	return fabs(x - a.x) < eps && fabs(y - a.y) < eps;
    }
};
Point poligono[MAXV];
double dot(Point a, Point b){
    return a.x*b.x + a.y*b.y;
}
double cross(Point o, Point a, Point b) {
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
double cross2(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}
int between(Point a, Point b, Point c) {
    return dot(c - a, b - a) >= -eps && dot(c - b, a - b) >= -eps;
}
int onSeg(Point a, Point b, Point c) {
    return between(a, b, c) && fabs(cross(a, b, c)) < eps;
}
int solve(int N, Point p){
    int i,j, c =0;
    for(i = 0, j = N-1; i < N;j = i++){
        if(poligono[i] == poligono[j]) continue;
        if(onSeg(poligono[i],poligono[j],p)) return 0;
        if (poligono[i].y > p.y != poligono[j].y > p.y &&
        p.x < (poligono[j].x-poligono[i].x)*(p.y-poligono[i].y)/(poligono[j].y-poligono[i].y) + poligono[i].x) c++;
    }
    return c&1;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T,A,B,c;
    Point aux;
    cin >> T;
    while(T--){
        c = 0;
        cin >> A >> B;
        for(int x=0;x<A;x++)
            cin >> poligono[x].x >> poligono[x].y;
        while(B--){
            cin >> aux.x >> aux.y;
            if(solve(A,aux)) c++;
        }
        cout << c << "\n";
    }
}
