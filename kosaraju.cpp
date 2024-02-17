// kosaraju algorithm helps to count the strongly connected components
//first we have to make the dfs trivarsal in finish time
//make a vector and store the dfs triversal
// then reverse the edges then start from the 0th element in the vector 
// we can use stack also 
// without dfs if you reverse the edges there is an adjecency connection 
// to avoid that we are using dfs in finishtime
#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
void dFs(int node, vector<int> adj[], vector<bool> &visited){
	
	visited[node] = true;
	for(auto nbr:adj[node]){
		if(!visited[nbr]){
			dFs(nbr, adj, visited);
		}
	}
	arr.push_back(node);
}
void dFsHelper(int node, vector<int> adj[], vector<bool> &visited){
	visited[node] = true;
	for(auto nbr:adj[node]){
		if(!visited[nbr]){
			dFsHelper(nbr, adj, visited);
		}
	}
}
int main(){
	int N, E;
	// N --> Nodes, E --> Edges
	cin >> N >> E;
	vector<int> adj[N];
	vector<int> adj_rev[N];
	for(int i = 0; i < N; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj_rev[v].push_back(u);
	}
	vector<bool> visited1(N + 1, false);
	vector<bool> visited2(N + 1, false);
	dFs(1, adj, visited1);
	int cnt = 0;
	for(auto it:arr){
		if(!visited2[it]){
			dFsHelper(it,adj_rev,visited2);
			cnt++;
		}
	}
	cout << cnt;

}