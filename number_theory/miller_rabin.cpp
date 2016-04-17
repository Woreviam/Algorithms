
/******************************************************************************/
/*************************************** Miller Rabin *************************/
/******************************************************************************/

long long mul(long long a, long long b, long long c){
	
    long long x = 0, y = a % c;
    while(b > 0){
    	
        if(b % 2 == 1)x = (x + y)%c;
        y = (y * 2) % c;
        b /= 2;
    }
    return x%c;
}

long long modd(long long a,long long b,long long c){
	
    long long x=1,y=a; 
    
    while(b > 0){
    	
        if(b % 2 == 1)x = mul(x,y,c);
        y = mul(y, y, c); 
        b /= 2;
    }
    return x%c;
}

bool Miller(long long p,int iter){
	
    if(p < 2)return false;
    if(p != 2 && p % 2 == 0)return false;
    
    long long s = p - 1;
    while(s % 2 == 0)s/=2;
    
    for(int i = 0;i < iter; i++){
    	
        long long a = rand() % (p - 1) + 1, temp = s;
        long long mod = modd(a, temp, p);
        
        while(temp != p - 1 && mod != 1 && mod != p - 1){
            mod = mul(mod, mod, p);
            temp *= 2;
        }
        
        if(mod != p - 1 && temp % 2 == 0)return false;
    }
    return true;
}


