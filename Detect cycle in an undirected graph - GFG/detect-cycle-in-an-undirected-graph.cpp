//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool> visited;
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                queue<int> q;
                unordered_map<int, int> parent;
                q.push(i);
                visited[i] = 1;
                parent[i] = -1;
                
                while(!q.empty()){
                    
                    int first = q.front();
                    q.pop();
                    for(auto neighbour : adj[first]){
                        if(visited[neighbour] && neighbour != parent[first]){
                            return 1;
                        }
                        if(!visited[neighbour]){
                            q.push(neighbour);
                            visited[neighbour] = 1;
                            parent[neighbour] = first;
                        }
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends