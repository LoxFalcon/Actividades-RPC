#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
vpll intervals;
map<ll,ll> best; //best[j] has the max painted section till the j-th wall
ll n; //Wall size
int k; //# Painters
ll sizeOfWall(ll s, ll e){
	return e-s+1;
}
ll longestPaint(){
	best[0] = 0;
	sort(intervals.begin(),intervals.end());
	map<ll,ll>::iterator it_s, it_e;
	for(int i=0;i<k;i++){
		int s = intervals[i].second;
		int e = intervals[i].first;
		it_s = best.lower_bound(s);
		it_s--;
		it_e = best.lower_bound(e);
		if(it_e == best.end()) { //This means it didn't find the e node but returned one after it (end() because it is sorted from interval's ends so there cannot be a higher it_e than e)
			it_e--;
		}
		int before = it_s->second + sizeOfWall(s,e);
		int after = it_e->second;
		int maxi = max(before,after);
		best[e] = maxi; //We don't need to check if it's a better solution at best[e], because we consider it with the var "after" and we choose the maximum
		cout<<"I: "<<i<<'\n';
		for (std::map<ll,ll>::iterator it=best.begin(); it!=best.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
	}
	it_e = best.end();
	it_e--; //We pick the most-right solution (it's going to have the max) from the end of the map
	
	return n-it_e->second; 
}
int main(){
	ll a,b;
	cin>>n>>k;
	for(int i=0;i<k;i++){
		cin>>a>>b;
		pll tmp = make_pair(b,a); //Invert the end and start, to sort the vector by the interval's end
		intervals.push_back(tmp);
	}
	cout<<longestPaint()<<'\n';
	
	return 0;
}
