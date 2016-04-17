
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005
#define INF (1<<30)

using namespace std;

struct heap{
	
	int size, a[N];
	
	heap(){ size = 0; }
	
	int getL(int pos){ return ((pos<<1) <= size)? a[pos<<1]:-1; }
	int getR(int pos){ return ((pos<<1) + 1 <= size)? a[(pos<<1) + 1]:-1;}
	
	void max_heapify(int pos){
		
		while(pos <= (size>>1) && a[pos] < max(getL(pos), getR(pos))){
			
			if(getL(pos) > getR(pos)){

				swap(a[pos], a[pos<<1]);
				pos <<= 1;
			}
			else swap(a[pos], a[(pos<<1) + 1]), pos = (pos<<1) + 1;
		}
	}
	
	void build(){
		
		a[size + 1] = -INF;
		for(int i = size/2; i >= 1; i--)
			max_heapify(i);
	}
	
	void heapSort(){
		
		int len = size;
		for(int i = size; i >= 2; i--){
			
			swap(a[1], a[i]); size--;
			max_heapify(1);
		}
		size = len;
	}
	
	void increase_key(int pos, int key){
		
		if(key < a[pos])cerr << "new key is smaller than current key" << endl;
		else{
		
			while(pos > 1 && a[pos>>1] < a[pos]){
				
				swap(a[pos>>1], a[pos]);
				pos >>= 1;
			}
		}
	}
	
	int heap_maximun(){ return a[1]; }
	int top(){ 
	
		if(size < 1)cerr << "heap underflow" << endl;
		else{
			
			swap(a[1], a[size]);
			size--;
			max_heapify(1);
			return a[size - 1];
		}
	}
	
	void print_heap(int root){
		
		 int l = root, r = root, len;
		 string space;
		 
		 while(l <= size){
		 	
		 	len = 80/(r - l + 1);
		 	r = min(r, size);
		 	
		 	for(int i = l; i <= r; i++){
			 
			 	space = string(len/2, ' ');
				cout << space << a[i] << space;  
			}
			
			cout << endl;
			l <<= 1;
			r = (r<<1) + 1;	
		 }
	}
	
	void print(){ 
	
		for(int i = 1; i <= size; i++)
			printf("%d ", a[i]);
		 puts(""); 
	}
	
	void read(){ scanf("%d", &a[++size]); }
	
};


int main(){

	int n;
	scanf("%d", &n);
	
	heap Q;
	for(int i = 0; i < n; i++)Q.read();
	
	Q.build();
	Q.print_heap(3);
	
	Q.heapSort();
	Q.print();
	
}

