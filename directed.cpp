#include<bits/stdc++.h>
using namespace std;
void DFS(vector<int> adj[], vector<bool> &visited, int node){
	cout << node << " ";
	visited[node] = true;
	for(auto nbr:adj[node]){
		if(!visited[nbr]) DFS(adj, visited, nbr);
		
	}
}
int main(){
	int N, E;
	cin >> N >> E;
	vector<int> adj[N + 1];
	for(int i = 0; i < E; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		
	}
	vector<bool> visited(N + 1, false);
	
	for(int i = 0; i < N; i++){
		if(!visited[i]){
			DFS(adj, visited, i); 
		}
	}
	
}