
#define N 100005

#define make_hash make_pair
#define c1 first
#define c2 second

#define MOD1 1000000007
#define MOD2 1000000009

using namespace std;
//todas las operaciones son <p1, p2]

typedef pair<long long, long long> hash;
hash H[N], PO[N], K = make_hash(31LL, 61LL);

char s[N];
int size;

hash operator *(const hash &h1, const hash &h2){ 
	
	long long aux1 = h1.c1 * h2.c1;
	if(aux1 >= MOD1)aux1 %= MOD1;
	
	long long aux2 = h1.c2 * h2.c2;
	if(aux2 >= MOD2)aux2 %= MOD2;
	
	return make_hash(aux1, aux2);
}

hash operator +(const hash &h1, const hash &h2){ 
	
	long long aux1 = h1.c1 + h2.c1;
	if(aux1 >= MOD1)aux1 -= MOD1;
	
	long long aux2 = h1.c2 + h2.c2;
	if(aux2 >= MOD2)aux2 -= MOD2;
	
	return make_hash(aux1, aux2);
}

hash operator -(const hash &h1, const hash &h2){ 
	
	long long aux1 = h1.c1 - h2.c1;
	if(aux1 < 0)aux1 += MOD1;
	
	long long aux2 = h1.c2 - h2.c2;
	if(aux2 < 0)aux2 += MOD2;
	
	return make_hash(aux1, aux2);
}


hash getHash(int p1, int p2){ return H[p2] - (H[p1] * PO[p2 - p1]); }


void process(){
	
	PO[0] = make_hash(1LL, 1LL);
	for(int i = 1; i < N; i++)
		PO[i] = PO[i - 1] * K;
		
	// la cadena cubre el rango [1, len]
	for(int i = 0, j; i < size; i++){
		
		j = (s[i] - 'a' + 1);
		H[i + 1] = (H[i] * K) + make_hash(j, j);
	}
}

int getLCP(int p1, int p2){ 
	
	int lo = 0, hi = min(size - p1, size - p2);
	while(lo < hi){
		
		int me = lo + (hi - lo + 1)/2;
		if(getHash(p1, p1 + me) == getHash(p2, p2 + me))lo = me;
		else hi = me - 1;	
	}
	
	return lo;
}

//comparador de dos sufijos en el rango <p1, len] y <p2, len]
bool comp(int p1, int p2){
	
	int lcp = getLCP(p1, p2);
	return s[p1 + lcp] < s[p2 + lcp];	
}

int suffix[N], lcp[N];
void doit(){


	scanf("%s", s);
	size = strlen(s);
	
	process();
	
	for(int i = 0; i < size; i++)suffix[i] = i;
	sort(suffix, suffix + size, comp);
		
	//longest common preffix array
	for(int i = 0; i < size - 1; i++)
		lcp[i] = getLCP(suffix[i], suffix[i + 1]);
		
	for(int i = 0; i < size; i++)	
		printf("%d %d\n", suffix[i], lcp[i]);
}

