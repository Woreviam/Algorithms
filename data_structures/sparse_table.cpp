
/******************************************************************************/
/**************************** Generic RMQ (testeado) **************************/
/******************************************************************************/

//Operaciones de rango de 0-> n(forward)
#define MAXLOG 18

int A[N], RMQ1[N][MAXLOG], RMQ2[N][MAXLOG]; //int n;
int opera(int a, int b){ return (a > b)? a:b; }


void process_rmq(int RMQ[][MAXLOG], int (*opera)(int, int)){
	
	for(int i = 0; i < n; i++)RMQ[i][0] = A[i];

	for(int j = 1; (1<<j) <= n; j++)
		for(int i = 0; i + (1<<j) <= n; i++)
			RMQ[i][j] = opera(RMQ[i][j - 1], RMQ[i + (1<<(j - 1))][j - 1]);

}

int query_rmq(int RMQ[][MAXLOG], int l, int r, int (*opera)(int, int)){
	
	int len = r - l + 1;
	int po = 31 - __builtin_clz(len);	
	return opera(RMQ[l][po], RMQ[r - (1<<po) + 1][po]);
}


/******************************************************************************/
/***************************** Generic RMQ2D(testeado)*************************/
/******************************************************************************/

//#define N 500
//#define MAXLOG 9

//Operaciones de rango de 0->n ^ 0->m (forward)
int B[N][N], pre[N][N][MAXLOG], RMQ2D[N][N][MAXLOG][MAXLOG];

void process_rmq2D(int n, int m){
	
	for(int lr = 0; (1<<lr) <= n; lr++){
		for(int lc = 0; (1<<lc) <= m; lc++){
			
			for(int i = 0; i + (1<<lr) <= n; i++){
				for(int j = 0; j + (1<<lc) <= m; j++){
					
					if(lr == 0 && lc == 0)RMQ2D[i][j][lr][lc] = B[i][j];
					else{
						
						if(lr == 0 && lc != 0)
							RMQ2D[i][j][lr][lc] = opera(RMQ2D[i][j][lr][lc - 1], RMQ2D[i][j + (1<<(lc - 1))][lr][lc - 1]);
						else
							RMQ2D[i][j][lr][lc] = opera(RMQ2D[i][j][lr - 1][lc], RMQ2D[i + (1<<(lr - 1))][j][lr - 1][lc]);
					}
				}
			}
			
		}
	}
	
}

// f1 <= c1 && f2 <= c2
int r1, r2;
int query_rmq2D(int f1, int c1, int f2, int c2){
	
	int len1 = f2 - f1 + 1;
	int len2 = c2 - c1 + 1;
	
	int po1 = 31 - __builtin_clz(len1);	
	int po2 = 31 - __builtin_clz(len2);
	
	r1 =  opera(RMQ2D[f1][c1][po1][po2], RMQ2D[f1][c2 - (1<<po2) + 1][po1][po2]);// same f1
	r2 =  opera(RMQ2D[f2 - (1<<po1) + 1][c1][po1][po2], RMQ2D[f2 - (1<<po1) + 1][c2 - (1<<po2) + 1][po1][po2]);// same f2 - 1<<po1 
	
	return opera(r1, r2);
}

