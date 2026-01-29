class Solution {
public:

    // DFS function to check if there is already a path
    // between node 'i' and node 'j' in the current graph.
    bool dfs(int i, int j, unordered_map<int, vector<int>>& mp, vector<bool>& visited) {
        // If source and destination are same, path exists
        if (i == j) {
            return true;
        }

        visited[i] = true;

        // Traverse all neighbors of current node
        for (auto& t : mp[i]) {
            if (!visited[t]) {
                if (dfs(t, j, mp, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    // Finds the redundant edge that creates a cycle in the graph
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;

        // Process edges one by one
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];

            // Visited array for DFS traversal
            vector<bool> visited(edges.size() + 1, false);

            // If both nodes already exist and path already exists between them,
            // then this edge is redundant (creates a cycle)
            if (mp.find(u) != mp.end() && mp.find(v) != mp.end() && dfs(u, v, mp, visited)) {
                return {u, v};
            }
            else {
                // Otherwise, add the edge to the graph
                mp[u].push_back(v);
                mp[v].push_back(u);
            }
        }

        // If no redundant edge is found
        return {-1, -1};
    }
};
