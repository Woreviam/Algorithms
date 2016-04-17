
/******************************************************************************/
/************************ Non Directed Eulerian Circuit ***********************/
/******************************************************************************/


int next[E], to[E], last[V], id = 0;

void addEdge(int u, int v){
	
	to[id] = v, next[id] = last[u], last[u] = id++;
	to[id] = u, next[id] = last[v], last[v] = id++;
}

bool vis[E];
int res[E], deg[V], top = 0;

void DFS(int u){
	
	for(int &e = last[u]; ; e = next[e]){
	
		int v = to[e];
		if(vis[e])continue;
		
		vis[e] = vis[e^1] = true;
		DFS(v);
		
		res[top++] = e;
		if(e == -1)break;
	}
}

bool solve(int n, int m){
	
	int ip = 0, source = 0;
	for(int i = 0; i < n; i++)if(deg[i]&1)ip++, source = i;
	
	memset(vis, false, sizeof vis);	
	DFS(source);
	
	if(ip > 2)return false;
	puts("YES");
	
	for(int i = 0; i < top; i++){
			
		if(i)printf(" ");
		printf("%d", res[i]);	
	}
	return true;
}


