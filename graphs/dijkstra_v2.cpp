
 
/*+++++++++++++++++++++++++++ Dijkstra V^2 	***************************/

int W[MAXN][MAXN];
 
void Dijkstra_V2(int source){
 
	fill(vis, vis + V, false); // set de optimos
	fill(D, D + V, -1);
 
	for(int i = 0; i < V; i++){
 
		int dis = INF, best;
 
		for(int j = 0; j < V; j++)
			if(!vis[j] && D[j] > 0 && D[j] < dis)dis = D[j], best = j;
 
		vis[best] = true;
 
		for(int j = 0; j < V; j++){
			if(!vis[j] && ( D[j] == -1 || D[j] > D[best] + W[best][j]) ){
 
				D[j] = D[best] + W[best][j];
				P[j] = best;
			}
		}
	}
}
