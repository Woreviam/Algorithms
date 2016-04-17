
/*****************************************************************************/
/********************************* Generic LCA ******************************/
/*****************************************************************************/

int P[MAXLOG][N], H[N];


int getLCA(int u, int v){
    
    if(u == v)return u;
    if(H[u] < H[v])swap(u, v);// u es el de mayor altura
    
    int bit = 31 - __builtin_clz(H[u]);
        
    for(int i = bit; i >= 0; i--)
        if(H[P[i][u]] > H[v])u = P[i][u];  
	
	if(H[u] > H[v])u = P[0][u];
	if(u == v)return u; //misma rama
	
    bit = 31 - __builtin_clz(H[u]);
    
    for(int i = bit; i >= 0; i--)
        if(P[i][u] != P[i][v])u = P[i][u], v = P[i][v];
    
    
    return P[0][u];
}

/*****************************************************************************/
/********************************* LCA Offline ******************************/
/*****************************************************************************/


vector<int>L[N]; 
vector<pair<int, int> >Q[N];

int P[N];
int Find(int u){
	
	if(u == P[u])return u;
	return P[u] = Find(P[u]);
}

void Union(int u, int v){
	
	u = Find(u);
	v = Find(v);
	P[u] = v;	
}

int res[N];
bool vis[N];

void DFS(int u, int pd){
	
	vis[u] = true;
	int v, id;
	
	for(int i = 0; i < L[u].size(); i++){
		
		v = L[u][i];
		if(v == pd || vis[v])continue;
		
		DFS(v, u);
		Union(v, u);	
	}
	
	for(int i = 0; i < Q[u].size(); i++){
		
		v = Q[u][i].first;
		id = Q[u][i].second;
		if(vis[v])res[id] = Find(v);
	}
}

int main(){

	int n;
	scanf("%d", &n);
	
	int u, v;
	for(int i = 0; i < n - 1; i++){
		
		scanf("%d%d", &u, &v);
		L[u].pb(v);
		L[v].pb(u);
	}
	
	for(int i = 1; i <= n; i++)P[i] = i;
	memset(vis, false, sizeof(bool)*(n + 1));
	
	int m;
	scanf("%d", &m);
	
	for(int i = 0; i < m; i++){
		
		scanf("%d%d", &u, &v);
		Q[u].pb(make_pair(v, i));
		Q[v].pb(make_pair(u, i));
	}
	
	DFS(1, 1);
	for(int i = 0; i < m; i++)printf("%d\n", res[i]);
	

}
