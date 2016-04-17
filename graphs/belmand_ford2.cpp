
int Q[MAXN];
int improved_belmand_ford(int source, int target){
 
	fill(D, D + V, INF);
	D[source] = 0;
 
	int head = 0, tail = 0;
	Q[tail++] = source;
 
	while(head < tail){
 
		int u = Q[head++];
		if(D[u] < 0)return -1; // hay ciclo negativo
 
		for(int i = 0; i < L[u].size(); i++){
 
			int v = L[u][i];
			int w = W[u][i];
 
			if(D[v] > D[u] + w){
 
				D[v] = D[u] + w;
				Q[tail++] = v;
			}
		}
	}
 
	return D[target];
}
