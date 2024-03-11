#include<bits/stdc++.h>
using namespace std;
bool dFs(int node, vector<int> &visited, vector<int> &visPath, vector<int> adj[]){
	visited[node] = 1;
	visPath[node] = 1;
	for(auto nbr:adj[node]){
		if(visited[nbr] == 0){
			if(dFs(nbr, visited, visPath, adj)) return true;
		}

		else if(visPath[nbr]) return true;
	}

	visPath[node] = 0;
	return false;

}
int main(){
	int N, V;
	cin >> N >> V;
	vector<int> adj[N + 1];
	for(int i = 0; i < N; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	vector<int> visited(N, 0);
	vector<int> visPath(N, 0);
	bool flag = false;
	for(int i = 0; i < N; i++){
		if(!visited[i]){
			bool res = dFs(i, visited, visPath, adj);
			if(res){
				flag = true;
				cout << "Detected";
				break;
			}
		}
	}
	if(flag == false) cout << "Not Detected";
  }