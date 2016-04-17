
/******************************************************************************/
/******************************* DFS_ITERATIVE*********************************/
/******************************************************************************/

int pila[N], des[N], fin[N];

void DFS_iterative(int source){
    
    int top = 0, timer = 1;
    pila[top++] = source;
    
    while(top > 0){
        
        int u = pila[top - 1];
        if(!des[u]){
            
            des[u] = timer++;  
            for(int i = 0; i < L[u].size(); i++){
            
                int v = L[u][i];
                if(!des[v])pila[top++] = v;
            }
        }
        else fin[u] = timer++, top--; 
    }   
}   
