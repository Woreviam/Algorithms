
/******************************************************************************/
/**************************** Directed Eulerian Circuit ***********************/
/******************************************************************************/


int next[E], to[E], last[V], id = 0;

void addEdge(int u, int v){
	
	to[id] = v, next[id] = last[u], last[u] = id++;
}

bool vis[E];
int res[E], in[V], out[V], top = 0;

void DFS(int u){
	
	for(int &e = last[u]; ; e = next[e]){
	
		int v = to[e];
		if(vis[e])continue;
		
		vis[e] = true;
		DFS(v);
		
		res[top++] = e;
		if(e == -1)break;
	}
}

void solve(int n, int m){
	
	int sum = 0, dif = 0, source = 0;
	for(int i = 0; i < n; i++){
		
		if(in[i] == out[i])continue;
		if(abs(in[i] - out[i]) > 1)return false;
		
		if(out[i] - in[i] == 1)dif++, source = i;
		else dif--;
		
		sum++;
	}
	
	memset(vis, false, sizeof vis);	
	DFS(source);
	
	if((sum <= 2 && dif != 0) || top != m)return false;
		
	puts("YES");
	for(int i = 0; i < top; i++){
			
		if(i)printf(" ");
		printf("%d", res[i]);	
	}

}
