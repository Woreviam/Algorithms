
#define N 100005
#define cout2(x, y) cout << x << " " << y << endl
#define INF (1<<30)

using namespace std;

typedef pair<int, int> interval;

bool comp_right(const interval &p1, const interval &p2){ return p2.second < p1.second; }
bool comp_left(const interval &p1, const interval &p2){ return p2.first < p1.first; }

void interval_partitioning(vector<interval > &I){
	
	vector<interval>ans[10000];
	sort(I.begin(), I.end(), comp_left);
	
	//par(r, id) ->el rightmost segment que pertenece al conjunto id
	multiset<pair<int, int> >S; 
	multiset<pair<int, int> >::iterator it;
	
	int len = 0, id;

	for(int i = 0; i < I.size(); i++){
		
		it = S.begin();
		if(i == 0 || (*it).first > I[i].first){
			
			S.insert(make_pair(I[i].second, id));
			ans[len++].push_back(I[i]);
			
		}
		else{
			
			id = (*it).second;
			S.erase(it);
			
			S.insert(make_pair(I[i].second, id));
			ans[id].push_back(I[i]);
			
		}
	}
	
	cout << "Maxima cantidad de conjuntos: " << len << endl;
	for(int i = 0; i < len; i++){
		
		cout << "Conjunto : " << i << endl;
		for(int j = 0; j < ans[i].size(); j++)cout << ans[i][j].first << " " << ans[i][j].second;
	}	
}



