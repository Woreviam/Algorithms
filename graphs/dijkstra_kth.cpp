 
/*+++++++++++++++++++++++++++ Dijkstra E*KLOG(V*K) 	***************************/
 
set<int> Dkth[MAXN][MAXN]; //Dkth[s][u][k] kth distancia desde source s hacia nodo u
 
void Dijkstra_Kth(int source){
 
	priority_queue<node> Q;
	Q.push(node(source, 0));
 
	while(!Q.empty()){
 
		int u = Q.top().id;
		int dis = Q.top().dis;
 
		Q.pop();
 
		if(Dkth[source][u].size() == 2)continue;
		Dkth[source][u].insert(dis);
 
		for(int i = 0; i < L[u].size(); i++){
 
			int v = L[u][i];
			int w = W[u][i];
			Q.push(node(v, dis + w));	
		}
	}
}
