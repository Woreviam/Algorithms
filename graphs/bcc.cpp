
/******************************************************************************/
/********************** Puntos de Art, Puentes, Biconnected *******************/
/******************************************************************************/

int des[MAXV], low[MAXV], pila[MAXE], timer;
int bcc[MAXE], id_bcc;

bool punto[MAXV], ponte[MAXE];

void DFS(int u, int pd){
	
	low[u] = des[u] = timer++;	
	int sons = 0;
	
	for(int e = last[u]; e != -1 ; e = next[e]){
		
		int v = to[e];
		if(v == pd)continue;
		
		pila[top++] = e;
		if(des[v] != -1)low[u] = min(low[u], des[v]);
		else{
		
			DFS(v, u); sons++;
			low[u] = min(low[u], low[v]);
			
			if(low[v] > des[u])ponte[e] = true;	
			if(low[v] >= des[u]){
				
				punto[u] = true;
				while(pila[top - 1] != e)bcc[pila[--top]] = id_bcc;
				bcc[pila[--top]] = id_bcc; id_bcc++;	
			}
		}
	}
	
	if(pd == -1 && sons <= 1)punto[u] = false;
}


