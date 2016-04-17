
/*****************************************************************************/
/************************ Generic Segment Tree *******************************/
/*****************************************************************************/


#define v1 2 * node
#define v2 2 * node + 1
#define me (ini + fin)/2

struct nod{
	
	int p1, flag;
	
	nod(int _p1, bool _flag){ p1 = _p1; flag = _flag; }
	nod(){}
};

nod tree[4 * N];
nod neutro = nod(0, 0);

bool operator == (const nod &n1, const nod &n2){ return n1.p1 == n2.p1 && n1.flag == n2.flag; } 
nod operator +(const nod &n1, const nod &n2){ 
	
	if(n1 == neutro)return n2;
	if(n2 == neutro)return n1;
	return nod(n1.p1 + n2.p1, 0); /*Modficar con la operacion */
}

void push(int node, int ini, int fin){
	
	if(tree[node].flag == 0)return;
	
	/* Modificar tree[node].p1, p2  etc*/
	
	if(ini != fin){
		
		tree[v1].flag += tree[node].flag;
		tree[v2].flag += tree[node].flag;
	}
	
	tree[node].flag = 0;
}

nod query(int node, int ini, int fin, int b, int e){
	
	push(node, ini, fin);
	if(fin < b || ini > e)return neutro;
	if(ini >= b && fin <= e)return tree[node];
	
	nod val1 = query(v1, ini, me, b, e);
	nod val2 = query(v2, me + 1, fin, b, e);
	
	tree[node] = tree[v1] + tree[v2];
	return val1 + val2;
	
}

void update(int node, int ini, int fin, int b, int e, int val){
	
	push(node, ini, fin);	
	if(fin < b || ini > e)return;
	
	if(ini >= b && fin <= e){
		
		tree[node].flag += val;
		push(node, ini, fin);
		return;
	}
	
	update(v1, ini, me, b, e, val);
	update(v2, me + 1, fin, b, e, val);
	
	tree[node] = tree[v1] + tree[v2];
}

/*******************************************************************************/
/************************ Generic Segment tree2D(testeado) *********************/
/*******************************************************************************/

#define v1 2 * node
#define v2 2 * node + 1
#define me (ini + fin)/2

/*
struct nod{
	
	long long maxi, mini;
	nod(long long _maxi, long long _mini){ maxi = _maxi; mini = _mini; }
	nod(){}
	nod operator +(const nod &n){ return nod(max(maxi, n.maxi), min(mini, n.mini)); }
}neutro(-INF, INF);
*/

nod tree2D[4 * N][4 * N];

int f1, f2, c1, c2, n, m;

void update1D(int level, int node, int ini, int fin, long long val, bool leaf){
	
	if(ini > c2 || fin < c1)return;
	if(ini >= c1 && fin <= c2){	
		
		if(leaf)tree2D[level][node] = nod(val, val); 
		else tree2D[level][node] = tree2D[2 * level][node] + tree2D[2 * level + 1][node];
		return;
	}
	
	update1D(level, v1, ini, me, val, leaf);
	update1D(level, v2, me + 1, fin, val, leaf);
	
	tree2D[level][node] = tree2D[level][v1] + tree2D[level][v2]; 
}

void update2D(int node, int ini, int fin, long long val){
	
	if(ini > f2 || fin < f1)return;
	if(ini >= f1 && fin <= f2)return update1D(node, 1, 0, m - 1, val, 1);
	
	update2D(v1, ini, me, val);
	update2D(v2, me + 1, fin, val);
	
	return update1D(node, 1, 0, m - 1, val, 0);
}

nod query1D(int level, int node, int ini, int fin){
	
	if(ini > c2 || fin < c1)return neutro;
	if(ini >= c1 && fin <= c2){ return tree2D[level][node];} 
	
	return query1D(level, v1, ini, me) + query1D(level, v2, me + 1, fin);	
}

nod query2D(int node, int ini, int fin){
	
	if(ini > f2 || fin < f1)return neutro;
	if(ini >= f1 && fin <= f2)return query1D(node, 1, 0, m - 1);  
	
	return query2D(v1, ini, me) + query2D(v2, me + 1, fin);	
}

