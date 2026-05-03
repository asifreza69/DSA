#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    // DFS traversal
    void dfs(int node, unordered_map<int, vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;

        for (auto nei : adj[node]) {
            if (!visited[nei]) {
                dfs(nei, adj, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {

        // Step 1: Build adjacency list
        unordered_map<int, vector<int>> adj;
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Track visited nodes
        vector<int> visited(n, 0);
        int count = 0;

        // Step 3: Traverse all nodes
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);  // explore full component
                count++;               // new component found
            }
        }

        return count;
    }
};

/*
==========================
🔥 APPROACH EXPLAINED
==========================

Goal:
Count number of connected components in an undirected graph

--------------------------------

🧠 Idea:

- Each DFS call explores ONE complete component
- Count how many times DFS is started

--------------------------------

Steps:

1. Convert edges → adjacency list
2. Maintain visited array
3. Loop through all nodes:
   - If not visited:
        → run DFS
        → increment count

--------------------------------

Example:

n = 5
edges = [[0,1],[1,2],[3,4]]

Graph:
0 - 1 - 2     3 - 4

Components:
[0,1,2], [3,4] → Answer = 2

--------------------------------

Time Complexity: O(V + E)
Space Complexity: O(V + E)

--------------------------------

🧠 Interview One-Liner:

"Run DFS from every unvisited node and count how many times DFS is called"

*/
