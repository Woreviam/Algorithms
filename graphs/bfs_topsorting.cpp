
#define MAXV 100005
#define MAXE 100005

int to[MAXE], next[MAXE], last[MAXV], E;
void addEdge(int u, int v){	
	
	to[E] = v, next[E] = last[u], last[u] = E++; 
} 

int indegree[MAXV], topsort[MAXV], Q[MAXV], len = 0;
void topsorting_BFS(){
 
	int head = 0, tail = 0;
	for(int i = 0; i < V; i++)
		if(indegree[i] == 0)Q[tail++] = i;
	
	while(head < tail){
 
		int u = Q[head++];	
		topsort[len++] = u;
 
		for(int e = last[u]; e != -1; e = next[e]){
 
			int v = to[e];
			indegree[v]--;
			if(indegree[v] == 0)Q[tail++] = v;
		}	
	}
 
	if(len < V)puts("Existe un ciclo");
	else for(int i = 0; i < V; i++)cout << topsort[i] << endl;
}

