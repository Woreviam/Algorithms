

int last[N], next[N];
bool vis[N];

int optimal_catching(vector<int> &task, int cap){
	
	int n = task.size();
	
	fill(last, last + n, n);
	fill(vis, vis + n, false);
	
	for(int i = n - 1; i >= 0; i--){
		
		next[i] = last[task[i]];
		last[task[i]] = i;
	}
	
	int ans = 0, id;
	priority_queue<int>farther;
	
	for(int i = 0; i < n; i++){
		
		if(farther.size() < cap){
		
			if(!vis[task[i]])farther.push(next[i]), vis[task[i]] = true;
		}
		else{
			
			id = farther.top();
			vis[task[id]] = false;
			
			vis[task[i]] = true;
			farther.push(next[i]);
			
			ans++;
		}
	}
	
	return ans;
}

