#include<bits/stdc++.h>
#define LL long long int
using namespace std;
typedef vector<LL> vi;
vi branches;
int N;
bool possible(){
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			LL sum = branches[i]+branches[j];
			vi::iterator it = lower_bound(branches.begin(), branches.end(), sum);
			it--;
			int ind = it-branches.begin();
			if((*it)>=branches[j] && (*it)<sum && ind != j) return true;			
		}
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>N;
	branches.assign(N,0);
	for(int i=0;i<N;i++){
		cin>>branches[i];
	}
	sort(branches.begin(),branches.end());
	if(possible()) cout<<"possible\n";
	else cout<<"impossible\n";
	return 0;
}
