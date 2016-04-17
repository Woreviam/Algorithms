
#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define cout2(x, y) cout << x << " " << y <<  endl
#define EPS 1e-6
#define N 10

using namespace std;

void z_funtion(char *s, int *z){ 
	
	int n = strlen(s);
	for(int i = 1, l = 0, r = 0; i < n; i++){
		
		if(i <= r)z[i] = min(z[i - l], r - i + 1);
		while(i + z[i] < n && s[i + z[i]] == s[z[i]])z[i]++;
		if(i + z[i] - 1 > r)r = i + z[i] - 1, l = i;
	}
}


