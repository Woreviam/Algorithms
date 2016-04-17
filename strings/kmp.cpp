
int borde[N];
char patt[N], text[N];

void process_borde(){
	
	int n = strlen(patt);
	borde[0] = -1;
	
	for(int i = 1, j = -1; i <= n; i++){
		
		while(j != -1 && patt[j] != patt[i - 1])j = borde[j];
		borde[i] = ++j;
	}
}

vector<int>match_kmp;

void kmp_search(){
	
	int n = strlen(text);
	int m = strlen(patt);
	
	for(int i = 1, j = 0; i <= n; i++){
		
		while(j != -1 && text[j] != text[i - 1])j = borde[j];
		++j;
		
		if(j == m)match_kmp.pb(i - m), j = borde[j];
	}
}

