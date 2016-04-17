
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005
#define K 31

using namespace std;
typedef unsigned long long hash;

//todas las operaciones son <p1, p2]

hash H[N], PO[N];
int suffix[N], lcp[N], len;

char s[N];
hash getHash(int p1, int p2){ return H[p2] - H[p1] * PO[p2 - p1]; }

//Longest common preffix entre dos sufijos en el rango <p1, len] y <p2, len]

int getLCP(int p1, int p2){ 
	
	int lo = 0, hi = min(len - p1, len - p2);
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

void doit(){

	PO[0] = 1;
	for(int i = 1; i < N; i++)
		PO[i] = PO[i - 1] * K;
	
	while(scanf("%s", s) == 1){
		
		len = strlen(s);
		// la cadena cubre el rango [1, len]
		for(int i = 0; i < len; i++)
			H[i + 1] = H[i] * K + (s[i] - 'a' + 1);
		
		for(int i = 0; i < len; i++)suffix[i] = i;
		sort(suffix, suffix + len, comp);
		
		//longest common preffix array
		for(int i = 0; i < len - 1; i++)
			lcp[i] = getLCP(suffix[i], suffix[i + 1]);
		
		for(int i = 0; i < len; i++)	
			printf("%d %d\n", suffix[i], lcp[i]);
	}

}


