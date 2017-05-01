#include<bits/stdc++.h>
#define MP make_pair
#define F first
#define S second
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vii edges;
struct node
{
	int count;
	node *left, *right;

	node(int count, node *left, node *right):
		count(count), left(left), right(right) {}

	node* insert(int l, int r, int w);
};

node *null = new node(0, NULL, NULL); //see line 135

node * node::insert(int l, int r, int w)
{
	if(l <= w && w < r)
	{
		// With in the range, we need a new node
		if(l+1 == r)
		{
			return new node(this->count+1, null, null);
		}
		int m = (l+r)>>1;
		return new node(this->count+1, this->left->insert(l, m, w), this->right->insert(m, r, w));
	}

	// Out of range, we can use previous tree node.
	return this;
}

int query(node *a, node *b, int l, int r, int k)
{
	if(l+1 == r)
	{
		return l;
	}

	int m = (l+r)>>1;
	int count = a->left->count - b->left->count;
	if(count >= k)
		return query(a->left, b->left, l, m, k);

	return query(a->right, b->right, m, r, k-count);
}

int a[N], RM[N];
node *root[N];
int main(){
	int T,a,b;
	cin>>T;
	while(T--){
		cin>>N>>M;
		for(int i=0;i<M;i++){
			cin>>a>>b;
			edges.push_back(MP(b,a)); //Invertir el intervalo para ordenar por fin
			
		}
		sort(edges.begin(),edges.end());// Ordenamos por el fin de los intervalos		
	}
	
	
	return 0;
}
