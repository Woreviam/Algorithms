
/******************************************************************************/
/****************************** SCC - Kosaraju ********************************/
/******************************************************************************/


vector<int>L[MAXV], LT[MAXV], topsort;
bool vis[MAXV];

void DFS(int u){
	
	if(vis[u])return;
	vis[u] = true;
	
	for(int i = 0; i < L[u].size(); i++)DFS(L[u][i]);
	topsort.pb(u);	
}

int comp[MAXV];
void DFS_reverse(int u, int id){
	
	if(comp[u] != -1)return;
	comp[u] = id;
	for(int i = 0; i < LT[u].size(); i++)DFS_reverse(LT[u][i], id);	
}

void getSCC(int n){
	
	memset(vis, false, sizeof vis);
	memset(comp, -1, sizeof comp);
	
	for(int i = 0; i < n; i++)DFS(i);	
	reverse(all(topsort));
	
	int id = 0;
	for(int i = 0, j; i < n; i++){
		
		j = topsort[i];
		if(comp[j] == -1)DFS_reverse(j, id), id++;
	}
}

