
/******************************************************************************/
/******************************  Generic BIT1D  *******************************/
/******************************************************************************/

/* inline int opera(int num1, int num2){ return min(num1, num2); } */

int ftree[N];
int query(int pos){
	
	int ans = 0;
	for(int i = pos; i > 0; i -= i&-i)ans = opera(ans, ftree[i]);
	return ans;	
}

void update(int pos, int val){
	
	for(int i = pos; i < N; i += i&-i)ftree[i] = opera(val, ftree[i]);	
}

/******************************************************************************/
/******************************  Generic BIT2D  *******************************/
/******************************************************************************/

int ftree2D[N][N];

int query(int fil, int col){
	
	int ans = 0;
	for(int i = fil; i > 0; i -= i&-i)
		for(int j = col; j > 0; j -= j&-j)ans += ftree2D[i][j];
	return ans;	
}

void update(int fil, int col, int val){
	
	for(int i = fil; i > 0; i -= i&-i)
		for(int j = col; j > 0; j -= j&-j)ftree2D[i][j] += ftree2D[i][j];	
} 


/******************************************************************************/
/********************** Generic BIT-range_update (testeado) *******************/
/******************************************************************************/

long long ftree_range[2][N];

inline long long query_range(int pos, int id){
	
	long long ans = 0;
	for(int i = pos; i > 0; i -= i&-i)ans += ftree_range[id][i];
	return ans;
}

inline void update_range(int pos, int id, long long val){
	
	for(int i = pos; i < N; i += i&-i)ftree_range[id][i] += val;	
}

inline long long QUERY(int pos){
	
	return query_range(pos, 0) * pos - query_range(pos, 1);
}

inline void UPDATE(int l, int r, long long val){
	
	update_range(l, 0, val);
	update_range(r + 1, 0, -1 * val);
	
	update_range(l, 1, (l - 1) * val);
	update_range(r + 1, 1, -1 * r * val);
}

