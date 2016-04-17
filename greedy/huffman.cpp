

int huffman_code(vector<char> text){
	
	sort(text.begin(), text.end());
	vector<int>frec;
	
	int len = 0;
	if(text.size() > 0)frec.pb(1), len++;
	
	for(int i = 1; i < text.size(); i++){
		
		if(text[i] == text[i - 1])frec[len - 1]++;
		else frec.pb(1), len++;
	}
	
	multiset<int>S;
	for(int i = 0; i < len; i++)S.insert(frec[i]);
	
	int ans = 0, best1, best2;

	while(S.size() > 1){
		
		best1 = *S.begin();
		S.erase(*S.begin());
		
		best2 = *S.begin();
		S.erase(*S.begin());
		
		S.insert(best1 + best2);
		ans += best1 + best2;
	}
	
	return ans;
}

