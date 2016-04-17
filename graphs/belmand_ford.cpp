
/*******************************************************************************/
/********************************* Belmand Ford ********************************/
/*******************************************************************************/

struct Edge{
 
	int u, v, w;
	Edge(int _u, int _v, int _w){ u = _u; v = _v; w = _w; }	
	Edge(){}
};
 
//Complejidad E * V
 
void belmand_ford(int source, vector<Edge> &E){
 
	fill(D, D + V, INF);
	D[source] = 0;
 
	int u, v, w;
	for(int i = 0; i < V - 1; i++){
 
		for(int j = 0; j < E.size(); j++){
 
			u = E[j].u;	
			v = E[j].v;
			w = E[j].w;
 
			if(D[v] > D[u] + w){
 
				D[v] = D[u] + w;
				P[v] = u;
			}
		}
	}
}
 
bool negative_cycle_detection(vector<Edge> &E){
 
	int u, v, w;
	for(int j = 0; j < E.size(); j++){
 
		u = E[j].u;	
		v = E[j].v;
		w = E[j].w;
 
		if(D[v] > D[u] + w)return true; // hay ciclo negativo
	}
	return false;
}


/*APLICACIONES */
 
/*
 
1.- Puede modelar sistema de inecuaciones de la forma  xi - xj <= cte
ya que todas las ecuaciones se pueden ver como desigualdades triangulares xi <= xj + cte de caminos cortos
Por lo tanto podemos modelar un grafo agregando arista dirigida (j, i) con peso cte
 
Donde luego de finalizar un camino corto tenemos: 
 
		xj = distancia corta de una fuente S a el nodo j
		xi = distancia corta de una fuente S a el nodo i
		cte = el peso de una arista entre los nodos i, j
 
		Luego de relajar con cualquier Algoritmo de Caminos cortos, Belmand, Dijstra o Warshal o cualquier otro
		las distancias obtenidas para cada nodo i será una solucion para la variable xi
 
		Nota: Si hay ciclo negativo no habrá solución debido a inconsistencia
			  Si los ctes en los pesos es no negativo, mejor es usar Dijstra
			  Se puede extender para igualdades xi - xj = cte (agregar condicion inversa)
 
Sea Ax <= b un sistema  de m diferentes constraints. 
----------------------------------------------------------------------------------------------
o Demotrar que el Algoritmo de Belmand Ford cuando finaliza maximiza:  
 
		Sumatoria(xi), tal que Ax <= b y xi <= 0 para todo xi
 
----------------------------------------------------------------------------------------------
o Demotrar que el Algoritmo de Belmand Ford cuando finaliza maximiza:  
 
		max{xi} - min{xi}, tal que Ax <= b					  
 
----------------------------------------------------------------------------------------------
2.- Ciclo Promedio Mínimo:
 
	o	Si se le quita una cierta cantidad X a cada arista del grafo el promedio en cualquier ciclo
		disminuye en X
 
			prueba: Sea un ciclo C de M aristas cuya suma de estas es W entonces su promedio es:
			promedio(C) = W/C
 
			luego si le quitamos a cada arista el valor X, tenemos:
			promedio(C) = (W - M*X)/M = W/M - X
 
 
	o	Se puede notar entonces que se puede hacer uso de Belmand Ford para saber lo minimo que debemos quitar a cada arista
		para no formar ciclos negativos y ese minimo sería el ciclo promedio minimo del grafo
 
		Notas: Se puede hacer uso de BinarySearch sobre el peso del ciclo, cumple para real y entero EV*log(maxW)
			   Uso de la observacion de Karp : complejidad O(E*V)
 
			   u* = minimo ciclo promedio
			   delta(s, v) : camino corto de fuente s hacia v
			   delta_k(s, v): camino corto de fuente s hacia v que consiste exactamente de k aristas
 
			   entonces: u* = min{ max{ (delta_n(s, v) - delta_k(s, v))/(n - k) /  0<=k<=n-1} / v pertenece a V }
 
*/
