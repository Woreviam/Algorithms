
/*******************************************************************/
/************************** Prim V^2 *******************************/
/*******************************************************************/

int D[V], W[V][V];
bool vis[V];

int Prim2(int source, int n){
	
	int best = source, ans = 0;
	
	memset(D, -1, sizeof(int)*n);
	D[source] = 0;
	
	for(int i = 0; i < n; i++){
		
		for(int j = 0; j < n; j++)
			if(!vis[j] && D[j] != -1 && D[best] >= D[j])best = j;
		
		vis[best] = true;
		ans += D[best];
		
		for(int j = 0; j < n; j++)
			if(D[j] == -1 || D[j] > W[best][j])D[j] = W[best][j];	
	}
	
	return ans;
}


