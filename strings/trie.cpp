
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// STRINGS  /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
/********************************* Generic Trie ******************************/
/*****************************************************************************/

int trie[N][26], terminal[N], nodes = 1;

void trie_add(char *s){
	
	int cur = 0;
	for(int i = 0; s[i]; i++){
	
		if(trie[cur][s[i] - 'a'] == 0)trie[cur][s[i]] = nodes++; 
		cur = trie[cur][s[i]]; 
	}
	
	terminal[cur]++;
}

bool trie_find(char *s){
	
	int cur = 0;
	for(int i = 0; s[i]; i++){
	
		if(trie[cur][s[i] - 'a'] == 0)return false;
		cur = trie[cur][s[i]]; 
	}
	
	return true;
}

/******************************************************************************/
/*************************** Generic Trie - lineal memory *********************/
/******************************************************************************/


int next[N], last[N], depth[N], C[2][N];
short int car[N];

//char s[N];
//int nodes = 1;

void add(char *s, int pos, int id){
    
    int cur = 0;
    for(int i = pos, j; s[i]; i++){
        
        for( j = last[cur]; j != 0; j = next[j] )
            if(car[j] == s[i] - 'a' + 1)break;
        
        if(!j && id == 0){
            
            if(nodes >= N)while(true){} // comprobar maxima cantidad de nodos
            j = ++nodes;
            car[j] = s[i] - 'a' + 1;
            
            next[j] = last[cur];
            
            last[cur] = j;
            depth[j] = depth[cur] + 1;
            
        }
        else if( !j && id == 1)break;
        
        cur = j;
        C[id][cur]++;
    }  
}

