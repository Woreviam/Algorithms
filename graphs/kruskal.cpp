
/*******************************************************************/
/************************ Kruskal ElogV ****************************/
/*******************************************************************/

int P[V];
int Find(int x){
	
	if(x == P[x])return x;
	return P[x] = Find(P[x]);	
}

void Union(int x, int y){
	
	x = Find(x);
	y = Find(y);
	P[x] = y;	
}

pair<int, int>edge[V];
int W[E];

int Kruskal(int n, int m){
	
	for(int i = 0; i < n; i++)P[i] = i;
	int u, v, w, ans = 0;
	
	for(int i = 0; i < m; i++){
		
		u = Find(u);
		v = Find(v);
		
		if(Find(u) == Find(v))continue;
		Union(u, v);
		
		ans += W[i];
	}
	return ans;
}
