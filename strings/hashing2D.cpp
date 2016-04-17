
hash POO[2][N], HH[N][N], SS[N][N];
int K_cte[2] = {31, 1001};

void process_hash_2D(){

	POO[0][0] = POO[1][0] = 1;
	for(int i = 1; i < MAXN; i++){
		
		POO[0][i] = POO[0][i - 1] * K_cte[0];
		POO[1][i] = POO[1][i - 1] * K_cte[1];
	}
		
		
	int m1, m2;
	scanf("%d%d", &m1, &m2);
		
	for(int i = 0; i < m1; i++){ // leyendo tablero a hashear
			
		scanf("%s", s);	
		for(int j = 0; j < m2; j++){
				
			HH[i + 1][j + 1] = HH[i + 1][j] * K_cte[0] + (s[j] - 'a' + 1);
			SS[i + 1][j + 1] = SS[i][j + 1] * K_cte[1] + HH[i + 1][j + 1];
		}
	}

}

//hash abierto en la fila f1 y columna c1 cerrado en la fila f2, columna c2
//imcomplete

hash getHash_2D(int f1, int c1, int f2, int c2){
	
	hash mat1, mat2, mat;
	int ct = 0;
			
	//mat2 = SS[c2][f2] - SS[c1][c2 - c1] * POO[0][c2 - c1];
	//mat1 = SS[i - n1][j] - SS[i - n1][j - n2] * POO[0][n2];
				
	return mat;// = mat2 - mat1 * POO[1][n1];
}

