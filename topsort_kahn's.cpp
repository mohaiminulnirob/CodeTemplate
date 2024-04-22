
#include <bits/stdc++.h>
using namespace std;
map<int,vector<int> > adj;

vector<int> topologicalSort(int V)
{
	vector<int> indegree;
    vector<int> result;
	queue<int> q;
	for (int i = 0; i < V; i++) {
		for (auto it : adj[i]) {
			indegree[it]++;
		}
	}

	for (int i = 0; i < V; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		result.push_back(node);
	
		for (auto it : adj[node]) {
			indegree[it]--;
		
			if (indegree[it] == 0)
				q.push(it);
		}
	}

	if (result.size() != V) {
		cout << "Graph contains cycle!" << endl;
		return {};
	}

	return result;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    
	adj.clear();
	int V,E;
	cin>>V>>E;
	topologicalSort(V);
	return 0;
}
