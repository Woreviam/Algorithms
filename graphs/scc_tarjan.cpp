
/******************************************************************************/
/******************************** SCC Tarjan **********************************/
/******************************************************************************/

int des[MAXV], low[MAXV], pila[MAXV], timer, id_scc, top;

void DFS_scc(int u){
	
	pila[top++] = u;
	des[u] = low[u] = timer++;
	
	for(int e = 0; e != -1; e = next[e]){
		
		int v = to[e];	
		if(des[v] != -1)low[u] = min(low[u], des[v]);
		else{
			
			DFS_scc(v);
			low[u] = min(low[u], low[v]);
		}	
	}
	
	if(des[u] == low[u]){
		
		while(pila[top - 1] != u)comp[pila[--top]] = id_scc;	
		comp[pila[--top]] = id_scc; id_scc++;
	}
}

