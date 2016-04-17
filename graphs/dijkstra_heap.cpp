
struct node{
 
	int id, dis;
	node(int _id, int _dis){ id = _id; dis = _dis; }
 
	node(){}
};
 
bool operator <(const node &n1, const node &n2){ return n1.dis > n2.dis; }
 
vector<int>W[MAXN];
int D[MAXN], P[MAXN];
 
void Dijkstra_heap(int source){
 
	fill(vis, vis + V, false);
	fill(D, D + V, -1);
 
	D[source] = 0;
 
	priority_queue<node>Q;	
	Q.push(node(source, 0));
 
	while(!Q.empty()){
 
		int u = Q.top().id;
		Q.pop();	
 
		if(vis[u])continue;
		vis[u] = true; 
 
		for(int i = 0; i < L[u].size(); i++){
 
			int v = L[u][i];	
			int w = W[u][i];
 
			if(D[v] == -1 || D[v] > D[u] + w){
 
				D[v] = D[u] + w;
				P[v] = u;
				Q.push(node(v, DIS[v]));
			}
		}
	}
}
