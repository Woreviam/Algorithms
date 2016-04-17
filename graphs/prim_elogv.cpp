
/*******************************************************************/
/************************ Prim ElogV ******************************/
/*******************************************************************/

struct node{
	
	int id, w;
	node(int _id, int _w){ id = _id; w = _w; }
	node(){}
};

bool operator <(const node &n1, const node &n2){ return n1.w > n2.w; }

vector<int>L[V], W[V];
int D[V];

int Prim(int source, int n){
	
	memset(D, -1, sizeof(int)*n);
	D[source] = 0;
	
	priority_queue<node>Q;
	Q.push(node(source, 0));
	
	int u, v, w, ans = 0;
	while(!Q.empty()){
	
		u = Q.top().id;
		Q.pop();
		
		for(int i = 0; i < L[u].size(); i++){
			
			v = L[u][i];
			w = W[u][i];
			
			if(D[v] == -1 || D[v] > w){
				
				D[v] = w;
				Q.push(node(v, D[v]));	
			}
		}
	}

	for(int i = 0; i < n; i++)ans += D[i];
	return ans;
}

