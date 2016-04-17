
#define N 100005
#define cout2(x, y) cout << x << " " << y << endl
#define INF (1<<30)

using namespace std;

typedef pair<int, int> interval;

bool comp_right(const interval &p1, const interval &p2){ return p2.second < p1.second; }
bool comp_left(const interval &p1, const interval &p2){ return p2.first < p1.first; }

////////////////////////GREEDY////////////////////////

void interval_schedulling(vector<interval > &I){
	
	vector<interval >ans;
	sort(I.begin(), I.end(), comp_right);
	
	int cur = -INF;
	for(int i = 0; i < I.size(); i++){
		
		if(cur < I[i].first){
			
			ans.push_back(I[i]);
			cur = I[i].second;	
		}
	}
	
	cout << "Maxima cantidad de intervalos disjuntos: " << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++)cout << I[i].first << " " << I[i].second;
}


