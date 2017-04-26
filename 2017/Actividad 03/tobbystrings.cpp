#include<bits/stdc++.h>
#define MAX_N 100005
#define MAX_A 26
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int N,Q,L; //N=#strings, Q=#queries, L=size of strings
int trie[MAX_N][MAX_A]={0};
int used[MAX_N][MAX_A]={0};
int strs[MAX_N]={0};
int nodeCount=1, casoActual = 0;
char str[MAX_N]={0};
queue<iii> q; // (index,node,cost)
void processLevel(int index, char tmp){
	int delta = (int)tmp - (int)'a';
	while(!q.empty()){
		iii u = q.front();
		int level = u.first;
		if(level>index){
			return;
		}else q.pop();
		int node = u.second.first;
		int cost  = u.second.second;
		if(cost>1) continue;
		if(cost == 1){
			if(used[node][delta]==casoActual){
				iii v = make_pair(index+1,make_pair(trie[node][delta],cost));	
				q.push(v);
			}
			continue;
		}
		for(int i=0;i<26;i++){
			if(used[node][i]<casoActual) continue;
			int extra=1;
			if(delta==i) extra = 0;
			iii v = make_pair(index+1,make_pair(trie[node][i],cost+extra));	
			q.push(v);
		}
	}
}
int getCount(){
	int sum=0;
	while(!q.empty()){
		iii u = q.front(); q.pop();
		int node = u.second.first;
		int cost = u.second.second;
		if(cost > 1) continue; //cost is too high
		else if(cost==0) sum+=strs[node]*L;
		else sum+=strs[node];
	}
	return sum;
}
int main(){
	//freopen("in.txt","r",stdin);
	while(scanf("%d%d%d\n",&N,&Q,&L)==3){
		casoActual++;
		nodeCount = 1;
		for(int i=0;i<N;i++){
			char tmp;
			int nodeIndex = 1;
			strs[nodeIndex] = 1;
			for(tmp=getchar();tmp!='\n';tmp=getchar()){
				int delta = (int)tmp - (int)'a';
				if(used[nodeIndex][delta]<casoActual){
					used[nodeIndex][delta] = casoActual;
					trie[nodeIndex][delta] = ++nodeCount;
					nodeIndex = trie[nodeIndex][delta];
					strs[nodeIndex] = 1;
				}else{
					nodeIndex = trie[nodeIndex][delta];
					strs[nodeIndex]++;
				}				
			}
		}
		for(int i=0;i<Q;i++){
			char tmp;
			q.push(make_pair(0,make_pair(1,0)));
			int j =0;
			for(tmp=getchar();tmp!='\n';tmp=getchar(), j++){
				processLevel(j,tmp);
			}
			int count = getCount();
			printf("%d\n",count);
		}
		
	}
	
	return 0;
}

