#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
//bfs
bool isThere(vector<int> adj[], int node, vector<bool> &visited){
    queue<pair<int, int>> Q;
    
    Q.push(mp(node, -1));
    visited[node] = 1;
    while(!Q.empty()){
        pair<int, int> top = Q.front();
        Q.pop();
        node = top.first;
        int parent = top.second;
        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                visited[nbr] = true;
                Q.push(mp(nbr, node));
            }
            else{
                if(nbr != parent) return true;
            }
        }
    }

    return false;
}
int main(){
	int n, e;
	cin >> n >> e;
	vector<int> adj[n + 1];
	for(int i = 0;  i <= n; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// cout << isThere(adj,,visited);
	bool flag = false;
	vector<bool> visited(n + 1, false);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            if(isThere(adj, i, visited)){
                 flag = true;
                 break;
            }
        }
    }
    
}