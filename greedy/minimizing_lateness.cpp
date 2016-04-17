

#define N 100005
#define cout2(x, y) cout << x << " " << y << endl
#define INF (1<<30)

#define deadline first
#define timer second

using namespace std;
typedef pair<int, int> interval;

bool comp_right(const interval &p1, const interval &p2){ return p2.second < p1.second; }
bool comp_left(const interval &p1, const interval &p2){ return p2.first < p1.first; }


int minimizing_lateness(vector<interval > &I){
	
	sort(I.begin(), I.end());
	int total = 0, ans = 0;
	
	for(int i = 0; i < I.size(); i++){
		
		total += I[i].timer;
		if(ans < total - I[i].deadline)ans = total - I[i].deadline;
	}
	
	return ans;
}


