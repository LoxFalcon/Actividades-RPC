struct edge{ 
	int to;
	int cap;
	int next;
};

class GrafoDeFlujo{
	public:
	vector<int> p,pEdge;
	int *first,edgeNum,MAX_V,MAX_E,f;
	edge *edges;
	
	grafoDeFlujo(int V, int E){
		MAX_V = V; MAX_E = E<<1;
		edges = new edge[MAX_E];
		first = new int [V];
		edgeNum = 0;
		fill(first,first+V,-1);
	}
	void agregarArista(int from, int to, int cap){
		edges[edgeNum].to = to;
		edges[edgeNum].cap = cap;
		edges[edgeNum].next = first[from];
		first[from] = edgeNum++;

		edges[edgeNum].to = from;
		edges[edgeNum].cap = 0;
		edges[edgeNum].next = first[to];
		first[to] = edgeNum++;
	}
	void augment(int v, int minEdge, int s){
		if(v == s){
			f = minEdge;
			return;
		}
		else if(p[v]!=-1){
			int res = edges[pEdge[v]].cap;
			augment(p[v],min(minEdge,res),s);
			edges[pEdge[v]].cap-=f;
			edges[pEdge[v]^1].cap+=f;
		}		
	}
	int maxFlow(int s, int t){
		int mf=0;
		while(1){
			f=0;
			vector<bool> vis(MAX_V);
			vis[s] = true;
			queue<int> q; q.push(s);
			p.assign(MAX_V,-1);
			pEdge.assign(MAX_V,-1);
			while(!q.empty()){
				int u = q.front(); q.pop();
				if(u==t) break;
				for(int cv = first[u]; cv != -1; cv = edges[cv].next){
					int v = edges[cv].to;
					int c = edges[cv].cap;
					if(c>0 && !vis[v]){
						vis[v] = true;
						q.push(v);
						p[v] = u; 
						pEdge[v] = cv;
					}
				}
			}
			augment(t,INF, s);
			if(f==0) break;
			mf+=f;
		}
		return mf;
	}	
	void clear(){
		fill(first,first+MAX_V,-1);
		edgeNum = 0;
	}
} grafo(MAX_N, MAX_E);

