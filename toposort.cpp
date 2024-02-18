#include<bits/stdc++.h>
using namespace std;
//toposort using bfs
//time complexity O(N + E);
//space complexity O(N) + O(N)//indegree // queue
void toposort(vector<int> adj[], vector<int> &indegree){
	queue<int> Q;
	//putting the nodes which having indegree = 0;
	for(int i = 0; i < indegree.size(); i++){
		if(indegree[i] == 0){
			Q.push(i);
		}
	}
	while(!Q.empty()){
		int top = Q.front();
		cout << top << " ";
		Q.pop();
		for(auto nbr:adj[top]){
			if(indegree[nbr] != 0){
				indegree[nbr]--;
				if(indegree[nbr] == 0){
					Q.push(nbr);
				}
			}
		}
	}
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
	//indegree vector
	vector<int> indegree(N, 0);
	for(int i =0 ; i < N; i++){
		for(auto it:adj[i]){
			indegree[it]++;
		}
	}

	toposort(adj, indegree);

}