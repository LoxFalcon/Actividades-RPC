#include<bits/stdc++.h>
#define MAX_K 1001
using namespace std;
typedef map<int,int> mii;
int K,N;
map<int,int> freq;
int reps[MAX_K]={0};
int findNumber(int rep){
	for(int i=1;i<=K;i++){
		if(reps[i]==rep) return i;
	}
	return -1;
}
bool printSolution(){
	if(freq.size() == 2){
		mii::iterator it1 = freq.begin();
		mii::iterator it2 = freq.begin(); it2++;
		if((it2->first - it1->first) == 1){
			if(it1->second == 1){
				cout<<'+'<<findNumber(it1->first)<<'\n';
				return true;
			}else if(it2->second == 1){
				cout<<'-'<<findNumber(it2->first)<<'\n';
				return true;
			}
		}
	}else if(freq.size()==3){
		mii::iterator it1 = freq.begin();
		mii::iterator it2 = freq.begin(); it2++;
		mii::iterator it3 = freq.begin(); it3++; it3++;
		if(it1->second == 1 && it3->second == 1 && (it3->first - it1->first) == 2){
			cout<<'-'<<findNumber(it3->first)<<" +"<<findNumber(it1->first)<<'\n';
			return true;
		}			
	}
	return false;
}
int  main(){
	cin>>K>>N;
	freq[0] = K;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		if(freq[reps[tmp]]==1){
			freq.erase(reps[tmp]);
		}else{
			freq[reps[tmp]]--;
		}
		reps[tmp]++;
		if(freq.count(reps[tmp])==0){
			freq[reps[tmp]] = 0;
		}
		freq[reps[tmp]]++;
	}
	if(!printSolution()){
		cout<<"*\n";
	}
	return 0;
}
