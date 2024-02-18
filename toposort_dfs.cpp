#include<bits/stdc++.h>
using namespace std;
//toposort DFS
stack<int> st;
void dfs(vector<int> adj[], vector<bool> &visited, int node){
	visited[node] = true;
	for(auto nbr:adj[node]){
		if(!visited[nbr]){
			dfs(adj, visited, nbr);
		}
	}
	st.push(node);
}
int main(){
	int N, E;
	cin >> N >> E;
	vector<int> adj[N];
	for(int i = 0; i < E; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	vector<bool> visited(N, false);
	for(int i = 0; i < N; i++){
		if(!visited[i]){
			dfs(adj, visited, i);
		}
	}
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
}