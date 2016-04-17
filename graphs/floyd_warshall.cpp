
/******************************************************************************/
/****************************** FLoyd Warshall ********************************/
/******************************************************************************/


int D[MAXN][MAXN], CT[MAXN][MAXN], path[MAXN][MAXN];
 
void Floyd_Warshall(){
 
	for(int i = 0; i < V; i++){
 
		fill(D[i], D[i] + V, INF);
		fill(CT[i], CT[i] + V, false); //cierre transitivo
	}
 
	memset(path, -1, sizeof path);
	int u, v, w, E;
 
	scanf("%d%d", &V, &E);
	for(int i = 0; i < E; i++){
 
		scanf("%d%d%d", &u, &v, &w); // indexado desde [0-V]
		if(D[u][v] > w)D[u][v] = w, path[u][v] = u;
		CT[u][v] = true;
	}
 
	for(int k = 0; k < V; k++){ // considerando nodos intermedios de [0 a k]
		for(int i = 0; i < V; i++){
			for(int j = 0; j < V; j++){
 
				if(D[i][j] > D[i][k] + D[k][j]){
 
					D[i][j] = D[i][k] + D[k][j];
					path[i][j] = path[k][j]; // guarda el previo a j en el camino de i a j
				}
 
				CT[i][j] = CT[i][j] || (CT[i][k] && CT[k][j]);
			}
		}
	}
 
}
 
 
/* APLICACIONES FLOYD WARSHALL - IDEAS */
 
// Si el grafo es dirigido D[i][i] = minimo ciclo dirigido que contiene al nodo i
// Si el grafos es dirigido y D[i][i] < 0, i pertenece a un ciclo negativo
// Si el grafo es dinamico y se van agregando vertices la tabla D se actualiza en V^2 por vertice agregado
// Si se agrega arista W(u, v)se actualiza la tabla D intentando relajar todas las D[i][j]  a traves de W(u, v)
// Cierre transitivo CT[u][v] = C[u][v] or (C[u][k] and C[k][v])
// Si el grafo es dinamico en aristas, las actualizaciones de las transitividades es en V^2 dando una complejidad
// total de E*V^2
 
/* PROBLEMAS:
http://p...content-available-to-author-only...j.org/problem?id=1734
10987 - Antifloyd UVA
 */


