
/*****************************************************************************/
/*************************** SQRT-DESC  (testeado) **************************/
/*****************************************************************************/


int M[N], len;
//int A[N], n;
//interval [0, SQRT(n) - 1]  query-> numero de A[i] <= x, l <= i <= r

int query_sqrt(int l, int r, int x){
	
	//restos extremos
	int ans = 0;
		
	while(l%len > 0 && l <= r)ans += (A[l] <= x), l++;
	while(r%len > 0 && l <= r)ans += (A[r] <= x), r--;
	
	if(l <= r)ans += (A[r] <= x), r--;
	while(l <= r){
		
		if(M[l] <= x){
			
			int lo = l, hi = l + len - 1;
			while(lo < hi){
				
				int mid = lo + (hi - lo + 1)/2;
				if(M[mid] > x)hi = mid - 1;
				else lo = mid;
			}
			ans += lo - l + 1;
		}
		l += len;
	}
	return ans;
}



void update_sqrt(int pos, int val){
	
	int l = pos - pos%len;
	int r = min(l + len - 1, n - 1);
	int p = l;
	
	while(M[p] != A[pos])p++;
	M[p] = val;
	
	while(p < r && M[p] > M[p + 1])swap(M[p], M[p + 1]), p++;
	while(p > l && M[p] < M[p - 1])swap(M[p], M[p - 1]), p--;
	A[pos] = val;
}


void init_sqrt(int l, int r){

	int ini, fin;
	while(l <= r){
		
		ini = l;
		fin = min(l + len, n);
		
		sort(M + ini, M + fin);	
		l += len;
	}

}
void process(){
	
	len = int(sqrt(n) + EPS);
	for(int i = 0; i < n; i++){
			
		scanf("%d", &A[i]);
		M[i] = A[i];
	}	
	
	//ordenamiento de bloques
	init_sqrt(0, n - 1);
	
	int pos, val, l, r, x, q, m;
	scanf("%d", &m);
	
	for(int i = 0; i < m; i++){
			
		scanf("%s", q);
		if(q == 0)scanf("%d%d", &pos, &val), update_sqrt(pos - 1, val);
		else scanf("%d%d%d", &l, &r, &x), printf("%d\n", query_sqrt(l - 1, r - 1, x));
			
	}	
}

