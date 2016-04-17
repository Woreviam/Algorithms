////////////////////////////////////////////////////////////////////////////////
//////////////////////////// DINAMIC PROGRAMMING   /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void recorrer_subsets(int mask){
		
	for(int i = mask; i > 0; i = (i - 1)&mask){/*....*/}
}

//conteo del digito d en el numero num
int frec_dig(long long num, int d){
	
	int ans = 0;
	for(int i = num; i > 0; i /= 10)if(i%10 == d)ans++;
	return ans;	
}

// cantidad de veces usada del digito d en el rango [1, num]
int solve(long long num, int d){
	
	if(num <= 0)return 0;
	return (num/10) + (num%10 >= d) + frec_dig(num/10, d) * (num%10 + 1) + solve(num/10 - 1, d) * 10 - (d == 0);
}

