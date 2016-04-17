
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005

using namespace std;

int size;

struct Matrix{
    
    long long M[21][21];
    
    Matrix(){}
    Matrix(int k){
        
        memset(M, 0, sizeof M);
        for(int i = 0; i < size; i++)M[i][i] = k;
    }
};

Matrix operator * ( const Matrix &a , const Matrix &b ){
    
    Matrix ans;
    memset(ans.M, 0, sizeof ans.M);
    
    long long ac;
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            
            ac = 0;
            for(int k = 0; k < size; k++){
                
                ac += (a.M[i][k] * b.M[k][j])%MOD;
                if(ac >= MOD)ac %= MOD;
            }
            ans.M[i][j] = ac;
        }
    }
    return ans;
}
Matrix pow(Matrix a , long long exp){
    
    Matrix ans(1);
    while(exp){
        
        if(exp & 1) ans = ans * a;
        a = a * a;
        exp >>= 1 ;
    }
    return ans;
}

