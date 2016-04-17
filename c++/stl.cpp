
////////////////////////////////////////////////////////////////////////
///////////////////////////////// STL  /////////////////////////////////
////////////////////////////////////////////////////////////////////////

void bit_masking(int mask, int n){
	
	//inverso de mask en n bits
	int inv = ((1<<n) - 1)&(~mask);
	
	//recorrer subconjuntos
	for(int i = mask; i > 0; i = (i - 1)&mask)
		
	
	
}

void prueba_set(){
	
	/* Recorrer un set S --> O(n)*/
	
	set<int>S;
	for(int i = 0; i < 10; i++)S.insert(i);
	
	set<int> :: iterator it;
	for(it = S.begin(); it != S.end(); it++)cout << *it << endl;

	/* Eliminar un elemento --> O(logn)*/
		int x;
		
		// -Mediante puntero 
			S.erase(it);
		// -Mediante valor
			S.erase(5);
	
	/* Lower Bound(x) - primer elemento >= x en el set O(nlogn) */
		it = S.lower_bound(x);
	
	/* Upper Bound(x) - primer elemento > x en el set O(nlogn) */
		it = S.upper_bound(x);
	
	/*Pasar set a vector O(n)*/
		vector<int>V(S.begin(), S.end());
}


void prueba_multi_set(){
	

	multiset<int>S;
	for(int i = 10; i < 10; i++)S.insert(i);

	/* Eliminar un elemento --> O(logn)*/
	
	// -Mediante puntero, si no se quiere borrar todos
	multiset<int> :: iterator it = S.find(10);
	S.erase(it);
			
	// -Mediante valor
	S.erase(10);
}	

void prueba_bitset(){
	
	bitset<23> bits;
	bits[2] = 1;
	bits[5] = 1;
	
	cout << bits << endl; // imprime todo el arreglo
	bits[2].flip(); //cambia valor del bit
	
	bits.reset(); // resetea a cero todo
	bits.set(); // setea todo a cero
	
	cout << bits.count() << endl; // cantidad de prendido
	
	bitset<N>S, R;
	//setear all bits on	//setear one bit on
	S.set();				S.set(5);
	
	//setear all bits on	//setear one bit on
	S.reset();				S.reset(5);
	
	//flips all bits on		//flip one bit on
	S.flip();				S.flip(5);
	
	//count with able operations
	cout << (S|R).count() << endl;
	cout << (S^R).count() << endl;
	cout << (S&R).count() << endl;
	cout << (~S).count() << endl;
	
	cout << S << endl;
}


void precisiones_iomanip(){
	
	/*#include <iomanip> - Presiciones */
	
	double d = 12345.6789;
	cout << d << endl;
	
	// precision entera y decimal --> 1.23e+04
	cout << setprecision(3) << d << endl; 
	
	// precision decimal --> 12345.679
	cout << setprecision(3) << fixed << d << endl;
	
	// precision decimal --> 0.6
	cout << setprecision(1) << fixed << 0.55 << endl;
	
}

void transformaciones_hexadecimales(){
	
	int i = 42;								
	cout << hex << i << endl; //2a
	cout << hex << uppercase << i << endl; //2A
	cout << i << endl; //2A
	cout << dec << i << endl; //42
}


	
inline void read(int &number) {
		
    number = 0;
    int ch = getcx();
        
    while (ch < '0' || ch > '9')ch = getcx();
    while(ch >= '0' && ch <= '9'){
        number = (number << 3) + (number << 1) + ch - '0';
		ch = getcx();
	}
}	
	

int main(){

	ios_base :: sync_with_stdio( 0 ); 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

